/** @file OSSolverService.cpp
 * 
 * @author  Robert Fourer,  Jun Ma, Kipp Martin, 
 * @version 1.0, 10/05/2005  
 * @since   OS1.0
 * 
 * \remarks
 * Copyright (C) 2005, Robert Fourer, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 *  
 * <b>INPUTS:</b>
 * <ul>
 * <li>
 * <b>-osil</b> xxx.osil (file name on local machine of optimization instance, 
 *       this is NULL by default, however if this remains NULL a problem
 * 		 instance must be specified in the osol file)
 * </li>  
 * <li>
 * <b>-osol</b> xxx.osol (file name on local machine of solver options, 
 *       default default value is NULL)
 * </li>
 * <li>
 * <b>-osrl</b> xxx.osrl (file name on local machine where the optimization 
 *       result is put, default is NULL)
 * </li> 
 * <li>
 * <b>-serviceLocation</b> location URL (the URL  of the server that is called 
 *       remotely if the problem not solved locally, default is NULL)
 * </li>
 * <li>
 * <b>-serviceMethod</b>  (send, solve, kill, knock, getJobID, retrieve, 
 *       default value is solve)
 * </li>
 * <li>
 * <b>-os</b> (Not used for now -- ignore)
 * </li>
 * <li>
 * <b>-osplInput</b> xxx.ospl name of file with input in OS Process Language
 * </li> 
 * <li>
 * <b>-osplOutput</b> xxx.ospl name of output file in OS Process Language
 * </li>
 * <li> 
 * <b>-mps</b> xxxx.mps (converts mps format to osil and has same effect as -osil)
 * </li>
 * <li>
 * <b>-nl</b> xxxx.nl (converts nl format to osil and has same effect as -osil)
 * </li>
 * <li>
 * <b>-solver</b> solverName (the name of the solver to be invoked)
 * </li>
 * <li>
 * <b>-browser</b> path location to browser e.g. 
 *       /Applications/Firefox.app/Contents/MacOS/firefox (default is NULL)
 * </li>
 * <li>
 * <b>-config</b> pathToConfigFile is the path to a configure file with the problem 
 * 	     parameters
 * </li>
 * <li>
 * <b>-insList</b> xxx.dat (used only for LINDO, file location on local 
 *       machine of LINDO instruction list)
 * </li>
 * </ul>
*/

#include "OSCoinSolver.h"
#include "OSResult.h" 
#include "OSiLReader.h"        
#include "OSiLWriter.h" 
#include "OSoLReader.h"
#include "OSrLReader.h"        
#include "OSrLWriter.h"      
#include "OSInstance.h"  
#include "OSOption.h"
#include "OSFileUtil.h"  
#include "OSConfig.h"  
#include "OSDefaultSolver.h"  
#include "OSWSUtil.h" 
#include "OSSolverAgent.h"   
#include "OShL.h"     
#include "OSErrorClass.h"
#include "OSmps2osil.h"   
#include "OSBase64.h"
#include "OSCommonUtil.h"






#ifdef COIN_HAS_KNITRO    
#include "OSKnitroSolver.h"
#endif 





#ifdef COIN_HAS_LINDO    
#include "OSLindoSolver.h"
#endif 

/*
#ifdef COIN_HAS_IPOPT  
	#ifndef COIN_HAS_ASL
		#include "OSIpoptSolver.h"
		#undef COIN_HAS_ASL
	#else
		#include "OSIpoptSolver.h"
#endif
#endif 
*/

#ifdef COIN_HAS_ASL
#include "OSnl2osil.h"
#endif



//#ifdef COIN_HAS_IPOPT  
//#include "OSIpoptSolver.h"
//#endif

#ifdef COIN_HAS_IPOPT  
	#ifndef COIN_HAS_ASL
		#include "OSIpoptSolver.h"
		#undef COIN_HAS_ASL
	#else
		#include "OSIpoptSolver.h"
	#endif
#endif



#ifdef COIN_HAS_BONMIN   
#include "OSBonminSolver.h"
#endif 

#ifdef COIN_HAS_COUENNE
#include "OSCouenneSolver.h"
#endif 


#include "OSOptionsStruc.h"  


using std::cout;
using std::endl;
using std::ostringstream;
using std::string;

    

#define MAXCHARS 5000 

typedef struct yy_buffer_state *YY_BUFFER_STATE;
YY_BUFFER_STATE osss_scan_string(const char* osss, void* scanner ); 
//void osssset_extra (YY_EXTRA_TYPE user_defined ,yyscan_t yyscanner );
void setyyextra(osOptionsStruc *osoptions, void* scanner);
int ossslex(void* scanner );
int ossslex_init(void** ptr);
int ossslex_destroy (void* scanner );

std::string get_help();
std::string get_version();

std::string get_help();
std::string get_version();

 
// the serviceMethods  
void solve();  
void getJobID(); 
void send();
void kill();
void retrieve(); 
void knock();

// additional methods
void getOSiLFromNl(); 
void getOSiLFromMps();
string getServiceURI( std::string osol);
string getInstanceLocation( std::string osol);
string getSolverName( std::string osol);

//options structure
// this is the only global variable but 
// this is not a problem since this is a main routine
osOptionsStruc *osoptions; 


int main(int argC, const char* argV[])
{  	
	WindowsErrorPopupBlocker();
	void* scanner;
	FileUtil *fileUtil = NULL;
	FileUtil *inputFileUtil = NULL; 
	char osss[MAXCHARS] = " ";
	const char *space = " "; 
	//char *config = "-config";
	std::string configFileName = "";
	int i;

	// initialize the OS options structure

	osoptions = new osOptionsStruc();
	osoptions->configFile = ""; 
	osoptions->osilFile = ""; 
	osoptions->osil = ""; 
	osoptions->osolFile = ""; 
	osoptions->osol = "";  
	osoptions->osrlFile = ""; 
	osoptions->osrl = ""; 
	osoptions->insListFile = ""; 
	osoptions->insList = ""; 
	osoptions->serviceLocation = ""; 
	osoptions->serviceMethod = ""; 
	osoptions->osplInputFile = ""; 
	osoptions->osplOutputFile = ""; 
	osoptions->mpsFile = ""; 
	osoptions->nlFile = ""; 
	osoptions->solverName = ""; 
	osoptions->browser = ""; 
	osoptions->invokeHelp = false;
	osoptions->writeVersion = false;
	try{
		if(argC < 2){
			std::cout << "There must be at least one command line argument" << std::endl;
			std::cout << "Try -help or --help" << std::endl;
			delete osoptions;
			return 1;
		}
		// see if the first argument is a file name
		i = 1;
		while(i < argC) {
			if(strlen(osss) + strlen(argV[ i]) + 1 > MAXCHARS) throw ErrorClass( "the command line has too many arguments");
			strcat(osss, argV[ i]);
			strcat(osss, space);
			i++;
		}
		cout << "Input String = "  << osss << endl;
		ossslex_init( &scanner);
		//std::cout << "Call Text Extra" << std::endl;
		setyyextra( osoptions, scanner);
		//std::cout << "Call scan string " << std::endl;
		osss_scan_string( osss, scanner); 
		std::cout << "call ossslex" << std::endl;
		ossslex( scanner);
		ossslex_destroy( scanner);
		std::cout << "done with call to ossslex" << std::endl;
		// if there is a config file, get those options
		if(osoptions->configFile != ""){
			ossslex_init( &scanner);
			configFileName = osoptions->configFile;
			cout << "configFileName = " << configFileName << endl;
			std::string osolfileOptions = fileUtil->getFileAsString( configFileName.c_str() );
			std::cout << "Call Text Extra" << std::endl;
			setyyextra( osoptions, scanner);
			std::cout << "Done with call Text Extra" << std::endl;
			osss_scan_string( osolfileOptions.c_str() , scanner);
			ossslex(scanner );	
			ossslex_destroy( scanner);
		}
	}
		catch(const ErrorClass& eclass){
		cout << eclass.errormsg <<  endl;
		cout << "try -help or --help" <<  endl;
		ossslex_destroy( scanner);
		delete fileUtil;
		delete osoptions;
		return 1;
	} 
		try{
			if(osoptions->invokeHelp == true){ 
				std::string helpTxt = get_help();
				std::cout << std::endl << std::endl;
				std::cout << helpTxt << std::endl;
				delete	osoptions;
				osoptions = NULL;	
				return 0;
			}
			if(osoptions->writeVersion == true){ 
				std::string writeTxt = get_version();
				std::cout << std::endl << std::endl;
				std::cout << writeTxt << std::endl;
				delete	osoptions;
				osoptions = NULL;	
				return 0;
			}
		}
		catch(const ErrorClass& eclass){
			cout << eclass.errormsg <<  endl;
			cout << "try -help or --help" <<  endl;
			delete	osoptions;
			osoptions = NULL;	
			delete inputFileUtil;
			inputFileUtil  = NULL;
			return 1;
		} 
		cout << "HERE ARE THE OPTION VALUES:" << endl;
		if(osoptions->configFile != "") cout << "Config file = " << osoptions->configFile << endl;
		if(osoptions->osilFile != "") cout << "OSiL file = " << osoptions->osilFile << endl;
		if(osoptions->osolFile != "") cout << "OSoL file = " << osoptions->osolFile << endl;
		if(osoptions->osrlFile != "") cout << "OSrL file = " << osoptions->osrlFile << endl;
		if(osoptions->insListFile != "") cout << "Instruction List file = " << osoptions->insListFile << endl;
		if(osoptions->osplInputFile != "") cout << "OSpL Input file = " << osoptions->osplInputFile << endl;
		if(osoptions->serviceMethod != "") cout << "Service Method = " << osoptions->serviceMethod << endl;
		if(osoptions->mpsFile != "") cout << "MPS File Name = " << osoptions->mpsFile << endl;
		if(osoptions->nlFile != "") cout << "NL File Name = " << osoptions->nlFile << endl;
		if(osoptions->browser != "") cout << "Browser Value = " << osoptions->browser << endl;
		// get the data from the files
		fileUtil = new FileUtil();
		try{	
			if(osoptions->insListFile != "") osoptions->insList = fileUtil->getFileAsChar( (osoptions->insListFile).c_str() );
			if(osoptions->osolFile != ""){
				osoptions->osol = fileUtil->getFileAsString( (osoptions->osolFile).c_str() );
			}
			if(osoptions->serviceLocation != ""){
				 cout << "Service Location = " << osoptions->serviceLocation << endl;
			}
			else{
				//if( getServiceURI( osoptions->osol) != ""){
				//	osoptions->serviceLocation = &getServiceURI( osoptions->osol)[0];
				//	cout << "Service Location = " << osoptions->serviceLocation << endl;
				//}
			}
			if(osoptions->osilFile != ""){
				//this takes precedence over what is in the OSoL file
				 osoptions->osil = fileUtil->getFileAsString( (osoptions->osilFile).c_str()   );
			}
			else{//get <instanceLocation if we are doing a local solve
				// make sure we don't have a service URI in the file
					if( (osoptions->osol != "") &&  (osoptions->serviceLocation == "")  &&  (getServiceURI( osoptions->osol) == "") ) 
						osoptions->osil = fileUtil->getFileAsString( getInstanceLocation( osoptions->osol).c_str()  );
			}
			// see if there is a solver specified
			if(osoptions->solverName != ""){ 
				cout << "Solver Name = " << osoptions->solverName << endl;
			}
			else{
				if(osoptions->osol != ""){
				osoptions->solverName  =    getSolverName( osoptions->osolFile.c_str()  );
				}
			}
			//if(osoptions->osplInputFile != "") osoptions->osplInput = fileUtil->getFileAsChar( (osoptions->osplInputFile).c_str()  );
			if(osoptions->osplInputFile != "") osoptions->osplInput = fileUtil->getFileAsString( (osoptions->osplInputFile).c_str() );
			//if(osoptions->osplOutputFile != "") osoptions->osplOutput = fileUtil->getFileAsChar( (osoptions->osplOutputFile).c_str() );
			if(osoptions->osplOutputFile != "") osoptions->osplOutput = fileUtil->getFileAsString( (osoptions->osplOutputFile).c_str() );
		}
		catch(const ErrorClass& eclass){
			//cout << eclass.errormsg <<  endl;
			cout << "could not open file properly" << endl;
			cout << "try -help or --help" <<  endl;
			delete	osoptions;
			osoptions = NULL;	
			delete fileUtil;
			fileUtil = NULL;
			return 1;
		}	
		// now call the correct serviceMethod
		// solve is the default
		if( osoptions->serviceMethod == "") solve();
		else{
			switch(osoptions->serviceMethod[ 0]){
				case 'g': 
					getJobID();
					break;
				case 'r':
					retrieve();
					break;
				case 's':
					if( osoptions->serviceMethod[ 1] == 'e') send();
					else solve();
					break;
				case 'k':
					if(osoptions->serviceMethod[ 1] == 'i') kill();
					else knock();
					break;
				default:
					break;
			}
		}
	delete	osoptions;
	osoptions = NULL;	
	delete fileUtil;
	fileUtil = NULL;
	return 0;
}

void solve(){
	std::string osrl = "";
	OSiLReader *osilreader = NULL; 
	OSoLReader *osolreader = NULL;
	OSSolverAgent* osagent = NULL;
	DefaultSolver *solverType  = NULL;
	FileUtil *fileUtil = NULL;
	fileUtil = new FileUtil();
	try{
		// now solve either remotely or locally
		if( osoptions->serviceLocation != "" ){
			// call a method here to get OSiL if we have an nl or mps file
			if(osoptions->osil == ""){
				//we better have an nl file present or mps file or osol file
				if(osoptions->nlFile != ""){
					getOSiLFromNl();
				}
				else{
					if(osoptions->mpsFile != ""){
						getOSiLFromMps();
					}
					else{// need an osol file with an instanceLocation specified
						if( osoptions->osol.find( "<instanceLocation") == std::string::npos){
							throw ErrorClass("solve called and no osil, osol with osil specified, nl, or mps file given");
						}
					}
				}
			}
			// place a remote call
			osagent = new OSSolverAgent( osoptions->serviceLocation );
			if(osoptions->solverName != ""){
				string::size_type iStringpos;
				//see if there is an osol file
				if(osoptions->osol != ""){// we have an osol string
					// see if a solver is listed, if so don't do anything
					iStringpos = osoptions->osol.find("os_solver");
					if(iStringpos == std::string::npos) { //don't have a solver specify, we must do so
						iStringpos = osoptions->osol.find("</osol");
							osoptions->osol.insert(iStringpos, "<other name=\"os_solver\">"
							+ osoptions->solverName  + "</other>");
					}
				}
				else{// no osol string
					osoptions->osol = "<?xml version=\"1.0\" encoding=\"UTF-8\"?> <osol xmlns=\"os.optimizationservices.org\" xmlns:xs=\"http://www.w3.org/2001/XMLSchema\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xsi:schemaLocation=\"os.optimizationservices.org http://www.optimizationservices.org/schemas/OSoL.xsd\"><other> </other></osol>";	
					iStringpos = osoptions->osol.find("</osol");
					osoptions->osol.insert(iStringpos, "<other name=\"os_solver\">"
							+ osoptions->solverName  + "</other>");
				}
			}
			std::cout  << std::endl;
			if(osoptions->osol.length() > 0){
				std::cout << "HERE IS THE OSoL FILE" << std::endl;
				std::cout << osoptions->osol << std::endl << std::endl;
			}
			osrl = osagent->solve(osoptions->osil  , osoptions->osol);
			if(osoptions->osrlFile != ""){
				fileUtil->writeFileFromString(osoptions->osrlFile, osrl);
				//const char *ch1 = "/Applications/Firefox.app/Contents/MacOS/firefox  ";
				if(osoptions->browser != ""){
					std::string str = osoptions->browser + "  " +  osoptions->osrlFile;
					const char *ch = &str[ 0];
					std::system( ch );
				}
			}
			else cout << osrl << endl;
			delete osagent;
			osagent = NULL;
		}
		else{
			// solve locally
			if(osoptions->solverName == "" ){
				string sSolverName = "cbc";
				osoptions->solverName = sSolverName;
			}
			if( osoptions->solverName.find( "ipopt") != std::string::npos) {
				// we are requesting the Ipopt solver
				bool bIpoptIsPresent = false;
				#ifdef COIN_HAS_IPOPT
				bIpoptIsPresent = true;
				solverType = new IpoptSolver();	
				#endif
				if(bIpoptIsPresent == false) throw ErrorClass( "the Ipopt solver requested is not present");
			}
			else{
				if( osoptions->solverName.find( "lindo") != std::string::npos) {
					// we are requesting the Lindo solver
					bool bLindoIsPresent = false;
					#ifdef COIN_HAS_LINDO
					bLindoIsPresent = true;
					std::cout << "calling the LINDO Solver " << std::endl;
					solverType = new LindoSolver();
					std::cout << "DONE calling the LINDO Solver " << std::endl;
					#endif
					if(bLindoIsPresent == false) throw ErrorClass( "the Lindo solver requested is not present");
				}
				else{ 
					if( osoptions->solverName.find( "clp") != std::string::npos){
						solverType = new CoinSolver();
						solverType->sSolverName = "clp";
					}
					else{
						if( osoptions->solverName.find( "cplex") != std::string::npos){
							solverType = new CoinSolver();
							solverType->sSolverName = "cplex";
						}
						else{
							if( osoptions->solverName.find( "glpk") != std::string::npos){
								solverType = new CoinSolver();
								solverType->sSolverName = "glpk";
							}
							else{
								if( osoptions->solverName.find( "dylp") != std::string::npos){
									bool bDYlPIsPresent  = false;
									#ifdef COIN_HAS_DYLP
									solverType = new CoinSolver();
									solverType->sSolverName = "dylp";
									bDYlPIsPresent = true;
									#endif
									if(bDYlPIsPresent == false) throw ErrorClass( "the DyLP solver requested is not present");
								}
								else{
									if( osoptions->solverName.find( "symphony") != std::string::npos){
										solverType = new CoinSolver();
										solverType->sSolverName = "symphony";
									}
									else{
										if( osoptions->solverName.find( "knitro") != std::string::npos){
											bool bKnitroIsPresent = false;
											#ifdef COIN_HAS_KNITRO
											bKnitroIsPresent = true;
											std::cout << "calling the KNITRO Solver " << std::endl;
											solverType = new KnitroSolver();
											std::cout << "DONE calling the KNITRO Solver " << std::endl;
											#endif
											if(bKnitroIsPresent == false) throw ErrorClass( "the Knitro solver requested is not present");		
										}
										else{ 
											if( osoptions->solverName.find( "vol") != std::string::npos){
												solverType = new CoinSolver();
												solverType->sSolverName = "vol";
											}
											else{
												if(osoptions->solverName.find( "bonmin") != std::string::npos){
													// we are requesting the Bonmin solver
													bool bBonminIsPresent = false;
													#ifdef COIN_HAS_BONMIN
													bBonminIsPresent = true;
													solverType = new BonminSolver();	
													#endif												
												}
												else{
													if(osoptions->solverName.find( "couenne") != std::string::npos){
														// we are requesting the Couenne solver
														bool bCouenneIsPresent = false;
														#ifdef COIN_HAS_COUENNE
														bCouenneIsPresent = true;
														solverType = new CouenneSolver();	
														#endif												
													}
													else{ //cbc is the default
														solverType = new CoinSolver();
														solverType->sSolverName = "cbc";
													}
												}
											}
										}									
									}
								}
							}
						}
					}
				}
			}
			std::cout << "CALL SOLVE" << std::endl;
			solverType->osol = osoptions->osol;
			if(osoptions->osil != ""){
				osilreader = new OSiLReader();
				std::cout << "CREATING AN OSINSTANCE FROM AN OSIL FILE" << std::endl;
				solverType->osinstance = osilreader->readOSiL( osoptions->osil );
				// set solver options if there is an OSoL file  kippster
				if(osoptions->osol != ""){
					osolreader = new OSoLReader();
					solverType->osoption = osolreader->readOSoL( osoptions->osol);
					solverType->buildSolverInstance();
					solverType->setSolverOptions();
					solverType->solve();
					osrl = solverType->osrl;
				}
				else{
					solverType->buildSolverInstance();
					solverType->setSolverOptions();
					solverType->solve();
					osrl = solverType->osrl;
				}
			}
			else{
				//we better have an nl file present or mps file or osol file
				if(osoptions->nlFile != ""){
					#ifdef COIN_HAS_ASL
						std::cout << "CREATING AN OSINSTANCE FROM AN NL FILE" << std::endl;
						OSnl2osil *nl2osil = new OSnl2osil( osoptions->nlFile); 
						nl2osil->createOSInstance() ;
						solverType->osinstance = nl2osil->osinstance;
						solverType->buildSolverInstance();
						solverType->solve();
						osrl = solverType->osrl;
						delete nl2osil;
					#else
						throw ErrorClass("nlFile specified locally but ASL not present");
					#endif
				}
				else{
					if(osoptions->mpsFile != ""){
						std::cout << "CREATING AN OSINSTANCE FROM AN MPS FILE" << std::endl;
						OSmps2osil *mps2osil = new OSmps2osil( osoptions->mpsFile);
						mps2osil->createOSInstance() ;
						solverType->osinstance = mps2osil->osinstance;
						solverType->buildSolverInstance();
						solverType->solve();
						osrl = solverType->osrl;
						
						delete mps2osil;
					}
					else{// need an osol file with an instanceLocation specified
						if( osoptions->osol.find( "<instanceLocation") == std::string::npos){
							throw ErrorClass("solve called and no osil, osol with osil specified, nl, or mps file given");
						}
					}
				}
			}
			//delete fileUtil;
			if(osoptions->osrlFile != ""){
				fileUtil->writeFileFromString(osoptions->osrlFile, osrl);
				//const char *ch1 = "/Applications/Firefox.app/Contents/MacOS/firefox  ";
				if(osoptions->browser != ""){
					std::string str = osoptions->browser + "  " +  osoptions->osrlFile;
					const char *ch = &str[ 0];
					std::system( ch );
				}
			}
			else cout << osrl << endl;
		}
	}//end try
	catch(const ErrorClass& eclass){
		if(osoptions->osrlFile != ""){
			fileUtil->writeFileFromString(osoptions->osrlFile, eclass.errormsg);
			if(osoptions->browser != ""){
				std::string str = osoptions->browser + "  " +  osoptions->osrlFile;
				const char *ch = &str[ 0];
				std::system( ch );
			}
		}
		else{
			OSResult *osresult = NULL;
			OSrLWriter *osrlwriter = NULL;
			osrlwriter = new OSrLWriter();
			osresult = new OSResult();
			osresult->setGeneralMessage( eclass.errormsg);
			osresult->setGeneralStatusType( "error");
			std::string osrl = osrlwriter->writeOSrL( osresult);
			std::cout << osrl << std::endl;
			delete osresult;
			delete osrlwriter;
		}
	}	
	if(osilreader != NULL) delete osilreader;
	if(osolreader != NULL) delete osolreader;
	if(solverType != NULL) delete solverType;
	delete fileUtil;
	fileUtil = NULL;
}//end solve

void getJobID(){
	std::string jobID = "";
	OSSolverAgent* osagent = NULL;
	try{
		if(osoptions->serviceLocation != ""){
			osagent = new OSSolverAgent( osoptions->serviceLocation );
			jobID = osagent->getJobID( osoptions->osol);
			cout << jobID << endl;
			delete osagent;
			osagent = NULL;
		}
		else{
			delete osagent;
			osagent = NULL;
			throw ErrorClass("please specify service location (url)");
		}
	}
	catch(const ErrorClass& eclass){
		FileUtil *fileUtil = NULL;
		fileUtil = new FileUtil();
		OSResult *osresult = NULL;
		OSrLWriter *osrlwriter = NULL;
		osrlwriter = new OSrLWriter();
		osresult = new OSResult();
		osresult->setGeneralMessage( eclass.errormsg);
		osresult->setGeneralStatusType( "error");
		std::string osrl = osrlwriter->writeOSrL( osresult);
		if(osoptions->osrlFile != "") fileUtil->writeFileFromString(osoptions->osrlFile, osrl);
		else cout << osrl << endl;
		delete osresult;
		osresult = NULL;
		delete osrlwriter;
		osrlwriter = NULL;
		delete fileUtil;
		fileUtil = NULL;
	}	
}//end getJobID
 

void knock(){
	std::string osplOutput = "";
	OSSolverAgent* osagent = NULL;
	FileUtil *fileUtil = NULL;
	fileUtil = new FileUtil();
	try{
		if(osoptions->serviceLocation != ""){
			osagent = new OSSolverAgent( osoptions->serviceLocation );
			osplOutput = osagent->knock(osoptions->osplInput,  osoptions->osol);
			if(osoptions->osplOutputFile != "") fileUtil->writeFileFromString(osoptions->osplOutputFile, osplOutput);
			else cout << osplOutput << endl;
			delete osagent;
		}
		else{
			delete osagent;
			throw ErrorClass( "please specify service location (url)" );
		}
		delete fileUtil;
		fileUtil = NULL;
	}
	catch(const ErrorClass& eclass){
		OSResult *osresult = NULL;
		OSrLWriter *osrlwriter = NULL;
		osrlwriter = new OSrLWriter();
		osresult = new OSResult();
		osresult->setGeneralMessage( eclass.errormsg);
		osresult->setGeneralStatusType( "error");
		std::string osrl = osrlwriter->writeOSrL( osresult);
		if(osoptions->osrlFile != "") fileUtil->writeFileFromString(osoptions->osrlFile, osrl);
		else cout << osrl << endl;
		delete osresult;
		osresult = NULL;
		delete osrlwriter;
		osrlwriter = NULL;
		delete fileUtil;
		fileUtil = NULL;
	}	
}//end knock


void send(){
	bool bSend = false;
	std::string jobID = "";
	OSSolverAgent* osagent = NULL;
	// first get the jobID
	std::string sOSoL = "<?xml version=\"1.0\" encoding=\"UTF-8\"?> <osol xmlns=\"os.optimizationservices.org\" xmlns:xs=\"http://www.w3.org/2001/XMLSchema\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xsi:schemaLocation=\"os.optimizationservices.org http://www.optimizationservices.org/schemas/OSoL.xsd\"><general> </general></osol>";
	string::size_type iStringpos;
	try{
		// call a method here to get OSiL if we have an nl or mps file
		if(osoptions->osil == ""){
			//we better have an nl file present or mps file
			if(osoptions->nlFile != ""){
				getOSiLFromNl();
			}
			else{
				if(osoptions->mpsFile != ""){
					getOSiLFromMps();
				}
				else{
					throw ErrorClass("solve called and no osil, nl, or mps file given");
				}
			}
		}
		if(osoptions->serviceLocation != ""){
			osagent = new OSSolverAgent( osoptions->serviceLocation );
			// check to see if there is an osol 
			if(osoptions->osolFile == ""){
				// get a jobID
				jobID =  osagent->getJobID( sOSoL) ;
				// insert the jobID into the default osol
				iStringpos = sOSoL.find("</general");
				cout << "startel ==  " << iStringpos << endl;
				if(iStringpos != std::string::npos) sOSoL.insert(iStringpos, "<jobID>" + jobID+ "</jobID>");
			}
			else{
				// we have an osol file use it for the sOSoL
				sOSoL = osoptions->osol;
				// see if we have a jobID
				iStringpos = sOSoL.find("<jobID");
				// if we have a jobId send out the osil and osol files
				if(iStringpos == std::string::npos){
					// get a jobID and insert it
					jobID =  osagent->getJobID( osoptions->osol) ;
					iStringpos = sOSoL.find("</general");
					if(iStringpos != std::string::npos) sOSoL.insert(iStringpos, "<jobID>" + jobID+ "</jobID>");
				}
			}
			cout << sOSoL << endl;
			bSend = osagent->send(osoptions->osil, sOSoL);
			if(bSend == true) cout << "send is true" << endl;
			else cout << "send is false" << endl;
			delete  osagent;
		}
		else{
			delete  osagent;
			throw ErrorClass( "please specify service location (url)" );
		}
	}
	catch(const ErrorClass& eclass){
		FileUtil *fileUtil = NULL;
		fileUtil = new FileUtil();
		OSResult *osresult = NULL;
		OSrLWriter *osrlwriter = NULL;
		osrlwriter = new OSrLWriter();
		osresult = new OSResult();
		osresult->setGeneralMessage( eclass.errormsg);
		osresult->setGeneralStatusType( "error");
		std::string osrl = osrlwriter->writeOSrL( osresult);
		if(osoptions->osrlFile != "") fileUtil->writeFileFromString(osoptions->osrlFile, osrl);
		else cout << osrl << endl;
		delete osresult;
		osresult = NULL;
		delete osrlwriter;
		osrlwriter = NULL;
		delete fileUtil;
		fileUtil = NULL;
	}	
}//end send

void retrieve(){
	FileUtil *fileUtil = NULL;
	fileUtil = new FileUtil();
	std::string osrl = "";
	OSSolverAgent* osagent = NULL;
	try{
		if(osoptions->serviceLocation != ""){
			osagent = new OSSolverAgent( osoptions->serviceLocation );
			std::cout << "HERE ARE THE OSOL OPTIONS " <<  osoptions->osol << std::endl;
			osrl = osagent->retrieve( osoptions->osol);
			if(osoptions->osrlFile != "") {
				fileUtil->writeFileFromString(osoptions->osrlFile, osrl); 
				if(osoptions->browser != ""){
					std::string str = osoptions->browser + "  " + osoptions->osrlFile ;
					const char *ch = &str[ 0];
					std::system( ch );
				}
			}
			else cout << osrl << endl;
			delete osagent;
			osagent = NULL;
		}
		else{
			delete osagent;
			osagent = NULL;
			throw ErrorClass( "please specify service location (url)" );
		}
		delete fileUtil;
		fileUtil = NULL;
	}
	catch(const ErrorClass& eclass){
		OSResult *osresult = NULL;
		OSrLWriter *osrlwriter = NULL;
		osrlwriter = new OSrLWriter();
		osresult = new OSResult();
		osresult->setGeneralMessage( eclass.errormsg);
		osresult->setGeneralStatusType( "error");
		std::string osrl = osrlwriter->writeOSrL( osresult);
		if(osoptions->osrlFile != "") fileUtil->writeFileFromString(osoptions->osrlFile, osrl);
		else cout << osrl << endl;
		delete osresult;
		osresult = NULL;
		delete osrlwriter;
		osrlwriter = NULL;
		delete fileUtil;
		fileUtil = NULL;
	}	
}//end retrieve

void kill(){
	FileUtil *fileUtil = NULL;
	fileUtil = new FileUtil();
	std::string osplOutput = "";
	OSSolverAgent* osagent = NULL;
	try{
		if(osoptions->serviceLocation != ""){
			osagent = new OSSolverAgent( osoptions->serviceLocation );
			osplOutput = osagent->kill( osoptions->osol);
			if(osoptions->osplOutputFile != "") fileUtil->writeFileFromString(osoptions->osplOutputFile, osplOutput);
			else cout << osplOutput << endl;
			delete osagent;
			osagent = NULL;
		}
		else{
			delete osagent;
			osagent = NULL;
			throw ErrorClass( "please specify service location (url)" );
		}
		delete fileUtil;
		fileUtil = NULL;
	}
	catch(const ErrorClass& eclass){
		OSResult *osresult = NULL;
		OSrLWriter *osrlwriter = NULL;
		osrlwriter = new OSrLWriter();
		osresult = new OSResult();
		osresult->setGeneralMessage( eclass.errormsg);
		osresult->setGeneralStatusType( "error");
		std::string osrl = osrlwriter->writeOSrL( osresult);
		if(osoptions->osrlFile != "") fileUtil->writeFileFromString(osoptions->osrlFile, osrl);
		else cout << osrl << endl;
		delete osresult;
		osresult = NULL;
		delete osrlwriter;
		osrlwriter = NULL;
		delete fileUtil;
		fileUtil = NULL;
	}	
}//end kill

void getOSiLFromNl(){
	try{
		#ifdef COIN_HAS_ASL
		OSnl2osil *nl2osil = NULL;
		nl2osil = new OSnl2osil( osoptions->nlFile);
		nl2osil->createOSInstance() ;
		OSiLWriter *osilwriter = NULL;
		osilwriter = new OSiLWriter();
		std::string osil;
		osil = osilwriter->writeOSiL(  nl2osil->osinstance) ;
		osoptions->osil = osil;
		delete nl2osil;
		nl2osil = NULL;
		delete osilwriter;
		osilwriter = NULL; 	
		#else
		throw ErrorClass("trying to convert nl to osil without AMPL ASL configured");
		#endif
	}
	catch(const ErrorClass& eclass){
		std::cout << eclass.errormsg <<  std::endl;
		throw ErrorClass( eclass.errormsg) ;
	}	
}//getOSiLFromNl


void getOSiLFromMps(){
	try{
		OSmps2osil *mps2osil = NULL;
		mps2osil = new OSmps2osil( osoptions->mpsFile);
		mps2osil->createOSInstance() ;
		OSiLWriter *osilwriter = NULL;
		osilwriter = new OSiLWriter();
		std::string osil;
		osil = osilwriter->writeOSiL(  mps2osil->osinstance) ;
		osoptions->osil = osil;
		delete mps2osil;
		mps2osil = NULL;
		delete osilwriter;
		osilwriter = NULL; 	
	}
	catch(const ErrorClass& eclass){
		std::cout << eclass.errormsg <<  std::endl;
		throw ErrorClass( eclass.errormsg) ;
	}	
	
}//getOSiLFromMps

string getServiceURI( std::string osol){
	if(osol == "") return osol;
	string::size_type pos2;
	string::size_type  pos1 = osol.find( "<serviceURI");
	if(pos1 != std::string::npos){
		// get the end of the serviceURI start tag
		pos1 = osol.find(">", pos1 + 1);
		if(pos1 != std::string::npos){
			// get the start of serviceURI end tag
			pos2 = osol.find( "</serviceURI", pos1 + 1);
			if( pos2 != std::string::npos){
				// get the substring
				return osol.substr( pos1 + 1, pos2 - pos1 - 1); 
			}
			else return "";
		}
		else return "";
	}
	else return "";
}//getServiceURI

string getInstanceLocation( std::string osol){
	if(osol == "") return osol;
	string::size_type pos2;
	string::size_type pos1 = osol.find( "<instanceLocation");
	if(pos1 != std::string::npos){
		// get the end of the instanceLocation start tag
		pos1 = osol.find(">", pos1 + 1);
		if(pos1 != std::string::npos){
			// get the start of instanceLocation end tag
			pos2 = osol.find( "</instanceLocation", pos1 + 1);
			if( pos2 != std::string::npos){
				// get the substring
				return osol.substr( pos1 + 1, pos2 - pos1 - 1); 
			}
			else return "";
		}
		else return "";
	}
	else return "";
}//getInstanceLocation

string getSolverName( std::string osol){
	if(osol == "") return osol;
	string::size_type pos2;
	string::size_type pos1 = osol.find( "os_solver");
	if(pos1 != std::string::npos){
		// get the end of the instanceLocation start tag
		pos1 = osol.find(">", pos1 + 1);
		if(pos1 != std::string::npos){
			// get the start of instanceLocation end tag
			pos2 = osol.find( "</other", pos1 + 1);
			if( pos2 != std::string::npos){
				// get the substring
				return osol.substr( pos1 + 1, pos2 - pos1 - 1); 
			}
			else return "";
		}
		else return "";
	}
	else return "";
}//getSolverName

std::string get_help(){

	std::ostringstream helpMsg;

	
	helpMsg << "************************* HELP *************************" << endl << endl;
	helpMsg << "In this HELP file we assume that the solve service method is used and " << endl; 
	helpMsg << "that we are solving problems locally, that is the solver is on the " << endl; 
	helpMsg << "machine running this OSSolverService.  See Section 10.3 of the User\'s  " << endl;
	helpMsg << "Manual for other service methods or calling a server remotely. " << endl; 
	helpMsg << "The OSSolverService takes the parameters listed below.  " << endl;
	helpMsg << "The order of the parameters is irrelevant.  Not all the parameters  " << endl;
	helpMsg << "are required.  However, the location of an instance file is  " << endl;
	helpMsg << "required when using the solve service method. The location of the " << endl;
	helpMsg << "instance file is specified using the osil option. " << endl;

	helpMsg << endl;
	
	helpMsg << "-osil xxx.osil this is the name of the file that contains the  " << endl;
	helpMsg << "optimization instance in OSiL format.  This option may be  " << endl;
	helpMsg << "specified in the OSoL solver options file. " << endl;
	
	helpMsg << endl;

	helpMsg << "-osol xxx.osol  this is the name of the file that contains the solver options.   " << endl;
	helpMsg << "It is not necessary to specify this option. " << endl; 
	
	helpMsg << endl;

	helpMsg << "-osrl xxx.osrl  this is the name of the file to which the solver solution is written.  " << endl; 
	helpMsg << "It is not necessary to specify this option. If this option is not specified,  " << endl;
	helpMsg << "the result will be printed to standard out.  " << endl;
	
	helpMsg << endl;

	helpMsg << "-serviceLocation url is the URL of the solver service.  " << endl;
	helpMsg << "This is not required, and if not specified it is assumed that   " << endl;
	helpMsg << "the problem is solved locally.  " << endl;
	
	helpMsg << endl;

	helpMsg << "-serviceMethod  methodName this is the method on the solver service to be invoked.  " << endl; 
	helpMsg << "The options are  solve,  send,  kill,  knock,  getJobID, and t retrieve.   " << endl;
	helpMsg << "This option is not required, and the default value is  solve.  " << endl;
	
	helpMsg << endl;

	helpMsg << "-mps  xxx.mps  this is the name of the mps file if the problem instance  " << endl;
	helpMsg << "is in mps format. The default file format is OSiL so this option is not required.  " << endl;
	
	helpMsg << endl;

	helpMsg << "-nl  xxx.nl  this is the name of the AMPL nl file if the problem  " << endl;
	helpMsg << "instance is in AMPL nl  format. The default file format is OSiL  " << endl;
	helpMsg << "so this option is not required.  " << endl;
	
	helpMsg << endl;

	helpMsg << "-solver  solverName  Possible values for default OS installation  " << endl;
	helpMsg << "are  bonmin(COIN-OR Bonmin), couenne (COIN-OR Couenne), clp (COIN-OR Clp)," << endl;
	helpMsg << "cbc (COIN-OR Cbc), dylp (COIN-OR DyLP), ipopt (COIN-OR Ipopt)," << endl;
	helpMsg << "and symphony (COIN-OR SYMPHONY). Other solvers supported" << endl;
	helpMsg << "(if the necessary libraries are present) are cplex (Cplex through COIN-OR Osi)," << endl;
	helpMsg << "glpk (glpk through COIN-OR Osi), knitro (Knitro), and lindo (LINDO)." << endl;
	helpMsg << "If no value is specified for this parameter," << endl;
	helpMsg << "then cbc is the default value of this parameter." << endl; 
	
	helpMsg << endl;

	helpMsg << "-browser  browserName this paramater is a path to the browser on the  " << endl; 
	helpMsg << "local machine. If this optional parameter is specified then the  " << endl; 
	helpMsg << "solver result in OSrL format is transformed using XSLT into  " << endl; 
	helpMsg << "HTML and displayed in the browser.  " << endl; 
	
	helpMsg << endl;

	helpMsg << "-config pathToConfigureFile this parameter specifies a path on  " << endl; 
	helpMsg << "the local machine to a text file containing values for the input parameters.  " << endl; 
	helpMsg << "This is convenient for the user not wishing to constantly retype parameter values.  " << endl;
	helpMsg << "This configure file can contain values for all of the other parameters. " << endl;
	
	helpMsg << endl;

	helpMsg << "--version or -v get the current version of this executable  " << endl;
	
	helpMsg << endl;

	helpMsg << "--help or -h  to get this help file " << endl;

	
	helpMsg << endl;
	
	helpMsg << "Note: If you specify a configure file by using the -config option, you can  " << endl;
	helpMsg << "override the values of the options in the configure file by putting them in   " << endl;
	helpMsg << "at the command line. " << endl << endl;
	
	helpMsg << "See the OS User\' Manual: http://www.coin-or.org/OS/doc/osUsersManual_1.1.pdf" << endl;
	helpMsg << "for more detail on how to use the OS project. " << endl;
	
	helpMsg << endl;
	helpMsg << "********************************************************" << endl << endl;

	return helpMsg.str();
}// get help


std::string get_version(){

	std::ostringstream versionMsg;
	versionMsg << "In order to find the version of this project " << endl;
	versionMsg << "connect to the directory where you downloaded " << endl;
	versionMsg << "and do: " << endl;
	versionMsg << "svn info " << endl;
	
	
	return versionMsg.str();
}// get version




