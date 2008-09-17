/** @file OSoLWriter.cpp
 * 
 *
 * @author  Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin, 
 * @version 1.0, 17/July/2008
 * @since   OS1.1
 *
 * \remarks
 * Copyright (C) 2005, Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, Dalhousie University and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */
 
 
 
#include "OSoLWriter.h"
#include "OSOption.h"
#include "OSParameters.h"
#include "OSCommonUtil.h"
#include "OSConfig.h"
#include <sstream>   
#include <iostream>  

using std::cout;
using std::endl;
using std::ostringstream;

OSoLWriter::OSoLWriter( ) {	 
}

OSoLWriter::~OSoLWriter(){
}


/*char* OSoLWriter::writeOSoLWrap( OSOption *theosoption){
	std::string sTmp = writeOSoL( theosoption);
	char *ch;
    ch = new char[sTmp.size() + 1];
    strcpy(ch, sTmp.c_str());
	return ch;
}
*/




 
std::string OSoLWriter::writeOSoL( OSOption *theosoption){
	m_OSOption = theosoption;
	std::ostringstream outStr;  
	#ifdef WIN_
	const char	dirsep='\\';
	#else
	const char	dirsep='/';
	#endif
  	// Set directory containing stylesheet files.
  	std::string xsltDir;
	xsltDir = dirsep == '/' ? "../stylesheets/" : "..\\stylesheets\\";
	// always go with '/' -- it is a hypertext reference
	xsltDir = "../stylesheets/";
	int i, j;
	if(m_OSOption == NULL)  return outStr.str(); 
	outStr << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" ; 
	outStr << "<?xml-stylesheet type = \"text/xsl\" href = \"";
	outStr << xsltDir;
	outStr << "OSoL.xslt\"?>";
	outStr << "<osol xmlns=\"os.optimizationservices.org\"   xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xsi:schemaLocation=\"os.optimizationservices.org http://www.optimizationservices.org/schemas/OSoL.xsd\" >" ;
	outStr << endl;

/**
 * 	Put the <general> element
 */
	if(m_OSOption->general != NULL)
	{	outStr << "<general>" << endl;
		if (m_OSOption->general->serviceURI != "")
		{	outStr << "<serviceURI>" + m_OSOption->general->serviceURI + "</serviceURI>" << endl;
		};
		if (m_OSOption->general->serviceName != "")
		{	outStr << "<serviceName>" + m_OSOption->general->serviceName + "</serviceName>" << endl;
		};
		if (m_OSOption->general->instanceName != "")
		{	outStr << "<instanceName>" + m_OSOption->general->instanceName + "</instanceName>" << endl;
		};
		if (m_OSOption->general->instanceLocation != NULL)
		{	if (m_OSOption->general->instanceLocation->locationType == "")
			{	outStr << "<instanceLocation>";
			}
			else 
			{	outStr << "<instanceLocation locationType=\"" + m_OSOption->general->instanceLocation->locationType + "\">";
			};
			outStr << "\"" + m_OSOption->general->instanceLocation->value + "\"</instanceLocation>" << endl;
		};
		if (m_OSOption->general->jobID != "")
		{	outStr << "<jobID>" + m_OSOption->general->jobID + "</jobID>" << endl;
		};
		if (m_OSOption->general->license != "")
		{	outStr << "<license>" + m_OSOption->general->license + "</license>" << endl;
		};
		if (m_OSOption->general->userName != "")
		{	outStr << "<userName>" + m_OSOption->general->userName + "</userName>" << endl;
		};
		if (m_OSOption->general->password != "")
		{	outStr << "<password>" + m_OSOption->general->password + "</password>" << endl;
		};
		if (m_OSOption->general->contact != NULL)
		{	outStr << "<contact>";
			if (m_OSOption->general->contact->transportType == "")
			{	outStr << "<contact>";
			}
			else 
			{	outStr << "<contact contactType=\"" + m_OSOption->general->contact->transportType + "\">";
			};
			outStr << "\"" + m_OSOption->general->contact->value + "\"</contact>" << endl;
		};
		if (m_OSOption->general->otherOptions != NULL)
		{	if (m_OSOption->general->otherOptions->numberOfOtherOptions > 0)
			{	outStr << "<otherOptions numberOfOtherOptions=\""; 
				outStr << m_OSOption->general->otherOptions->numberOfOtherOptions + "\">" << endl;
				for (int i=0; i < m_OSOption->general->otherOptions->numberOfOtherOptions; i++)
				{	outStr << "<other name=\"" + m_OSOption->general->otherOptions->other[i]->name + "\"";
					if (m_OSOption->general->otherOptions->other[i]->value != "")
						outStr << "value=\" + m_OSOption->general->otherOptions->other[i]->value + \"";
					if (m_OSOption->general->otherOptions->other[i]->description != "")
						outStr << "description=\" + m_OSOption->general->otherOptions->other[i]->description + \"";
					outStr << "/>" << endl;
				}
				outStr << "</otherOptions>" << endl;
			}
		}
		outStr << "</general>" << endl;
	};

/**
 * 	Put the <system> element
 */
	if(m_OSOption->system != NULL){
		outStr << "<system>" << endl;
		if (m_OSOption->system->minDiskSpace != NULL)
		{	if (m_OSOption->system->minDiskSpace->unit == "")
				m_OSOption->system->minDiskSpace->unit = "byte";
			outStr << "<minDiskSpace unit=\"" << m_OSOption->system->minDiskSpace->unit << "\">";
			outStr << m_OSOption->system->minDiskSpace->value << "</minDiskSpace>" << endl;
		}
		if (m_OSOption->system->minMemorySize != NULL)
		{	if (m_OSOption->system->minMemorySize->unit == "")
				m_OSOption->system->minMemorySize->unit = "byte";
			outStr << "<minMemorySize unit=\"" << m_OSOption->system->minMemorySize->unit << "\">";
			outStr << m_OSOption->system->minMemorySize->value << "</minMemorySize>" << endl;
		}
		if (m_OSOption->system->minCPUSpeed != NULL)
		{	if (m_OSOption->system->minCPUSpeed->unit == "")
				m_OSOption->system->minCPUSpeed->unit = "hertz";
			outStr << "<minCPUSpeed unit=\"" << m_OSOption->system->minCPUSpeed->unit << "\">";
			outStr << m_OSOption->system->minCPUSpeed->value << "</minCPUSpeed>" << endl;
		}
		if (m_OSOption->system->minCPUNumber > 0.0)
		{	outStr << "<minCPUNumber>" << m_OSOption->system->minCPUNumber << "</minCPUNumber>";
		};
		if (m_OSOption->system->otherOptions != NULL)
		{	if (m_OSOption->system->otherOptions->numberOfOtherOptions > 0)
			{	outStr << "<otherOptions numberOfOtherOptions=\""; 
				outStr << m_OSOption->system->otherOptions->numberOfOtherOptions << "\">" << endl;
				for (int i=0; i < m_OSOption->system->otherOptions->numberOfOtherOptions; i++)
				{	outStr << "<other name=\"" + m_OSOption->system->otherOptions->other[i]->name + "\"";
					if (m_OSOption->system->otherOptions->other[i]->value != "")
						outStr << "value=\" + m_OSOption->system->otherOptions->other[i]->value + \"";
					if (m_OSOption->system->otherOptions->other[i]->description != "")
						outStr << "description=\" + m_OSOption->system->otherOptions->other[i]->description + \"";
					outStr << "/>" << endl;
				}
				outStr << "</otherOptions>" << endl;
			}
		}
		outStr << "</system>" << endl;
	};

/**
 * 	Put the <service> element
 */
	if(m_OSOption->service != NULL){
		outStr << "<service>" << endl;
		if (m_OSOption->service->type != "")
		{	outStr << "<type>" + m_OSOption->service->type + "</type>";
		};
		if (m_OSOption->service->otherOptions != NULL)
		{	if (m_OSOption->service->otherOptions->numberOfOtherOptions > 0)
			{	outStr << "<otherOptions numberOfOtherOptions=\""; 
				outStr << m_OSOption->service->otherOptions->numberOfOtherOptions + "\">" << endl;
				for (int i=0; i < m_OSOption->service->otherOptions->numberOfOtherOptions; i++)
				{	outStr << "<other name=\"" + m_OSOption->service->otherOptions->other[i]->name + "\"";
					if (m_OSOption->service->otherOptions->other[i]->value != "")
						outStr << "value=\" + m_OSOption->service->otherOptions->other[i]->value + \"";
					if (m_OSOption->service->otherOptions->other[i]->description != "")
						outStr << "description=\" + m_OSOption->service->otherOptions->other[i]->description + \"";
					outStr << "/>" << endl;
				}
				outStr << "</otherOptions>" << endl;
			}
		}
		outStr << "</service>" << endl;
	};

/**
 * 	Put the <job> element
 */
	if(m_OSOption->job != NULL)
	{	outStr << "<job>" << endl;
//		outStr << "<maxTime>" << m_OSOption->job->maxTime << "</maxTime>" << endl;
//		outStr << "<scheduledStartTime>" + m_OSOption->job->scheduledStartTime + "</scheduledStartTime>" << endl;
//dependencies
//requiredDirectoriesAndFiles
//directoriesToMake
//filesToCreate
//inputFilesToCopyFrom
//inputFilesToCopyTo
//inputFilesToMoveFrom
//inputFilesToMoveTo
//outputFilesToCopyFrom
//outputFilesToCopyTo
//outputFilesToMoveFrom
//outputFilesToMoveTo
//filesToDelete
//directoriesToDelete
//processesToKill


		outStr << "</job>" << endl;
	};

/**
 * 	Put the <optimization> element
 */
	if(m_OSOption->optimization != NULL)
	{	outStr << "<optimization>" << endl;

		outStr << "</optimization>" << endl;
	};



	outStr << "</osol>" << endl;
	return outStr.str();
}// end writeOSoL



