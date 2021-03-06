/* $Id$ */
/** @file OSParseosol.y.1
 *
 * @author  Horand Gassmann, Jun Ma, Kipp Martin 
 *
 * \remarks
 * Copyright (C) 2005-2014, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 * In order to allow easier maintenance of the parsers, 
 * the files OSParseosol.y and OSParseosrl.y are stored in several pieces
 * that are combined in the makefile.
 * This is the first part of the file OSParseosol.y.
 * Tokens pertaining to the OSgL and OSnL parsers are appended.
 * These are in files OSParseosgl.y.tokens and OSParseosnl.y.tokens.   
 * Then follow the syntax rules involving only OSoL constructs (OSParseosol.y.2). 
 * After that we put the syntax rules for elements from the OSgL schema, 
 * maintained in the file OSParseosgl.y.syntax, and then the OSnL syntax
 * in OSParseosnl.y.syntax. The postamble in OSParseosol.y.3 is appended at the end.
 * This process could be repeated for as many other auxiliary schemas as needed. 
 */

%{


#include "OSConfig.h"
#include "OSMathUtil.h"
#include "OSParameters.h"
#include "OSGeneral.h"
#include "OSErrorClass.h"
#include "OSOption.h"
#include "OSoLParserData.h"
#include "OSgLParserData.h"
#include "OSnLParserData.h"
#include "OSBase64.h"

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>

//#define DEBUG

#ifdef DEBUG
#define YYDEBUG 1
#endif

typedef struct yy_buffer_state *YY_BUFFER_STATE;
YY_BUFFER_STATE osol_scan_string (const char *yy_str , void* yyscanner  );
int osollex_init(void** ptr_yy_globals);
int osollex_destroy (void* yyscanner );
int osolget_lineno( void* yyscanner);
char *osolget_text (void* yyscanner );
void osolset_lineno (int line_number , void* yyscanner );
void osolset_extra (OSoLParserData* parserData , void* yyscanner );
void  yygetOSOption(const char *ch, OSOption* m_osoption, OSoLParserData *m_parserData, OSgLParserData *osglData, OSnLParserData *osnlData ) throw(ErrorClass);
void osol_empty_vectors( OSoLParserData* parserData);
void osgl_empty_vectors( OSgLParserData* osglData);
void osnl_empty_vectors( OSnLParserData* osnlData);


%}


%pure-parser
%locations
%defines
%parse-param{OSOption *osoption}
%parse-param{OSoLParserData *parserData}
%parse-param{OSgLParserData *osglData}
%parse-param{OSnLParserData *osnlData}
%lex-param {void* scanner}


%union {
    double dval;
    int ival;
    char* sval;
}

/* %name-prefix="osol"
this fails in Mac OS X
*/

%{

std::string addErrorMsg(YYLTYPE* mytype, OSOption *osoption, OSoLParserData* parserData, OSgLParserData* osglData, OSnLParserData* osnlData, std::string errormsg ) ;
void osolerror(YYLTYPE* mytype, OSOption *osoption, OSoLParserData* parserData, OSgLParserData* osglData, OSnLParserData* osnlData, std::string errormsg );
int osollex(YYSTYPE* lvalp,  YYLTYPE* llocp, void* scanner);
#define scanner parserData->scanner
%}

%token <sval> ATTRIBUTETEXT
%token <sval> ELEMENTTEXT
%token <sval> ITEMTEXT
%token <ival> INTEGER
%token <dval> DOUBLE
%token <sval> QUOTE

%token TWOQUOTES GREATERTHAN ENDOFELEMENT
%token OSOLSTART OSOLSTARTEMPTY OSOLATTRIBUTETEXT OSOLEND

%token NUMBEROFOTHEROPTIONSATT NUMBEROFENUMERATIONSATT;
%token NUMBEROFJOBIDSATT NUMBEROFPATHSATT NUMBEROFPATHPAIRSATT;
%token FROMATT TOATT MAKECOPYATT CATEGORYATT TYPEATT GROUPWEIGHTATT;
%token NUMBEROFPROCESSESATT NUMBEROFSOLVEROPTIONSATT NUMBEROFSOSATT;
%token NUMBEROFVARIABLESATT NUMBEROFOBJECTIVESATT NUMBEROFCONSTRAINTSATT;
%token NUMBEROFOTHERVARIABLEOPTIONSATT NUMBEROFOTHEROBJECTIVEOPTIONSATT;
%token NUMBEROFOTHERCONSTRAINTOPTIONSATT NUMBEROFITEMSATT;
%token NUMBEROFVARATT NUMBEROFOBJATT NUMBEROFCONATT NUMBEROFELATT;
%token NAMEATT IDXATT SOSIDXATT VALUEATT UNITATT DESCRIPTIONATT;
%token CONTYPEATT EMPTYCONTYPEATT ENUMTYPEATT EMPTYENUMTYPEATT 
%token OBJTYPEATT EMPTYOBJTYPEATT VARTYPEATT EMPTYVARTYPEATT 
%token EMPTYTYPEATT EMPTYNAMEATT EMPTYCATEGORYATT EMPTYDESCRIPTIONATT EMPTYUNITATT EMPTYVALUEATT;
%token EMPTYLBVALUEATT EMPTYUBVALUEATT LBVALUEATT UBVALUEATT
%token EMPTYLBDUALVALUEATT EMPTYUBDUALVALUEATT LBDUALVALUEATT UBDUALVALUEATT
%token SOLVERATT EMPTYSOLVERATT WEIGHTATT EMPTYWEIGHTATT;
%token TRANSPORTTYPEATT LOCATIONTYPEATT;

%token GENERALSTART GENERALEND SYSTEMSTART SYSTEMEND SERVICESTART SERVICEEND;
%token JOBSTART JOBEND OPTIMIZATIONSTART OPTIMIZATIONEND;

%token SERVICEURISTART SERVICEURIEND SERVICENAMESTART SERVICENAMEEND;
%token INSTANCENAMESTART INSTANCENAMEEND INSTANCELOCATIONSTART INSTANCELOCATIONEND;
%token JOBIDSTART JOBIDEND SOLVERTOINVOKESTART SOLVERTOINVOKEEND;
%token LICENSESTART LICENSEEND USERNAMESTART USERNAMEEND PASSWORDSTART PASSWORDEND;
%token CONTACTSTART CONTACTEND OTHEROPTIONSSTART OTHEROPTIONSEND OTHERSTART OTHEREND;
%token MINDISKSPACESTART MINDISKSPACEEND MINMEMORYSTART MINMEMORYEND MINCPUSPEEDSTART MINCPUSPEEDEND;
%token MINCPUNUMBERSTART MINCPUNUMBEREND SERVICETYPESTART SERVICETYPEEND;
%token MAXTIMESTART MAXTIMEEND REQUESTEDSTARTTIMESTART REQUESTEDSTARTTIMEEND;
%token DEPENDENCIESSTART DEPENDENCIESEND;
%token REQUIREDDIRECTORIESSTART REQUIREDDIRECTORIESEND REQUIREDFILESSTART REQUIREDFILESEND;
%token PATHSTART PATHEND PATHPAIRSTART PATHPAIREND;
%token DIRECTORIESTOMAKESTART DIRECTORIESTOMAKEEND FILESTOMAKESTART FILESTOMAKEEND;
%token DIRECTORIESTODELETESTART DIRECTORIESTODELETEEND FILESTODELETESTART FILESTODELETEEND;
%token  INPUTDIRECTORIESTOMOVESTART  INPUTDIRECTORIESTOMOVEEND  INPUTFILESTOMOVESTART  INPUTFILESTOMOVEEND;
%token OUTPUTDIRECTORIESTOMOVESTART OUTPUTDIRECTORIESTOMOVEEND OUTPUTFILESTOMOVESTART OUTPUTFILESTOMOVEEND;
%token PROCESSESTOKILLSTART PROCESSESTOKILLEND PROCESSSTART PROCESSEND;

%token VARIABLESSTART VARIABLESEND;
%token INITIALVARIABLEVALUESSTART INITIALVARIABLEVALUESEND VARSTART VAREND;
%token INITIALVARIABLEVALUESSTRINGSTART INITIALVARIABLEVALUESSTRINGEND;
%token INITIALBASISSTATUSSTART INITIALBASISSTATUSEND;
%token BASICSTART BASICEND ATUPPERSTART ATUPPEREND ATLOWERSTART ATLOWEREND ATEQUALITYSTART ATEQUALITYEND
%token SUPERBASICSTART SUPERBASICEND ISFREESTART ISFREEEND UNKNOWNSTART UNKNOWNEND
%token INTEGERVARIABLEBRANCHINGWEIGHTSSTART INTEGERVARIABLEBRANCHINGWEIGHTSEND
%token SOSVARIABLEBRANCHINGWEIGHTSSTART SOSVARIABLEBRANCHINGWEIGHTSEND
%token SOSSTART SOSEND

%token OBJECTIVESSTART OBJECTIVESEND;
%token INITIALOBJECTIVEVALUESSTART INITIALOBJECTIVEVALUESEND OBJSTART OBJEND;
%token INITIALOBJECTIVEBOUNDSSTART INITIALOBJECTIVEBOUNDSEND;
%token CONSTRAINTSSTART CONSTRAINTSEND;
%token INITIALCONSTRAINTVALUESSTART INITIALCONSTRAINTVALUESEND CONSTART CONEND;
%token INITIALDUALVALUESSTART INITIALDUALVALUESEND;
%token SOLVEROPTIONSSTART SOLVEROPTIONSEND SOLVEROPTIONSTART SOLVEROPTIONEND;
%token ENUMERATIONSTART ENUMERATIONEND;
%token ITEMEMPTY ITEMSTART ITEMEND ITEMSTARTANDEND;
%token BASE64START BASE64END;
%token INCRATT MULTATT SIZEOFATT;
%token ELSTART ELEND;

/* $Id$ */
/** @file OSParseosgl.y.tokens
 *
 * @author  Horand Gassmann, Jun Ma, Kipp Martin 
 *
 * \remarks
 * Copyright (C) 2005-2014, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 * In order to allow easier maintenance of the parsers, the files 
 * OSParseosil.y, OSParseosol.y and OSParseosrl.y are stored in several pieces.
 * These are the tokens pertaining to the OSgL parser.
 * They are appended after the regular OSxL tokens.
 *
 */

%token HEADERSTART HEADEREND

%token FILENAMESTART FILENAMEEND FILENAMEEMPTY FILENAMESTARTANDEND
%token FILESOURCESTART FILESOURCEEND FILESOURCEEMPTY FILESOURCESTARTANDEND
%token FILEDESCRIPTIONSTART FILEDESCRIPTIONEND FILEDESCRIPTIONEMPTY FILEDESCRIPTIONSTARTANDEND
%token FILECREATORSTART FILECREATOREND FILECREATOREMPTY FILECREATORSTARTANDEND
%token FILELICENCESTART FILELICENCEEND FILELICENCEEMPTY FILELICENCESTARTANDEND

%token ENUMERATIONSTART ENUMERATIONEND NUMBEROFELATT
%token ITEMEMPTY ITEMSTART ITEMEND ITEMSTARTANDEND
%token BASE64START BASE64END
%token INCRATT MULTATT SIZEOFATT
%token ELSTART ELEND

%token MATRIXSTART MATRIXEND BASEMATRIXEND BASEMATRIXSTART
%token BLOCKSTART BLOCKEND BLOCKSSTART BLOCKSEND

%token EMPTYNAMEATT NAMEATT EMPTYTYPEATT TYPEATT EMPTYSHAPEATT SHAPEATT
%token EMPTYSYMMETRYATT SYMMETRYATT EMPTYNEGATIVEPATTERNATT NEGATIVEPATTERNATT CONSTANTATT
%token NUMBEROFBLOCKSATT NUMBEROFCOLUMNSATT NUMBEROFROWSATT NUMBEROFVALUESATT NUMBEROFVARIDXATT

%token IDXATT COEFATT

%token BASEMATRIXIDXATT TARGETMATRIXFIRSTROWATT TARGETMATRIXFIRSTCOLATT
%token BASEMATRIXSTARTROWATT BASEMATRIXSTARTCOLATT BASEMATRIXENDROWATT BASEMATRIXENDCOLATT
%token SCALARMULTIPLIERATT EMPTYBASETRANSPOSEATT BASETRANSPOSEATT

%token ELEMENTSSTART ELEMENTSEND
%token CONSTANTELEMENTSSTART CONSTANTELEMENTSEND STARTVECTORSTART STARTVECTOREND
%token NONZEROSSTART NONZEROSEND INDEXESSTART INDEXESEND VALUESSTART VALUESEND
%token VARREFERENCEELEMENTSSTART VARREFERENCEELEMENTSEND
%token LINEARELEMENTSSTART LINEARELEMENTSEND
%token GENERALELEMENTSSTART GENERALELEMENTSEND
%token CONREFERENCEELEMENTSSTART CONREFERENCEELEMENTSEND
%token OBJREFERENCEELEMENTSSTART OBJREFERENCEELEMENTSEND
%token PATTERNELEMENTSSTART PATTERNELEMENTSEND VARIDXSTART VARIDXEND

%token TRANSFORMATIONSTART TRANSFORMATIONEND

%token COLOFFSETSSTART COLOFFSETSEND ROWOFFSETSSTART ROWOFFSETSEND

%token EMPTYROWMAJORATT ROWMAJORATT BLOCKROWIDXATT BLOCKCOLIDXATT

%token DUMMY


/* $Id$ */
/** @file OSParseosnl.y.tokens
 *
 * @author  Horand Gassmann, Jun Ma, Kipp Martin 
 *
 * \remarks
 * Copyright (C) 2005-2014, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 * In order to allow easier maintenance of the parsers, the files 
 * OSParseosil.y, OSParseosol.y and OSParseosrl.y are stored in several pieces.
 * These are the tokens pertaining to the OSnL parser.
 * They are appended after the regular OSxL tokens.
 *
 */

%token NONLINEAREXPRESSIONSSTART NONLINEAREXPRESSIONSEND NUMBEROFNONLINEAREXPRESSIONS NLSTART NLEND
%token MATRIXEXPRESSIONSSTART MATRIXEXPRESSIONSEND NUMBEROFEXPR EXPRSTART EXPREND
%token NUMBEROFMATRIXTERMSATT MATRIXTERMSTART MATRIXTERMEND

%token POWERSTART POWEREND PLUSSTART PLUSEND MINUSSTART MINUSEND
%token DIVIDESTART DIVIDEEND LNSTART LNEND SQRTSTART SQRTEND SUMSTART SUMEND PRODUCTSTART PRODUCTEND 
%token EXPSTART EXPEND NEGATESTART NEGATEEND IFSTART IFEND
%token SQUARESTART SQUAREEND COSSTART COSEND SINSTART SINEND
%token VARIABLESTART VARIABLEEND ABSSTART ABSEND ERFSTART ERFEND  MAXSTART MAXEND
%token ALLDIFFSTART ALLDIFFEND MINSTART MINEND ESTART EEND PISTART PIEND
%token TIMESSTART TIMESEND NUMBERSTART NUMBEREND 

%token MATRIXDETERMINANTSTART MATRIXDETERMINANTEND MATRIXTRACESTART MATRIXTRACEEND MATRIXTOSCALARSTART MATRIXTOSCALAREND

%token MATRIXDIAGONALSTART MATRIXDIAGONALEND MATRIXDOTTIMESSTART MATRIXDOTTIMESEND
%token MATRIXLOWERTRIANGLESTART MATRIXLOWERTRIANGLEEND MATRIXUPPERTRIANGLESTART MATRIXUPPERTRIANGLEEND
%token MATRIXMERGESTART MATRIXMERGEEND MATRIXMINUSSTART MATRIXMINUSEND MATRIXNEGATESTART MATRIXNEGATEEND
%token MATRIXPLUSSTART MATRIXPLUSEND MATRIXTIMESSTART MATRIXTIMESEND MATRIXPRODUCTSTART MATRIXPRODUCTEND
%token MATRIXSCALARTIMESSTART MATRIXSCALARTIMESEND MATRIXSUBMATRIXATSTART MATRIXSUBMATRIXATEND
%token MATRIXTRANSPOSESTART MATRIXTRANSPOSEEND MATRIXREFERENCESTART MATRIXREFERENCEEND
%token IDENTITYMATRIXSTART IDENTITYMATRIXEND MATRIXINVERSESTART  MATRIXINVERSEEND

%token EMPTYINCLUDEDIAGONALATT INCLUDEDIAGONALATT

%token IDATT

/* $Id$ */
/** @file OSParseosol.y.2
 *
 * @author  Horand Gassmann, Jun Ma, Kipp Martin 
 *
 * \remarks
 * Copyright (C) 2005-2014, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 * In order to allow easier maintenance of the parsers, 
 * the files OSParseosol.y and OSParseosrl.y are stored in several pieces
 * that are combined in the makefile.
 * This is the third part of the file OSParseosol.y, containing 
 * the grammar rules involving only OSoL constructs. 
 *
 * See also the comments in OSParseosol.y.1. 
 */

%%

osoldoc: 
    osolStartEmpty osolBody osolEnd
  | osolStart osolAttributes osolContent;

osolStartEmpty: OSOLSTARTEMPTY
{
#ifdef DEBUG
    yydebug = 1;
#endif
}; 

osolStart: OSOLSTART
{
#ifdef DEBUG
    yydebug = 1;
#endif
    parserData->parser_errors = "";
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;
}; 

osolAttributes: | OSOLATTRIBUTETEXT;

osolContent: osolEmpty | osolLaden;

osolEmpty: ENDOFELEMENT;

osolLaden: GREATERTHAN osolBody osolEnd; 
    
osolEnd: osolEnding
    {
        if (parserData->parser_errors != "")
        {
            parserData->parser_errors += ("\n\nOSoL input is either not valid or well formed.\n"); 
            osolerror( NULL, osoption, parserData, osglData, osnlData, parserData->parser_errors);
        }
    };

osolEnding: OSOLEND
  | { parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "unexpected end of file, expecting </osol>");};

osolBody: 
    headerElement generalElement systemElement serviceElement jobElement optimizationElement;

/**
 * ========================================================== 
 * OSoL header 
 * ==========================================================
 */

headerElement: | osglFileHeader
{
    if (!osoption->setHeader(osglData->fileName, osglData->source,
            osglData->description, osglData->fileCreator, osglData->licence) )     
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setHeader failed");
};


/**
 * ========================================================== 
 * <general> element 
 * ==========================================================
 */
generalElement: | generalElementStart generalElementContent;

generalElementStart: GENERALSTART
{
    parserData->serviceURIPresent          = false;    
    parserData->serviceNamePresent         = false;
    parserData->instanceNamePresent        = false;
    parserData->instanceLocationPresent    = false;
    parserData->jobIDPresent               = false;
    parserData->solverToInvokePresent      = false;
    parserData->licensePresent             = false;
    parserData->usernamePresent            = false;
    parserData->passwordPresent            = false;
    parserData->contactPresent             = false;
    parserData->otherGeneralOptionsPresent = false;
    osoption->general = new GeneralOption();
};

generalElementContent: generalElementEmpty | generalElementLaden;

generalElementEmpty: GREATERTHAN GENERALEND | ENDOFELEMENT;

generalElementLaden: GREATERTHAN generalElementBody GENERALEND; 

generalElementBody:  generalElementList;

generalElementList:  generalChild | generalElementList generalChild;

generalChild: 
    serviceURI 
  | serviceName
  | instanceName 
  | instanceLocation 
  | jobID
  | solverToInvoke 
  | license 
  | username 
  | password 
  | contact 
  | otherGeneralOptions
  ;

/* -------------------------------------------- */
serviceURI: serviceURIStart serviceURIContent;

serviceURIStart: SERVICEURISTART
{
    if (parserData->serviceURIPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated element: <serviceURI>");
    else
        parserData->serviceURIPresent = true;
    
};

serviceURIContent: serviceURIEmpty | serviceURILaden; 

serviceURIEmpty: GREATERTHAN SERVICEURIEND | ENDOFELEMENT;

serviceURILaden: GREATERTHAN serviceURIBody SERVICEURIEND;

serviceURIBody:  ELEMENTTEXT 
    {
        if (osoption->setServiceURI($1) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setServiceURI failed");
        free($1); 
        parserData->errorText = NULL;
    };


/* -------------------------------------------- */
serviceName: serviceNameStart serviceNameContent;

serviceNameStart: SERVICENAMESTART 
    {
        if (parserData->serviceNamePresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated element: <serviceName>");
        parserData->serviceNamePresent = true;
    };

serviceNameContent: serviceNameEmpty | serviceNameLaden;

serviceNameEmpty: GREATERTHAN SERVICENAMEEND | ENDOFELEMENT;

serviceNameLaden: GREATERTHAN serviceNameBody SERVICENAMEEND;

serviceNameBody:  ELEMENTTEXT  
    {
        if (osoption->setServiceName($1) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setServiceName failed");
        free($1); 
        parserData->errorText = NULL;
    };


/* -------------------------------------------- */
instanceName: instanceNameStart instanceNameContent;

instanceNameStart:  INSTANCENAMESTART 
    {    if (parserData->instanceNamePresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated element: <instanceName>");
        parserData->instanceNamePresent = true;
    };

instanceNameContent: instanceNameEmpty | instanceNameLaden;

instanceNameEmpty: GREATERTHAN INSTANCENAMEEND | ENDOFELEMENT;

instanceNameLaden: GREATERTHAN instanceNameBody INSTANCENAMEEND;

instanceNameBody:  ELEMENTTEXT  
    {
        if (osoption->setInstanceName($1) == false) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setInstanceName failed");
        free($1); 
        parserData->errorText = NULL;
    };


/* -------------------------------------------- */
instanceLocation: instanceLocationStart instanceLocationAttributes instanceLocationContent
{
    if (osoption->setInstanceLocation(parserData->tempStr,parserData->typeAttribute) == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setInstanceLocation failed");
    parserData->errorText = NULL;
};

instanceLocationStart:  INSTANCELOCATIONSTART 
    {
        if (parserData->instanceLocationPresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated element: <instanceLocation>");
        parserData->instanceLocationPresent = true;
        parserData->typeAttribute = "local";
    };

instanceLocationAttributes: 
    | locationTypeAttribute
    {   
        if (verifyLocationType(parserData->typeAttribute) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "instance location type not recognized");
        parserData->errorText = NULL;
    };

locationTypeAttribute: LOCATIONTYPEATT ATTRIBUTETEXT QUOTE 
{ 
    parserData->typeAttribute = $2; 
    free($2);
};

instanceLocationContent: instanceLocationEmpty | instanceLocationLaden;

instanceLocationEmpty: GREATERTHAN INSTANCELOCATIONEND | ENDOFELEMENT;

instanceLocationLaden: GREATERTHAN instanceLocationBody INSTANCELOCATIONEND;

instanceLocationBody:  ELEMENTTEXT  
    {    
        parserData->tempStr = $1;
        free($1); 
    };


/* -------------------------------------------- */
jobID: jobIDStart jobIDContent;

jobIDStart: JOBIDSTART 
    {    if (parserData->jobIDPresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated element: <jobID>");
        parserData->jobIDPresent = true;
    };
    
jobIDContent: jobIDEmpty | jobIDLaden;

jobIDEmpty: GREATERTHAN JOBIDEND | ENDOFELEMENT;

jobIDLaden: GREATERTHAN jobIDBody JOBIDEND;

jobIDBody:  ELEMENTTEXT  
    {
        if (osoption->setJobID($1) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setJobID failed");
        free($1); 
        parserData->errorText = NULL;
    };

/* -------------------------------------------- */
solverToInvoke: solverToInvokeStart solverToInvokeContent;

solverToInvokeStart: SOLVERTOINVOKESTART 
    {
        if (parserData->solverToInvokePresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated element: <solverToInvoke>");
        parserData->solverToInvokePresent = true;
    };

solverToInvokeContent: solverToInvokeEmpty | solverToInvokeLaden;

solverToInvokeEmpty: GREATERTHAN SOLVERTOINVOKEEND | ENDOFELEMENT;

solverToInvokeLaden: GREATERTHAN solverToInvokeBody SOLVERTOINVOKEEND;

solverToInvokeBody:  ELEMENTTEXT  
    {
        if (osoption->setSolverToInvoke($1) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setSolverToInvoke failed");
        free($1); 
        parserData->errorText = NULL;
    };


/* -------------------------------------------- */
license: licenseStart licenseContent;

licenseStart: LICENSESTART
{
    if (parserData->licensePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated element: <license>");
    parserData->licensePresent = true;    
};

licenseContent: licenseEmpty | licenseLaden;

licenseEmpty: GREATERTHAN LICENSEEND | ENDOFELEMENT;

licenseLaden: GREATERTHAN licensebody LICENSEEND;

licensebody: ELEMENTTEXT 
    {
        if (osoption->setLicense($1) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setLicense failed");
        free($1);
        parserData->errorText = NULL;
    };


/* -------------------------------------------- */
username: usernameStart usernameContent;

usernameStart: USERNAMESTART
{    if (parserData->usernamePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated element: <username>");
    parserData->usernamePresent = true;    
};

usernameContent: usernameEmpty | usernameLaden;

usernameEmpty: GREATERTHAN USERNAMEEND | ENDOFELEMENT;

usernameLaden: GREATERTHAN usernamebody USERNAMEEND;

usernamebody: ELEMENTTEXT 
    {
        if (osoption->setUserName($1) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setUsername failed");
        free($1); 
        parserData->errorText = NULL;
    };


/* -------------------------------------------- */
password: passwordStart passwordContent;

passwordStart: PASSWORDSTART
{    if (parserData->passwordPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated element: <password>");
    parserData->passwordPresent = true;    
};

passwordContent: passwordEmpty | passwordLaden;

passwordEmpty: GREATERTHAN PASSWORDEND | ENDOFELEMENT;

passwordLaden: GREATERTHAN passwordbody PASSWORDEND;

passwordbody: ELEMENTTEXT 
    {
        if (osoption->setPassword($1) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setPassword failed");
        free($1); 
        parserData->errorText = NULL;
    };


/* -------------------------------------------- */
contact: contactStart contactAttributes contactContent
{
    if (osoption->setContact(parserData->tempStr,parserData->typeAttribute) == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setContact failed");
    parserData->errorText = NULL;
};

contactStart: CONTACTSTART
{
    if (parserData->contactPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated element: <contact>");
    parserData->contactPresent = true;
    parserData->typeAttribute = "osp";
    parserData->tempStr = "";
};

contactAttributes: 
    | transportTypeAttribute
    {   
        if (verifyTransportType(parserData->typeAttribute) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "transport type not recognized");
    };

transportTypeAttribute: TRANSPORTTYPEATT ATTRIBUTETEXT QUOTE 
    { 
        parserData->typeAttribute = $2; 
        free($2);
    };


contactContent: contactContentEmpty | contactContentLaden;

contactContentEmpty: GREATERTHAN CONTACTEND | ENDOFELEMENT;

contactContentLaden: GREATERTHAN contactBody CONTACTEND;

contactBody: ELEMENTTEXT
    {
        parserData->tempStr = $1;
        free($1);
    };


/* -------------------------------------------- */
otherGeneralOptions: otherGeneralOptionsStart otherGeneralOptionsAttributes otherGeneralOptionsContent
    {
        parserData->suppressFurtherErrorMessages = false;
        parserData->ignoreDataAfterErrors = false;        
    };

otherGeneralOptionsStart: OTHEROPTIONSSTART
    {
        if (parserData->otherGeneralOptionsPresent)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated element: <general> <otherOptions>");
            parserData->ignoreDataAfterErrors = true;            
        }
        parserData->otherGeneralOptionsPresent = true;
    };

otherGeneralOptionsAttributes: numberOfOtherOptionsAttribute 
    {
        if (parserData->tempInt < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of other general options cannot be negative");
        parserData->numberOf = parserData->tempInt;
        parserData->kounter = 0;
    };

otherGeneralOptionsContent: 
    otherGeneralOptionsEmpty 
    {
        if (parserData->numberOf > 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected at least one <other> element");
    }  
  | otherGeneralOptionsLaden
    {
        if (parserData->kounter < parserData->numberOf - 1)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "fewer <other> elements than specified");
    };
    
otherGeneralOptionsEmpty: GREATERTHAN OTHEROPTIONSEND | ENDOFELEMENT;

otherGeneralOptionsLaden: GREATERTHAN otherGeneralOptionsBody OTHEROPTIONSEND;

otherGeneralOptionsBody:  otherGeneralOptionArray;


/* -------------------------------------------- */
otherGeneralOptionArray:  otherGeneralOption | otherGeneralOptionArray otherGeneralOption; 

otherGeneralOption: otherGeneralOptionStart otherGeneralAttributes otherGeneralEnd
    {    
        parserData->kounter++;
        if (!parserData->ignoreDataAfterErrors)
            if (osoption->setAnOtherGeneralOption(parserData->nameAttribute, parserData->valueAttribute, parserData->descriptionAttribute) == false)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setOtherGeneralOption failed");
    };    

otherGeneralOptionStart: OTHERSTART
{
    if (parserData->kounter >= parserData->numberOf)
    {
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <other> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    }
    parserData->nameAttributePresent = false;
    parserData->valueAttributePresent = false;
    parserData->descriptionAttributePresent = false;
    parserData->nameAttribute = "";
    parserData->valueAttribute = "";
    parserData->descriptionAttribute = "";
};

otherGeneralAttributes: otherGeneralAttList
{
    if (!parserData->nameAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<other> must have name attribute");
};    

otherGeneralAttList: | otherGeneralAttList otherGeneralAtt;

otherGeneralAtt: 
    nameAttribute
    {    if (parserData->nameAttribute.length() == 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "otherOption name cannot be empty");
    }
  | valueAttribute
  | descriptionAttribute
  ;

otherGeneralEnd: GREATERTHAN OTHEREND | ENDOFELEMENT;



/**
 * ========================================================== 
 * <system> element 
 * ==========================================================
 */
systemElement: | systemElementStart systemElementContent;

systemElementStart: SYSTEMSTART
{
    parserData->minDiskSpacePresent = false;    
    parserData->minMemoryPresent = false;
    parserData->minCPUSpeedPresent = false;
    parserData->minCPUNumberPresent = false;
    parserData->otherSystemOptionsPresent = false;
    osoption->system = new SystemOption();
};

systemElementContent: systemElementEmpty | systemElementLaden;

systemElementEmpty: GREATERTHAN SYSTEMEND | ENDOFELEMENT;

systemElementLaden: GREATERTHAN systemElementBody SYSTEMEND; 
          
systemElementBody:  systemElementList;
               
systemElementList:  systemChild | systemElementList systemChild; 

systemChild: 
    minDiskSpace 
  | minMemorySize 
  | minCPUSpeed 
  | minCPUNumber 
  | otherSystemOptions
  ;

/* -------------------------------------------- */
minDiskSpace: minDiskSpaceStart minDiskSpaceAttributes minDiskSpaceContent;

minDiskSpaceStart: MINDISKSPACESTART
    {    if (parserData->minDiskSpacePresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one minDiskSpace element allowed");
        parserData->minDiskSpacePresent = true;    
        parserData->unitAttributePresent = false;    
        parserData->descriptionAttributePresent = false;    
        parserData->unitAttribute = "byte";    
        parserData->descriptionAttribute = "";
    };

minDiskSpaceAttributes: minDiskSpaceAttList;

minDiskSpaceAttList: | minDiskSpaceAttList minDiskSpaceAtt;

minDiskSpaceAtt: 
    unitAttribute
  | descriptionAttribute
  ;
  
minDiskSpaceContent: GREATERTHAN minDiskSpaceValue MINDISKSPACEEND;

minDiskSpaceValue: aNumber
{
    if (osoption->setMinDiskSpace(parserData->unitAttribute, parserData->descriptionAttribute, parserData->tempVal) == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setMinDiskSpace failed");
    parserData->errorText = NULL;
};

/* -------------------------------------------- */
minMemorySize: minMemoryStart minMemoryAttributes minMemoryContent;

minMemoryStart: MINMEMORYSTART
    {    if (parserData->minMemoryPresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one minMemory element allowed");
        parserData->minMemoryPresent = true;
        parserData->unitAttributePresent = false;    
        parserData->descriptionAttributePresent = false;    
        parserData->unitAttribute = "byte";    
        parserData->descriptionAttribute = "";
    };

minMemoryAttributes: minMemoryAttList;

minMemoryAttList: | minMemoryAttList minMemoryAtt;

minMemoryAtt: 
    unitAttribute 
  | descriptionAttribute
  ;

minMemoryContent: GREATERTHAN minMemoryValue MINMEMORYEND;

minMemoryValue: aNumber
{
    if (osoption->setMinMemorySize(parserData->unitAttribute, parserData->descriptionAttribute, parserData->tempVal) == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setMinMemorySize failed");
    parserData->errorText = NULL;
};


/* -------------------------------------------- */
minCPUSpeed: minCPUSpeedStart minCPUSpeedAttributes minCPUSpeedContent;

minCPUSpeedStart: MINCPUSPEEDSTART
    {    if (parserData->minCPUSpeedPresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one minCPUSpeed element allowed");
        parserData->minCPUSpeedPresent = true;
        parserData->unitAttributePresent = false;    
        parserData->descriptionAttributePresent = false;    
        parserData->unitAttribute = "hertz";    
        parserData->descriptionAttribute = "";
    };

minCPUSpeedAttributes: minCPUSpeedAttList;

minCPUSpeedAttList: | minCPUSpeedAttList minCPUSpeedAtt;

minCPUSpeedAtt: 
    unitAttribute 
  | descriptionAttribute
  ;

minCPUSpeedContent: GREATERTHAN minCPUSpeedValue MINCPUSPEEDEND;

minCPUSpeedValue: aNumber
{    
    if (osoption->setMinCPUSpeed(parserData->unitAttribute, parserData->descriptionAttribute, parserData->tempVal) == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setMinCPUSpeed failed");
    parserData->errorText = NULL;
};


/* -------------------------------------------- */
minCPUNumber: minCPUNumberStart minCPUNumberAttributes minCPUNumberContent;

minCPUNumberStart: MINCPUNUMBERSTART
    {    if (parserData->minCPUNumberPresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one minCPUNumber element allowed");
        parserData->minCPUNumberPresent = true;
        parserData->descriptionAttributePresent = false;    
        parserData->descriptionAttribute = "";    
    };

minCPUNumberAttributes: 
  | descriptionAttribute;

minCPUNumberContent: GREATERTHAN minCPUNumberValue MINCPUNUMBEREND;

minCPUNumberValue: INTEGER 
{
    if (osoption->setMinCPUNumber($1, parserData->descriptionAttribute) == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setMinCPUNumber failed");
    //free($1); 
    parserData->errorText = NULL; 
};



/* -------------------------------------------- */
otherSystemOptions: otherSystemOptionsStart otherSystemOptionsAttributes otherSystemOptionsContent
    {
        parserData->suppressFurtherErrorMessages = false;
        parserData->ignoreDataAfterErrors = false;        
    };

otherSystemOptionsStart: OTHEROPTIONSSTART
{
    if (parserData->otherSystemOptionsPresent)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated element: <system> <otherOptions>");
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->otherSystemOptionsPresent = true;
};

otherSystemOptionsAttributes: numberOfOtherOptionsAttribute
{
    if (parserData->tempInt < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of other system options cannot be negative");
    parserData->numberOf = parserData->tempInt;
    parserData->kounter = 0;
};

otherSystemOptionsContent: 
    otherSystemOptionsEmpty
    {    if (parserData->numberOf > 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected at least one <other> element");
    }
  | otherSystemOptionsLaden
    {    if (parserData->kounter < parserData->numberOf - 1)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "fewer <other> elements than specified");
    };

otherSystemOptionsEmpty: GREATERTHAN OTHEROPTIONSEND | ENDOFELEMENT;

otherSystemOptionsLaden: GREATERTHAN otherSystemOptionsBody OTHEROPTIONSEND;

otherSystemOptionsBody:  otherSystemOptionArray;


/* -------------------------------------------- */
otherSystemOptionArray:  otherSystemOption | otherSystemOptionArray otherSystemOption; 

otherSystemOption: otherSystemOptionStart otherSystemOptionAttributes otherSystemOptionEnd
    {
        parserData->kounter++;
        if (!parserData->ignoreDataAfterErrors)
            if (osoption->setAnOtherSystemOption(parserData->nameAttribute, parserData->valueAttribute, parserData->descriptionAttribute) == false)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setOtherSystemOption failed");
    };

otherSystemOptionStart: OTHERSTART
{
    if (parserData->kounter >= parserData->numberOf)
    {
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <other> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    }
    parserData->nameAttributePresent = false;
    parserData->valueAttributePresent = false;
    parserData->descriptionAttributePresent = false;
    parserData->nameAttribute = "";
    parserData->valueAttribute = "";
    parserData->descriptionAttribute = "";
};

otherSystemOptionAttributes: otherSystemOptionAttList
{    if (!parserData->nameAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<other> must have name attribute");
};
    
otherSystemOptionAttList: | otherSystemOptionAttList otherSystemOptionAtt;

otherSystemOptionAtt:
    nameAttribute
    {
        if (parserData->nameAttribute.length() == 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "otherOption name cannot be empty");
    }
  | valueAttribute
  | descriptionAttribute
  ;

otherSystemOptionEnd: GREATERTHAN OTHEREND | ENDOFELEMENT;



/**
 * ========================================================== 
 * <service> element 
 * ==========================================================
 */
serviceElement: | serviceElementStart serviceElementContent;

serviceElementStart: SERVICESTART
{
    parserData->serviceTypePresent = false;    
    parserData->otherServiceOptionsPresent = false;
    osoption->service = new ServiceOption();
};

serviceElementContent: serviceElementEmpty | serviceElementLaden;

serviceElementEmpty: GREATERTHAN SERVICEEND | ENDOFELEMENT; 

serviceElementLaden: GREATERTHAN serviceElementBody SERVICEEND;

serviceElementBody:  serviceElementList;
                
serviceElementList:  serviceChild | serviceElementList serviceChild;
        
serviceChild: 
    serviceType 
  | otherServiceOptions
  ;

/* -------------------------------------------- */
serviceType: serviceTypeStart serviceTypeContent;

serviceTypeStart: SERVICETYPESTART
    {    if (parserData->serviceTypePresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one currentState element allowed");
        parserData->serviceTypePresent = true;
    };

serviceTypeContent: serviceTypeEmpty | serviceTypeLaden;

serviceTypeEmpty: GREATERTHAN SERVICETYPEEND | ENDOFELEMENT;

serviceTypeLaden: GREATERTHAN serviceTypeBody SERVICETYPEEND;

serviceTypeBody:  ELEMENTTEXT  
    {
        parserData->tempStr = $1; 
        free($1);
        if (osoption->setServiceType(parserData->tempStr) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setServiceType failed; current system state not recognized");
        parserData->errorText = NULL;
    };


/* -------------------------------------------- */
otherServiceOptions: otherServiceOptionsStart otherServiceOptionsAttributes otherServiceOptionsContent
    {
        parserData->suppressFurtherErrorMessages = false;
        parserData->ignoreDataAfterErrors = false;        
    };

otherServiceOptionsStart: OTHEROPTIONSSTART
{
    if (parserData->otherServiceOptionsPresent)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated element: <service> <otherOptions>");
            parserData->ignoreDataAfterErrors = true;            
        }
    parserData->otherServiceOptionsPresent = true;
};

otherServiceOptionsAttributes: numberOfOtherOptionsAttribute
{
    if (parserData->tempInt < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of other service options cannot be negative");
    parserData->numberOf = parserData->tempInt;
    parserData->kounter = 0;
};

otherServiceOptionsContent: 
    otherServiceOptionsEmpty
    {    if (parserData->numberOf > 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected at least one <other> element");
    }
  | otherServiceOptionsLaden
    {    if (parserData->kounter < parserData->numberOf - 1)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "fewer <other> elements than specified");
    };

otherServiceOptionsEmpty: GREATERTHAN OTHEROPTIONSEND | ENDOFELEMENT;

otherServiceOptionsLaden: GREATERTHAN otherServiceOptionsBody OTHEROPTIONSEND

otherServiceOptionsBody:  otherServiceOptionArray;


/* -------------------------------------------- */
otherServiceOptionArray: otherServiceOption | otherServiceOptionArray otherServiceOption; 

otherServiceOption: otherServiceOptionStart otherServiceOptionAttributes otherServiceOptionEnd
    {    
        parserData->kounter++;
        if (!parserData->ignoreDataAfterErrors)
            if (osoption->setAnOtherServiceOption(parserData->nameAttribute, parserData->valueAttribute, parserData->descriptionAttribute) == false)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setOtherServiceOption failed");
    };

otherServiceOptionStart: OTHERSTART
{
    if (parserData->kounter >= parserData->numberOf)
    {
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <other> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    }
    parserData->nameAttributePresent = false;
    parserData->valueAttributePresent = false;
    parserData->descriptionAttributePresent = false;
    parserData->nameAttribute = "";
    parserData->valueAttribute = "";
    parserData->descriptionAttribute = "";
};

otherServiceOptionAttributes: otherServiceOptionAttList
{    if (!parserData->nameAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<other> must have name attribute");
};
    
otherServiceOptionAttList: | otherServiceOptionAttList otherServiceOptionAtt;

otherServiceOptionAtt: 
    nameAttribute 
    {
        if (parserData->nameAttribute.length() == 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "otherOption name cannot be empty");
    }
  | valueAttribute 
  | descriptionAttribute
  ;
  
otherServiceOptionEnd: GREATERTHAN OTHEREND | ENDOFELEMENT;


/**
 * ========================================================== 
 * <job> element 
 * ==========================================================
 */
jobElement: | jobElementStart jobElementContent;

jobElementStart: JOBSTART
{
    parserData->maxTimePresent = false;    
    parserData->requestedStartTimePresent = false;    
    parserData->dependenciesPresent = false;    
    parserData->requiredDirectoriesPresent = false;    
    parserData->requiredFilesPresent = false;    
    parserData->directoriesToMakePresent = false;    
    parserData->filesToMakePresent = false;    
    parserData->inputDirectoriesToMovePresent = false;    
    parserData->inputFilesToMovePresent = false;    
    parserData->outputDirectoriesToMovePresent = false;    
    parserData->outputFilesToMovePresent = false;    
    parserData->filesToDeletePresent = false;    
    parserData->directoriesToDeletePresent = false;    
    parserData->processesToKillPresent = false;    
    parserData->otherJobOptionsPresent = false;     
    osoption->job = new JobOption();
 };

jobElementContent: jobElementEmpty | jobElementLaden;

jobElementEmpty: GREATERTHAN JOBEND | ENDOFELEMENT;

jobElementLaden: GREATERTHAN jobElementBody JOBEND;

jobElementBody:  jobElementList;

jobElementList:  jobChild | jobElementList jobChild;

jobChild: 
    maxTime 
  | requestedStartTime 
  | dependencies 
  | requiredDirectories 
  | requiredFiles
  | directoriesToMake 
  | filesToMake 
  | inputDirectoriesToMove 
  | inputFilesToMove 
  | outputDirectoriesToMove
  | outputFilesToMove  
  | filesToDelete 
  | directoriesToDelete 
  | processesToKill 
  | otherJobOptions
  ;


/* -------------------------------------------- */
maxTime: maxTimeStart maxTimeAttributes maxTimeContent
{    
    if (osoption->setMaxTime(parserData->maxTimeValue, parserData->unitAttribute) == false)       
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "max time request could not be honored");
}; 

maxTimeStart: MAXTIMESTART
{    
    if (parserData->maxTimePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one <maxTime> element allowed");
    parserData->maxTimePresent = true;
    parserData->unitAttributePresent = false;    
    parserData->unitAttribute = "second"; 
    parserData->maxTimeValue = OSDBL_MAX;
};

maxTimeAttributes: |
           unitAttribute; 

maxTimeContent: maxTimeEmpty | maxTimeLaden;

maxTimeEmpty: GREATERTHAN MAXTIMEEND | ENDOFELEMENT;

maxTimeLaden: GREATERTHAN maxTimeBody MAXTIMEEND;

maxTimeBody:  maxTimeValue;

maxTimeValue: aNumber
{
    parserData->maxTimeValue = parserData->tempVal;
};


/* -------------------------------------------- */
requestedStartTime: requestedStartTimeStart requestedStartTimeContent;

requestedStartTimeStart: REQUESTEDSTARTTIMESTART 
    {    if (parserData->requestedStartTimePresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one requestedStartTime element allowed");
        parserData->requestedStartTimePresent = true;
    };

requestedStartTimeContent: requestedStartTimeEmpty | requestedStartTimeLaden;

requestedStartTimeEmpty: GREATERTHAN REQUESTEDSTARTTIMEEND | ENDOFELEMENT;

requestedStartTimeLaden: GREATERTHAN requestedStartTimeBody REQUESTEDSTARTTIMEEND;

requestedStartTimeBody:  ELEMENTTEXT  
    {
        if (osoption->setRequestedStartTime($1) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setRequestedStartTime failed");    
        free($1); 
        parserData->errorText = NULL;
        };


/* -------------------------------------------- */
dependencies: dependenciesStart dependenciesAttributes dependenciesContent
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setJobDependencies(parserData->numberOf, parserData->jobDependencies) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <job> <dependencies> failed");
    delete[] parserData->jobDependencies;
    parserData->jobDependencies = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

dependenciesStart: DEPENDENCIESSTART
{
    if (parserData->dependenciesPresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one <dependencies> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->dependenciesPresent = true;
};

dependenciesAttributes: numberOfJobIDsATT;

dependenciesContent: dependenciesEmpty | dependenciesLaden;

dependenciesEmpty: GREATERTHAN DEPENDENCIESEND | ENDOFELEMENT;

dependenciesLaden: GREATERTHAN dependenciesList DEPENDENCIESEND
{
    if (parserData->kounter < parserData->numberOf)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few job IDs in <dependencies> element");
        parserData->ignoreDataAfterErrors = true;        
    }
};

dependenciesList: dependencyJobID | dependenciesList dependencyJobID;

dependencyJobID: JOBIDSTART GREATERTHAN ELEMENTTEXT JOBIDEND
{
    if (parserData->kounter >= parserData->numberOf)
    {
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too many job IDs in <dependencies> element");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    }
    else
    {
        parserData->jobDependencies[parserData->kounter] = $3;
        parserData->kounter++;
    }
    free($3); 
};


/* -------------------------------------------- */
requiredDirectories: requiredDirectoriesStart numberOfPathsAttribute requiredDirectoriesContent
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setRequiredDirectories(parserData->numberOf,parserData->paths) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <requiredDirectories> failed");
    delete[] parserData->paths;
    parserData->paths = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

requiredDirectoriesStart: REQUIREDDIRECTORIESSTART
{
    if (parserData->requiredDirectoriesPresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one <requiredDirectories> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->requiredDirectoriesPresent = true;
};

requiredDirectoriesContent: requiredDirectoriesEmpty | requiredDirectoriesLaden;

requiredDirectoriesEmpty: GREATERTHAN REQUIREDDIRECTORIESEND | ENDOFELEMENT;

requiredDirectoriesLaden: GREATERTHAN PathList REQUIREDDIRECTORIESEND
{
    if (parserData->kounter < parserData->numberOf)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few paths in <requiredDirectories> element");
        parserData->ignoreDataAfterErrors = true;        
    }
};


/* -------------------------------------------- */
requiredFiles: requiredFilesStart numberOfPathsAttribute requiredFilesContent
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setRequiredFiles(parserData->numberOf, parserData->paths) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <requiredFiles> failed");
    delete[] parserData->paths;
    parserData->paths = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

requiredFilesStart: REQUIREDFILESSTART
{
    if (parserData->requiredFilesPresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one <requiredFiles> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->requiredFilesPresent = true;
};

requiredFilesContent: requiredFilesEmpty | requiredFilesLaden;

requiredFilesEmpty: GREATERTHAN REQUIREDFILESEND | ENDOFELEMENT;

requiredFilesLaden: GREATERTHAN PathList REQUIREDFILESEND
{
    if (parserData->kounter < parserData->numberOf)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few paths in <requiredFiles> element");
        parserData->ignoreDataAfterErrors = true;        
    }
};


/* -------------------------------------------- */
directoriesToMake: directoriesToMakeStart numberOfPathsAttribute directoriesToMakeContent
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setDirectoriesToMake(parserData->numberOf, parserData->paths) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <directoriesToMake> failed");
    delete[] parserData->paths;
    parserData->paths = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

directoriesToMakeStart: DIRECTORIESTOMAKESTART
{
    if (parserData->directoriesToMakePresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one <directoriesToMake> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->directoriesToMakePresent = true;
};

directoriesToMakeContent: directoriesToMakeEmpty | directoriesToMakeLaden;

directoriesToMakeEmpty: GREATERTHAN DIRECTORIESTOMAKEEND | ENDOFELEMENT;

directoriesToMakeLaden: GREATERTHAN PathList DIRECTORIESTOMAKEEND
{
    if (parserData->kounter < parserData->numberOf)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few paths in <directoriesToMake> element");
        parserData->ignoreDataAfterErrors = true;        
    }
};


/* -------------------------------------------- */
filesToMake: filesToMakeStart numberOfPathsAttribute filesToMakeContent
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setFilesToMake(parserData->numberOf, parserData->paths) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <filesToMake> failed");
    delete[] parserData->paths;
    parserData->paths = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

filesToMakeStart: FILESTOMAKESTART
{
    if (parserData->filesToMakePresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one <filesToMake> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->filesToMakePresent = true;
};

filesToMakeContent: filesToMakeEmpty | filesToMakeLaden;

filesToMakeEmpty: GREATERTHAN FILESTOMAKEEND | ENDOFELEMENT;

filesToMakeLaden: GREATERTHAN PathList FILESTOMAKEEND
{
    if (parserData->kounter < parserData->numberOf)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few paths in <filesToMake> element");
        parserData->ignoreDataAfterErrors = true;        
    }
};


/* -------------------------------------------- */
inputDirectoriesToMove: inputDirectoriesToMoveStart inputDirectoriesToMoveAttributes inputDirectoriesToMoveContent
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setPathPairs(ENUM_PATHPAIR_input_dir, parserData->fromPaths, 
                parserData->toPaths, parserData->makeCopy, parserData->numberOfPathPairs) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <inputDirectoriesToMove> failed");
    delete[] parserData->fromPaths;
    delete[] parserData->toPaths;
    delete[] parserData->makeCopy;
    parserData->fromPaths = NULL;
    parserData->toPaths   = NULL;
    parserData->makeCopy  = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;
};

inputDirectoriesToMoveStart: INPUTDIRECTORIESTOMOVESTART
{
    if (parserData->inputDirectoriesToMovePresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one <inputDirectoriesToMove> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->inputDirectoriesToMovePresent = true;
};

inputDirectoriesToMoveAttributes: numberOfPathPairsAttribute;

inputDirectoriesToMoveContent: inputDirectoriesToMoveEmpty | inputDirectoriesToMoveLaden;

inputDirectoriesToMoveEmpty: GREATERTHAN INPUTDIRECTORIESTOMOVEEND | ENDOFELEMENT;

inputDirectoriesToMoveLaden: GREATERTHAN inputDirectoriesToMoveList INPUTDIRECTORIESTOMOVEEND
{
    if (parserData->kounter < parserData->numberOfPathPairs)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few path pairs in <inputDirectoriesToMove> element");
        parserData->ignoreDataAfterErrors = true;        
    }
};

inputDirectoriesToMoveList: inputDirectoryToMove | inputDirectoriesToMoveList inputDirectoryToMove;

inputDirectoryToMove: PathPair;


/* -------------------------------------------- */
inputFilesToMove: inputFilesToMoveStart inputFilesToMoveAttributes inputFilesToMoveContent
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setPathPairs(ENUM_PATHPAIR_input_file, parserData->fromPaths, 
                parserData->toPaths, parserData->makeCopy, parserData->numberOfPathPairs) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <inputFilesToMove> failed");
    delete[] parserData->fromPaths;
    delete[] parserData->toPaths;
    delete[] parserData->makeCopy;
    parserData->fromPaths = NULL;
    parserData->toPaths   = NULL;
    parserData->makeCopy  = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

inputFilesToMoveStart: INPUTFILESTOMOVESTART
{
    if (parserData->inputFilesToMovePresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one <inputFilesToMove> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->inputFilesToMovePresent = true;
};

inputFilesToMoveAttributes: numberOfPathPairsAttribute;

inputFilesToMoveContent: inputFilesToMoveEmpty | inputFilesToMoveLaden;

inputFilesToMoveEmpty: GREATERTHAN INPUTFILESTOMOVEEND | ENDOFELEMENT;

inputFilesToMoveLaden: GREATERTHAN inputFilesToMoveList INPUTFILESTOMOVEEND
{
    if (parserData->kounter < parserData->numberOfPathPairs)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few path pairs in <inputFilesToMove> element");
        parserData->ignoreDataAfterErrors = true;        
    }
};

inputFilesToMoveList: inputFileToMove | inputFilesToMoveList inputFileToMove;

inputFileToMove: PathPair;


/* -------------------------------------------- */
outputFilesToMove: outputFilesToMoveStart outputFilesToMoveAttributes outputFilesToMoveContent
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setPathPairs(ENUM_PATHPAIR_output_file, parserData->fromPaths, 
                parserData->toPaths, parserData->makeCopy, parserData->numberOfPathPairs) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <inputDirectoriesToMake> failed");
    delete[] parserData->fromPaths;
    delete[] parserData->toPaths;
    delete[] parserData->makeCopy;
    parserData->fromPaths = NULL;
    parserData->toPaths   = NULL;
    parserData->makeCopy  = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

outputFilesToMoveStart: OUTPUTFILESTOMOVESTART
{
    if (parserData->outputFilesToMovePresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one <outputFilesToMove> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->outputFilesToMovePresent = true;
};

outputFilesToMoveAttributes: numberOfPathPairsAttribute;

outputFilesToMoveContent: outputFilesToMoveEmpty | outputFilesToMoveLaden;

outputFilesToMoveEmpty: GREATERTHAN OUTPUTFILESTOMOVEEND | ENDOFELEMENT;

outputFilesToMoveLaden: GREATERTHAN outputFilesToMoveList OUTPUTFILESTOMOVEEND
{
    if (parserData->kounter < parserData->numberOfPathPairs)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few path pairs in <outputFilesToMake> element");
        parserData->ignoreDataAfterErrors = true;        
    }
};

outputFilesToMoveList: outputFileToMove | outputFilesToMoveList outputFileToMove;

outputFileToMove: PathPair;


/* -------------------------------------------- */
outputDirectoriesToMove: outputDirectoriesToMoveStart outputDirectoriesToMoveAttributes outputDirectoriesToMoveContent
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setPathPairs(ENUM_PATHPAIR_output_dir, parserData->fromPaths, 
                parserData->toPaths, parserData->makeCopy, parserData->numberOfPathPairs) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <inputDirectoriesToMake> failed");
    delete[] parserData->fromPaths;
    delete[] parserData->toPaths;
    delete[] parserData->makeCopy;
    parserData->fromPaths = NULL;
    parserData->toPaths   = NULL;
    parserData->makeCopy  = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

outputDirectoriesToMoveStart: OUTPUTDIRECTORIESTOMOVESTART
{
    if (parserData->outputDirectoriesToMovePresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one <outputDirectoriesToMove> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->outputDirectoriesToMovePresent = true;
};

outputDirectoriesToMoveAttributes: numberOfPathPairsAttribute;

outputDirectoriesToMoveContent: outputDirectoriesToMoveEmpty | outputDirectoriesToMoveLaden;

outputDirectoriesToMoveEmpty: GREATERTHAN OUTPUTDIRECTORIESTOMOVEEND | ENDOFELEMENT;

outputDirectoriesToMoveLaden: GREATERTHAN outputDirectoriesToMoveList OUTPUTDIRECTORIESTOMOVEEND
{
    if (parserData->kounter < parserData->numberOfPathPairs)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few path pairs in <outputDirectoriesToMake> element");
        parserData->ignoreDataAfterErrors = true;        
    }
};

outputDirectoriesToMoveList: outputDirectoryToMove | outputDirectoriesToMoveList outputDirectoryToMove;

outputDirectoryToMove: PathPair;


/* -------------------------------------------- */
filesToDelete: filesToDeleteStart filesToDeleteAttributes filesToDeleteContent
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setFilesToDelete(parserData->numberOf, parserData->paths) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <filesToDelete> failed");
    delete[] parserData->paths;
    parserData->paths = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

filesToDeleteStart: FILESTODELETESTART
{
    if (parserData->filesToDeletePresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one <filesToDelete> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->filesToDeletePresent = true;
};

filesToDeleteAttributes: numberOfPathsAttribute;

filesToDeleteContent: filesToDeleteEmpty | filesToDeleteLaden;

filesToDeleteEmpty: GREATERTHAN FILESTODELETEEND | ENDOFELEMENT;

filesToDeleteLaden: GREATERTHAN PathList FILESTODELETEEND
{
    if (parserData->kounter < parserData->numberOf)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few paths in <filesToDelete> element");
        parserData->ignoreDataAfterErrors = true;        
    }
};


/* -------------------------------------------- */
directoriesToDelete: directoriesToDeleteStart directoriesToDeleteAttributes directoriesToDeleteContent
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setDirectoriesToDelete(parserData->numberOf, parserData->paths) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <directoriesToDelete> failed");
    delete[] parserData->paths;
    parserData->paths = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

directoriesToDeleteStart: DIRECTORIESTODELETESTART
{
    if (parserData->directoriesToDeletePresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one <directoriesToDelete> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->directoriesToDeletePresent = true;
};

directoriesToDeleteAttributes: numberOfPathsAttribute;

directoriesToDeleteContent: directoriesToDeleteEmpty | directoriesToDeleteLaden;

directoriesToDeleteEmpty: GREATERTHAN DIRECTORIESTODELETEEND | ENDOFELEMENT;

directoriesToDeleteLaden: GREATERTHAN PathList DIRECTORIESTODELETEEND
{
    if (parserData->kounter < parserData->numberOf)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few paths in <directoriesToDelete> element");
        parserData->ignoreDataAfterErrors = true;        
    }
};

/*
directoriesToDeleteList: directoryToDelete | directoriesToDeleteList directoryToDelete;

directoryToDelete: PATHSTART GREATERTHAN ELEMENTTEXT PATHEND
{
    if (parserData->kounter >= parserData->numberOf)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too many paths in <directoriesToDelete> element");
    else
    {
        parserData->paths[parserData->kounter] = $3;
        parserData->kounter++;
    }
    free($3); 
};
*/

/* -------------------------------------------- */
processesToKill: processesToKillStart processesToKillAttributes processesToKillContent
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setProcessesToKill(parserData->numberOf, parserData->processesToKill) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <processesToKill> failed");
    delete[] parserData->processesToKill;
    parserData->processesToKill = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

processesToKillStart: PROCESSESTOKILLSTART
{
    if (parserData->processesToKillPresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one <processesToKill> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->processesToKillPresent = true;
};

processesToKillAttributes: numberOfProcessesATT;

processesToKillContent: processesToKillEmpty | processesToKillLaden;

processesToKillEmpty: GREATERTHAN PROCESSESTOKILLEND | ENDOFELEMENT;

processesToKillLaden: GREATERTHAN processesToKillList PROCESSESTOKILLEND
{
    if (parserData->kounter < parserData->numberOf)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few process IDs in <processesToKill> element");
        parserData->ignoreDataAfterErrors = true;        
    }
};

processesToKillList: processID | processesToKillList processID;

processID: PROCESSSTART GREATERTHAN ELEMENTTEXT PROCESSEND
{
    if (parserData->kounter >= parserData->numberOf)
    {
    if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too many process IDs in <processesToKill> element");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    }
    else
    {
        parserData->processesToKill[parserData->kounter] = $3;
        parserData->kounter++;
    }
    free($3); 
};


/* -------------------------------------------- */
otherJobOptions: otherJobOptionsStart otherJobOptionsAttributes otherJobOptionsContent
    {
        parserData->suppressFurtherErrorMessages = false;
        parserData->ignoreDataAfterErrors = false;        
    };

otherJobOptionsStart: OTHEROPTIONSSTART
{
    if (parserData->otherJobOptionsPresent)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated element: <job> <otherOptions>");
            parserData->ignoreDataAfterErrors = true;            
        }
    parserData->otherJobOptionsPresent = true;
};

otherJobOptionsAttributes: numberOfOtherOptionsAttribute 
{
    if (parserData->tempInt < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of other job options cannot be negative");
    parserData->numberOf = parserData->tempInt;
    parserData->kounter = 0;
};

otherJobOptionsContent: 
    otherJobOptionsEmpty
    {    if (parserData->numberOf > 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected at least one <other> element");
    }
  | otherJobOptionsLaden
    {    if (parserData->kounter < parserData->numberOf - 1)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "fewer <other> elements than specified");
    };

otherJobOptionsEmpty: GREATERTHAN OTHEROPTIONSEND | ENDOFELEMENT;

otherJobOptionsLaden: GREATERTHAN otherJobOptionsBody OTHEROPTIONSEND;

otherJobOptionsBody:   otherJobOptionArray;


/* -------------------------------------------- */
otherJobOptionArray: otherJobOption | otherJobOptionArray otherJobOption; 

otherJobOption: otherJobOptionStart otherJobOptionAttributes otherJobOptionEnd
    {
        parserData->kounter++;
        if (!parserData->ignoreDataAfterErrors)
            if (osoption->setAnOtherJobOption(parserData->nameAttribute, parserData->valueAttribute, parserData->descriptionAttribute) == false)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setOtherJobOption failed");
    };    

otherJobOptionStart: OTHERSTART
{
    if (parserData->kounter >= parserData->numberOf)
    {
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <other> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    }
    parserData->nameAttributePresent = false;
    parserData->valueAttributePresent = false;
    parserData->descriptionAttributePresent = false;
    parserData->nameAttribute = "";
    parserData->valueAttribute = "";
    parserData->descriptionAttribute = "";
};

otherJobOptionAttributes: otherJobOptionAttList
{
    if (!parserData->nameAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<other> must have name attribute");
};

otherJobOptionAttList: | otherJobOptionAttList otherJobOptionAtt;

otherJobOptionAtt: 
    nameAttribute 
    {
        if (parserData->nameAttribute.length() == 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "otherOption name cannot be empty");
    }
  | valueAttribute 
  | descriptionAttribute
  ;

otherJobOptionEnd: GREATERTHAN OTHEREND | ENDOFELEMENT;


/**
 * ========================================================== 
 * <optimization> element 
 * ==========================================================
 */
optimizationElement: | optimizationStart optimizationAttributes optimizationContent;

optimizationStart: OPTIMIZATIONSTART
{
    osoption->optimization = new OptimizationOption();
    parserData->numberOfVariablesPresent = false;
    parserData->numberOfObjectivesPresent = false;
    parserData->numberOfConstraintsPresent = false;
};

optimizationAttributes: optimizationAttList

optimizationAttList: | optimizationAttList optimizationATT; 

optimizationATT: 
    numberOfVariablesAttribute 
    {    
        parserData->numberOfVariables = parserData->tempInt; 
        if (osoption->setNumberOfVariables(parserData->tempInt) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setNumberOfVariables failed");
    }             
  | numberOfConstraintsAttribute 
    {
        parserData->numberOfConstraints = parserData->tempInt; 
        if (osoption->setNumberOfConstraints(parserData->tempInt) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setNumberOfConstraints failed");
    } 
  | numberOfObjectivesAttribute 
    {    
        parserData->numberOfObjectives = parserData->tempInt; 
        if (osoption->setNumberOfObjectives(parserData->tempInt) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setNumberOfObjectives failed");
    };


optimizationContent: optimizationEmpty | optimizationLaden;

optimizationEmpty: ENDOFELEMENT;

optimizationLaden: GREATERTHAN optimizationBody OPTIMIZATIONEND;

optimizationBody: variables objectives constraints solverOptions;

/**
 * ========================================================== 
 * <optimization> <variables> 
 * ==========================================================
 */
variables: | variablesStart variablesAttributes variablesContent;

variablesStart: VARIABLESSTART
{
    parserData->numberOfOtherVariableOptions = 0;
    osoption->optimization->variables = new VariableOption();
};

variablesAttributes: numberOfOtherVariableOptions
{    
    if (osoption->setNumberOfOtherVariableOptions(parserData->numberOfOtherVariableOptions) == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setNumberOfOtherVariableOptions failed");
    parserData->iOther = 0;
};

numberOfOtherVariableOptions: | numberOfOtherVariableOptionsAttribute
{    
    parserData->numberOfOtherVariableOptions = parserData->tempInt;
};

variablesContent: variablesEmpty | variablesLaden;

variablesEmpty: ENDOFELEMENT;

variablesLaden: GREATERTHAN variablesBody VARIABLESEND;

variablesBody:  initialVariableValues initialVariableValuesString variableInitialBasis 
    integerVariableBranchingWeights sosVariableBranchingWeights otherVariableOptionsArray
{
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        

};


/* -------------------------------------------- */
initialVariableValues: | initialVariableValuesStart initialVariableValuesAttributes initialVariableValuesContent
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitVarValues(parserData->numberOfVar, parserData->idxArray, parserData->valArray, parserData->namArray) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <initialVariableValues> failed");
    delete[] parserData->idxArray;
    delete[] parserData->namArray;
    delete[] parserData->valArray;
    parserData->idxArray = NULL;
    parserData->namArray = NULL;
    parserData->valArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

initialVariableValuesStart: INITIALVARIABLEVALUESSTART
{
    parserData->numberOfVarAttributePresent = false;
};

initialVariableValuesAttributes: numberOfVarAttribute 
{
    parserData->kounter = 0;
    parserData->idxArray = new         int[parserData->numberOfVar];
    parserData->namArray = new std::string[parserData->numberOfVar];
    parserData->valArray = new      double[parserData->numberOfVar];
    for (int i=0; i < parserData->numberOfVar; i++) parserData->namArray[i] = "";
    for (int i=0; i < parserData->numberOfVar; i++) parserData->valArray[i] = OSNaN();
}; 

initialVariableValuesContent: 
    initialVariableValuesEmpty 
    {
        if (parserData->numberOfVar > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<initialVariableValues>: expected at least one <var> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
  | initialVariableValuesLaden
    {
        if (parserData->kounter < parserData->numberOfVar)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<initialVariableValues>: fewer <var> elements than specified");
            parserData->ignoreDataAfterErrors = true;        
        }
    };

initialVariableValuesEmpty: GREATERTHAN INITIALVARIABLEVALUESEND | ENDOFELEMENT;

initialVariableValuesLaden: GREATERTHAN initialVariableValuesBody INITIALVARIABLEVALUESEND;

initialVariableValuesBody:  initVarValueArray;

initVarValueArray: initVarValue | initVarValueArray initVarValue;

/* -------------------------------------------- */
initVarValue: initVarValueStart  initVarValueAttributes initVarValueContent
{
    parserData->kounter++;
}; 

initVarValueStart: VARSTART
{    
    if (parserData->kounter >= parserData->numberOfVar)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <var> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->idxAttributePresent = false;
    parserData->nameAttributePresent = false;
    parserData->valueAttributePresent = false;
};

initVarValueAttributes: initVarValueAttList
{
    if (parserData->idxAttributePresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<var> element must have idx attribute");
};

initVarValueAttList: | initVarValueAttList initVarValueAtt;

initVarValueAtt: 
    idxAttribute 
    {
        if (parserData->idxAttribute < 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "variable index must be nonnegative");
        if (osoption->optimization->numberOfVariables >= 0)
        {
            if (parserData->idxAttribute >= osoption->optimization->numberOfVariables)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "variable index exceeds upper limit");
        };
        if (!parserData->ignoreDataAfterErrors)
            parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
    }
  | nameAttribute
    {
        if (!parserData->ignoreDataAfterErrors)
            parserData->namArray[parserData->kounter] = parserData->nameAttribute;
    }
  | valueAttribute
    {
        if (parserData->valueAttribute == "")
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected an integer or floating point value");
        if (!parserData->ignoreDataAfterErrors)
            parserData->valArray[parserData->kounter] = os_strtod((parserData->valueAttribute).c_str(), NULL);
    };

initVarValueContent: GREATERTHAN VAREND | ENDOFELEMENT;


/* -------------------------------------------- */
initialVariableValuesString: | initialVariableValuesStringStart initialVariableValuesStringAttributes initialVariableValuesStringContent
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitVarValuesString(parserData->numberOfVar, parserData->idxArray, parserData->valueString, parserData->namArray) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <initialVariableValuesString> failed");
    delete[] parserData->idxArray;
    delete[] parserData->namArray;
    delete[] parserData->valueString;
    parserData->idxArray = NULL;
    parserData->namArray = NULL;
    parserData->valueString = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

initialVariableValuesStringStart: INITIALVARIABLEVALUESSTRINGSTART
{
    parserData->numberOfVarAttributePresent = false;
};

initialVariableValuesStringAttributes: numberOfVarAttribute 
{
    parserData->kounter = 0;
    parserData->idxArray    = new         int[parserData->numberOfVar];
    parserData->namArray    = new std::string[parserData->numberOfVar];
    parserData->valueString = new std::string[parserData->numberOfVar];
    for (int i=0; i < parserData->numberOfVar; i++) parserData->namArray[i] = "";
    for (int i=0; i < parserData->numberOfVar; i++) parserData->valueString[i] = "";
}; 

initialVariableValuesStringContent: 
    initialVariableValuesStringEmpty 
    {
        if (parserData->numberOfVar > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<initialVariableValuesString>: expected at least one <var> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
  | initialVariableValuesStringLaden
    {
        if (parserData->kounter < parserData->numberOfVar)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few initial values in <initialVariableValuesString> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    };

initialVariableValuesStringEmpty: GREATERTHAN INITIALVARIABLEVALUESSTRINGEND | ENDOFELEMENT;

initialVariableValuesStringLaden: GREATERTHAN initialVariableValuesStringBody INITIALVARIABLEVALUESSTRINGEND;

initialVariableValuesStringBody:  initVarValueStringArray;

initVarValueStringArray: initVarValueString | initVarValueStringArray initVarValueString;

/* -------------------------------------------- */
initVarValueString: initVarValueStringStart  initVarValueStringAttributes initVarValueStringContent
{
    parserData->kounter++;
}; 

initVarValueStringStart: VARSTART
{    
    if (parserData->kounter >= parserData->numberOfVar)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <var> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->idxAttributePresent = false;
    parserData->nameAttributePresent = false;
    parserData->valueAttributePresent = false;
    parserData->valueAttribute = "48r 87e WY EUV e7 df"; //random string...
};

initVarValueStringAttributes: initVarValueStringAttList
{
    if (parserData->idxAttributePresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<var> element must have idx attribute");
};

initVarValueStringAttList: | initVarValueStringAttList initVarValueStringAtt;

initVarValueStringAtt:
    idxAttribute 
    {
        if (parserData->idxAttribute < 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "variable index must be nonnegative");
        if (osoption->optimization->numberOfVariables >= 0)
        {
            if (parserData->idxAttribute >= osoption->optimization->numberOfVariables)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "variable index exceeds upper limit");
        };
        if (!parserData->ignoreDataAfterErrors)
            parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
    }
  | nameAttribute
    {
        if (!parserData->ignoreDataAfterErrors)
            parserData->namArray[parserData->kounter] = parserData->nameAttribute;
    }
  | valueAttribute
    {
        if (!parserData->ignoreDataAfterErrors)
            parserData->valueString[parserData->kounter] = parserData->valueAttribute;
    }
    
initVarValueStringContent: GREATERTHAN VAREND | ENDOFELEMENT;


/* -------------------------------------------- */
variableInitialBasis: | variableInitialBasisStart variableInitialBasisContent;

variableInitialBasisStart: INITIALBASISSTATUSSTART
{
    osoption->optimization->variables->initialBasisStatus = new BasisStatus();
};

variableInitialBasisContent: variableInitialBasisEmpty | variableInitialBasisLaden;

variableInitialBasisEmpty: ENDOFELEMENT;

variableInitialBasisLaden: GREATERTHAN variableInitialBasisBody INITIALBASISSTATUSEND;

variableInitialBasisBody:  variablesBasic variablesAtLower variablesAtUpper variablesAtEquality variablesIsFree variablesSuperbasic variablesUnknown;

/* -------------------------------------------- */
variablesBasic: | variablesBasicStart variablesBasicNumberOfElATT variablesBasicContent
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set variables basic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

variablesBasicStart: BASICSTART
{
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
};

variablesBasicNumberOfElATT: numberOfElAttribute
{
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    if (parserData->numberOf > 0)
        osglData->osglIntArray = new int[parserData->numberOf];
}; 

variablesBasicContent: variablesBasicEmpty | variablesBasicLaden;

variablesBasicEmpty: ENDOFELEMENT;

variablesBasicLaden: GREATERTHAN variablesBasicBody BASICEND;

variablesBasicBody:  osglIntArrayData;


/* -------------------------------------------- */
variablesAtLower: | variablesAtLowerStart variablesAtLowerNumberOfElATT variablesAtLowerContent
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set variables atLower failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};


variablesAtLowerStart: ATLOWERSTART
{
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
};

variablesAtLowerNumberOfElATT: numberOfElAttribute
{
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    if (parserData->numberOf > 0)
        osglData->osglIntArray = new int[parserData->numberOf];
}; 

variablesAtLowerContent: variablesAtLowerEmpty | variablesAtLowerLaden;

variablesAtLowerEmpty: ENDOFELEMENT;

variablesAtLowerLaden: GREATERTHAN variablesAtLowerBody ATLOWEREND;

variablesAtLowerBody:  osglIntArrayData;


/* -------------------------------------------- */
variablesAtUpper: | variablesAtUpperStart variablesAtUpperNumberOfElATT variablesAtUpperContent
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set variables atUpper failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

variablesAtUpperStart: ATUPPERSTART
{
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
};

variablesAtUpperNumberOfElATT: numberOfElAttribute
{
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    if (parserData->numberOf > 0)
        osglData->osglIntArray = new int[parserData->numberOf];
}; 

variablesAtUpperContent: variablesAtUpperEmpty | variablesAtUpperLaden;

variablesAtUpperEmpty: ENDOFELEMENT;

variablesAtUpperLaden: GREATERTHAN variablesAtUpperBody ATUPPEREND;

variablesAtUpperBody:  osglIntArrayData;


/* -------------------------------------------- */
variablesAtEquality: | variablesAtEqualityStart variablesAtEqualityNumberOfElATT variablesAtEqualityContent
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atEquality, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set variables atEquality failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

variablesAtEqualityStart: ATEQUALITYSTART
{
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
};

variablesAtEqualityNumberOfElATT: numberOfElAttribute
{
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    if (parserData->numberOf > 0)
        osglData->osglIntArray = new int[parserData->numberOf];
}; 

variablesAtEqualityContent: variablesAtEqualityEmpty | variablesAtEqualityLaden;

variablesAtEqualityEmpty: ENDOFELEMENT;

variablesAtEqualityLaden: GREATERTHAN variablesAtEqualityBody ATEQUALITYEND;

variablesAtEqualityBody:  osglIntArrayData;


/* -------------------------------------------- */
variablesIsFree: | variablesIsFreeStart variablesIsFreeNumberOfElATT variablesIsFreeContent
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set variables isFree failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

variablesIsFreeStart: ISFREESTART
{
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
};

variablesIsFreeNumberOfElATT: numberOfElAttribute
{
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    if (parserData->numberOf > 0)
        osglData->osglIntArray = new int[parserData->numberOf];
}; 

variablesIsFreeContent: variablesIsFreeEmpty | variablesIsFreeLaden;

variablesIsFreeEmpty: ENDOFELEMENT;

variablesIsFreeLaden: GREATERTHAN variablesIsFreeBody ISFREEEND;

variablesIsFreeBody:  osglIntArrayData;


/* -------------------------------------------- */
variablesSuperbasic: | variablesSuperbasicStart variablesSuperbasicNumberOfElATT variablesSuperbasicContent
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set variables superbasic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

variablesSuperbasicStart: SUPERBASICSTART
{
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
};

variablesSuperbasicNumberOfElATT: numberOfElAttribute
{
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    if (parserData->numberOf > 0)
        osglData->osglIntArray = new int[parserData->numberOf];
}; 

variablesSuperbasicContent: variablesSuperbasicEmpty | variablesSuperbasicLaden;

variablesSuperbasicEmpty: ENDOFELEMENT;

variablesSuperbasicLaden: GREATERTHAN variablesSuperbasicBody SUPERBASICEND;

variablesSuperbasicBody:  osglIntArrayData;


/* -------------------------------------------- */
variablesUnknown: | variablesUnknownStart variablesUnknownNumberOfElATT variablesUnknownContent
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set variables unknown failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

variablesUnknownStart: UNKNOWNSTART
{
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
};

variablesUnknownNumberOfElATT: numberOfElAttribute
{
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    if (parserData->numberOf > 0)
        osglData->osglIntArray = new int[parserData->numberOf];
}; 

variablesUnknownContent: variablesUnknownEmpty | variablesUnknownLaden;

variablesUnknownEmpty: ENDOFELEMENT;

variablesUnknownLaden: GREATERTHAN variablesUnknownBody UNKNOWNEND;

variablesUnknownBody:  osglIntArrayData;


/* -------------------------------------------- */
integerVariableBranchingWeights: | integerVariableBranchingWeightsStart
    integerVariableBranchingWeightsAttributes integerVariableBranchingWeightsContent
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setIntegerVariableBranchingWeights(parserData->numberOfVar, parserData->idxArray, parserData->valArray, parserData->namArray) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <initialVariableValues> failed");
    delete[] parserData->idxArray;
    delete[] parserData->namArray;
    delete[] parserData->valArray;
    parserData->idxArray = NULL;
    parserData->namArray = NULL;
    parserData->valArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

integerVariableBranchingWeightsStart: INTEGERVARIABLEBRANCHINGWEIGHTSSTART
{
    parserData->numberOfVarAttributePresent = false;
};

integerVariableBranchingWeightsAttributes: numberOfVarAttribute 
{
    parserData->kounter = 0;
    parserData->idxArray = new         int[parserData->numberOfVar];
    parserData->namArray = new std::string[parserData->numberOfVar];
    parserData->valArray = new      double[parserData->numberOfVar];
    for (int i=0; i < parserData->numberOfVar; i++) parserData->namArray[i] = "";
    for (int i=0; i < parserData->numberOfVar; i++) parserData->valArray[i] = OSNaN();
}; 

integerVariableBranchingWeightsContent:
    integerVariableBranchingWeightsEmpty
    {
        if (parserData->numberOfVar > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected at least one <var> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
  | integerVariableBranchingWeightsLaden
    {
        if (parserData->kounter < parserData->numberOfVar)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "fewer <var> elements than specified");
            parserData->ignoreDataAfterErrors = true;        
        }
    };

integerVariableBranchingWeightsEmpty: GREATERTHAN INTEGERVARIABLEBRANCHINGWEIGHTSEND | ENDOFELEMENT;

integerVariableBranchingWeightsLaden: GREATERTHAN integerVariableBranchingWeightsBody INTEGERVARIABLEBRANCHINGWEIGHTSEND;

integerVariableBranchingWeightsBody: branchingWeightsArray;


/* This code can be used in both <integerVariableBranchingWeights> and <sosBranchingWeights> <sos> 
   ------------------------------------------------------------------------------------------------*/
   
branchingWeightsArray: branchingWeight | branchingWeightsArray branchingWeight;

branchingWeight: branchingWeightStart branchingWeightAttributes branchingWeightContent
{
    parserData->kounter++;
}; 

branchingWeightStart: VARSTART
{    
    if (parserData->kounter >= parserData->numberOfVar)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <var> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->idxAttributePresent = false;
    parserData->nameAttributePresent = false;
    parserData->nameAttribute = "";
    parserData->valueAttributePresent = false;
    parserData->valueAttribute = "1.0";
};

branchingWeightAttributes: branchingWeightAttList
{
    if (parserData->idxAttributePresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<var> element must have idx attribute");
};

branchingWeightAttList: | branchingWeightAttList branchingWeightAtt;

branchingWeightAtt: 
    idxAttribute 
    {
        if (parserData->idxAttribute < 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "variable index must be nonnegative");
        if (osoption->optimization->numberOfVariables >= 0)
        {
            if (parserData->idxAttribute >= osoption->optimization->numberOfVariables)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "variable index exceeds upper limit");
        };
        if (!parserData->ignoreDataAfterErrors)
            parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
    }
  | nameAttribute
    {
        if (!parserData->ignoreDataAfterErrors)
            parserData->namArray[parserData->kounter] = parserData->nameAttribute;
    }
  | valueAttribute
    {
        if (parserData->valueAttribute == "")
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected an integer or floating point value");
        if (!parserData->ignoreDataAfterErrors)
            parserData->valArray[parserData->kounter] = os_strtod((parserData->valueAttribute).c_str(), NULL);
    };

branchingWeightContent: GREATERTHAN VAREND | ENDOFELEMENT;


/* -------------------------------------------- */
sosVariableBranchingWeights: | sosVariableBranchingWeightsStart sosVariableBranchingWeightsAttributes sosVariableBranchingWeightsContent
{
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

sosVariableBranchingWeightsStart: SOSVARIABLEBRANCHINGWEIGHTSSTART
{
    parserData->sosIdxAttributePresent = false;    
    parserData->currentSOS = 0;
}; 

sosVariableBranchingWeightsAttributes: NUMBEROFSOSATT QUOTE INTEGER QUOTE   
{
    if ($3 < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <sos> elements must be nonnegative");
    parserData->numberOfSOS = $3;
};

sosVariableBranchingWeightsContent:
    sosVariableBranchingWeightsEmpty
    {
        if (parserData->numberOfSOS > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected at least one <sos> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
  | sosVariableBranchingWeightsLaden
    {    if (parserData->currentSOS != parserData->numberOfSOS)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "fewer <sos> elements than specified");
            parserData->ignoreDataAfterErrors = true;        
        }
    };

sosVariableBranchingWeightsEmpty: GREATERTHAN SOSVARIABLEBRANCHINGWEIGHTSEND | ENDOFELEMENT;

sosVariableBranchingWeightsLaden: GREATERTHAN sosWeightGroupArray SOSVARIABLEBRANCHINGWEIGHTSEND;

sosWeightGroupArray: sosWeightGroup | sosWeightGroupArray sosWeightGroup;

sosWeightGroup: sosWeightGroupStart sosWeightGroupAttributes sosWeightGroupContent
{
    if (!parserData->ignoreDataAfterErrors)
        if (!osoption->setAnotherSOSVariableBranchingWeight(parserData->sosIdx, 
                    parserData->numberOfVar, parserData->groupWeight,
                    parserData->idxArray,     parserData->valArray, parserData->namArray) )
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "error processing SOS branching weights");
    delete[] parserData->idxArray;
    delete[] parserData->namArray;
    delete[] parserData->valArray;
    parserData->idxArray = NULL;
    parserData->namArray = NULL;
    parserData->valArray = NULL;
    parserData->currentSOS++;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};


sosWeightGroupStart: SOSSTART
{
    if (parserData->currentSOS >= parserData->numberOfSOS)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too many SOS branching weights");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->sosIdxAttributePresent = false;
    parserData->groupWeightAttributePresent = false;
    parserData->numberOfVarAttributePresent = false;
    parserData->groupWeight = 1.0;
    parserData->numberOfSOSVar = 0;
};

sosWeightGroupAttributes: sosWeightGroupAttList
{
    if (!parserData->sosIdxAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "SOS index required");
    if (!parserData->numberOfVarAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfVar required");
};

sosWeightGroupAttList: | sosWeightGroupAttList sosWeightGroupAtt; 

sosWeightGroupAtt: 
    sosIdxAttribute;
  | numberOfVarAttribute
    {
        parserData->kounter = 0;
        parserData->idxArray = new         int[parserData->numberOfVar];
        parserData->namArray = new std::string[parserData->numberOfVar];
        parserData->valArray = new      double[parserData->numberOfVar];
        for (int i=0; i < parserData->numberOfVar; i++) parserData->valArray[i] = OSNaN();
        parserData->numberOfVarAttributePresent = true;
    }
  | groupWeightAttribute
;

sosWeightGroupContent: sosWeightGroupEmpty | sosWeightGroupLaden;

sosWeightGroupEmpty:   GREATERTHAN SOSEND | ENDOFELEMENT;

sosWeightGroupLaden:   GREATERTHAN branchingWeightsArray SOSEND;



/* -------------------------------------------- */
otherVariableOptionsArray: | otherVariableOptionsArray otherVariableOption;

otherVariableOption: otherVariableOptionStart otherVariableOptionAttributes otherVariableOptionContent
    {      
        parserData->iOther++;
    };

otherVariableOptionStart: OTHERSTART
{
    if (parserData->iOther >= parserData->numberOfOtherVariableOptions)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <otherVariableOptions> than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->numberOfVarAttributePresent = false;
    parserData->numberOfVar = 0;
    parserData->numberOfEnumerationsAttributePresent = false;    
    parserData->numberOfEnumerations = 0;
    parserData->nameAttributePresent = false;    
    parserData->valueAttributePresent = false;    
    parserData->valueAttribute = "";
    parserData->solverAttributePresent = false;    
    parserData->solverAttribute = "";
    parserData->categoryAttributePresent = false;    
    parserData->categoryAttribute = "";
    parserData->typeAttributePresent = false;    
    parserData->typeAttribute = "";
    parserData->varTypeAttributePresent = false;    
    parserData->varTypeAttribute = "";
    parserData->enumTypeAttributePresent = false;    
    parserData->enumTypeAttribute = "";
    parserData->descriptionAttributePresent = false;    
    parserData->descriptionAttribute = "";    
    parserData->otherOptionType = ENUM_PROBLEM_COMPONENT_variables;
}; 

otherVariableOptionAttributes: otherVariableOptionAttList 
    {
        if (!parserData->nameAttributePresent) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<other> element requires name attribute"); 
        if (!parserData->ignoreDataAfterErrors)
            if (!osoption->setOtherVariableOptionAttributes(
                    parserData->iOther,
                    parserData->numberOfVar,
                    parserData->numberOfEnumerations,
                    parserData->nameAttribute,
                    parserData->valueAttribute,
                    parserData->solverAttribute,
                    parserData->categoryAttribute,
                    parserData->typeAttribute,
                    parserData->varTypeAttribute,
                    parserData->enumTypeAttribute,
                    parserData->descriptionAttribute) )
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<other> element could not be initialed"); 
    };
      
otherVariableOptionAttList: | otherVariableOptionAttList otherVariableOptionATT;

otherVariableOptionATT: 
    numberOfVarAttribute 
    {
        parserData->kounter = 0;
    }  
  | numberOfEnumerationsAttribute
    {
        parserData->kounter = 0;
    }  
  | nameAttribute 
  | valueAttribute
  | solverAttribute 
  | categoryAttribute 
  | typeAttribute 
  | varTypeAttribute 
  | enumTypeAttribute 
  | descriptionAttribute
  ;
  
otherVariableOptionContent: otherVariableOptionEmpty | otherVariableOptionLaden;

otherVariableOptionEmpty: GREATERTHAN OTHEREND | ENDOFELEMENT;

otherVariableOptionLaden: GREATERTHAN otherVariableOptionBody OTHEREND;

otherVariableOptionBody:  otherVarList | otherEnumerationList;

otherVarList: otherVar | otherVarList otherVar;

/* -------------------------------------------- */
otherVar: otherVarStart otherVarAttributes otherVarContent 
{     
    if (!parserData->ignoreDataAfterErrors)
        if (!osoption->setOtherVariableOptionVar(
                parserData->iOther, 
                parserData->kounter,
                parserData->idxAttribute, 
                parserData->nameAttribute,
                parserData->valueAttribute,
                parserData->lbValueAttribute, 
                parserData->ubValueAttribute) )
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set other variable option <var> element failed");
    parserData->kounter++;
};

otherVarStart: VARSTART
{
    if (parserData->kounter >= parserData->numberOfVar)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <var> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->idxAttributePresent = false;    
    parserData->nameAttributePresent = false;    
    parserData->nameAttribute = "";
    parserData->valueAttributePresent = false;    
    parserData->valueAttribute = "";
    parserData->lbValueAttributePresent = false;    
    parserData->lbValueAttribute = "";
    parserData->ubValueAttributePresent = false;    
    parserData->ubValueAttribute = "";
}; 

otherVarAttributes: otherVarAttList;

otherVarAttList: | otherVarAttList otherVarAtt;

otherVarAtt:
    idxAttribute
    {
        if (parserData->idxAttribute < 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "variable index must be nonnegative");
        if (osoption->optimization->numberOfVariables >= 0)
        {
            if (parserData->idxAttribute >= osoption->optimization->numberOfVariables)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "variable index exceeds upper limit");
        };
    }
  | nameAttribute
  | valueAttribute
  | lbValueAttribute
  | ubValueAttribute
  ;
      
otherVarContent: otherVarEmpty;

otherVarEmpty: GREATERTHAN VAREND | ENDOFELEMENT;


/**
 * ========================================================== 
 * <optimization> <objectives> 
 * ==========================================================
 */
objectives: | objectivesStart objectivesAttributes objectivesContent;

objectivesStart: OBJECTIVESSTART
{
    parserData->numberOfOtherObjectiveOptions = 0; 
    osoption->optimization->objectives = new ObjectiveOption();
};

objectivesAttributes: numberOfOtherObjectiveOptions
{    
    if (osoption->setNumberOfOtherObjectiveOptions(parserData->numberOfOtherObjectiveOptions) == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setNumberOfOtherVariableOptions failed");
    parserData->iOther = 0;
};

numberOfOtherObjectiveOptions: | numberOfOtherObjectiveOptionsAttribute
{    
    parserData->numberOfOtherObjectiveOptions = parserData->tempInt;
};

objectivesContent: objectivesEmpty | objectivesLaden;

objectivesEmpty: ENDOFELEMENT;

objectivesLaden: GREATERTHAN objectivesBody OBJECTIVESEND;

objectivesBody:  initialObjectiveValues initialObjectiveBounds objectiveInitialBasis otherObjectiveOptionsArray
{
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        

};


/* -------------------------------------------- */
initialObjectiveValues: | initialObjectiveValuesStart initialObjectiveValuesAttributes initialObjectiveValuesContent
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitObjValues(parserData->numberOfObj, parserData->idxArray, parserData->valArray, parserData->namArray) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <initialObjectiveValues> failed");
    delete[] parserData->idxArray;
    delete[] parserData->namArray;
    delete[] parserData->valArray;
    parserData->idxArray = NULL;
    parserData->namArray = NULL;
    parserData->valArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};


initialObjectiveValuesStart: INITIALOBJECTIVEVALUESSTART
{
    parserData->numberOfObjAttributePresent = false;
};


initialObjectiveValuesAttributes: numberOfObjAttribute 
{
    parserData->kounter = 0;
    parserData->idxArray = new         int[parserData->numberOfObj];
    parserData->namArray = new std::string[parserData->numberOfObj];
    parserData->valArray = new      double[parserData->numberOfObj];
    for (int i=0; i < parserData->numberOfObj; i++) parserData->idxArray[i] = -1;
    for (int i=0; i < parserData->numberOfObj; i++) parserData->namArray[i] = "";
    for (int i=0; i < parserData->numberOfObj; i++) parserData->valArray[i] = OSNaN();
}; 

initialObjectiveValuesContent: 
    initialObjectiveValuesEmpty 
    {    
        if (parserData->numberOfObj > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<initialObjectiveValues>: expected at least one <obj> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
  | initialObjectiveValuesLaden
    {
        if (parserData->kounter < parserData->numberOfObj)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<initialObjectiveValues>: fewer <obj> elements than specified");
            parserData->ignoreDataAfterErrors = true;        
        }
    };

initialObjectiveValuesEmpty: GREATERTHAN INITIALOBJECTIVEVALUESEND | ENDOFELEMENT;

initialObjectiveValuesLaden: GREATERTHAN initialObjectiveValuesBody INITIALOBJECTIVEVALUESEND;

initialObjectiveValuesBody:  initObjValueArray;

initObjValueArray: initObjValue | initObjValueArray initObjValue;

/* -------------------------------------------- */
initObjValue: initObjValueStart initObjValueAttributes initObjValueContent
{
    parserData->kounter++;
}; 

initObjValueStart: OBJSTART
{    
    if (parserData->kounter >= parserData->numberOfObj)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <obj> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->idxAttributePresent = false;
    parserData->nameAttributePresent = false;
    parserData->valueAttributePresent = false;
    parserData->idxAttribute = -1;
};

initObjValueAttributes: initObjValueAttList;

initObjValueAttList: | initObjValueAttList initObjValueAtt;

initObjValueAtt: 
    idxAttribute 
    {
        if (parserData->idxAttribute >= 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "objective index must be negative");
        if (osoption->optimization->numberOfObjectives >= 0)
        {
            if (parserData->idxAttribute < -osoption->optimization->numberOfObjectives)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "objective index exceeds limit");
        };
        parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
    }
  | nameAttribute
    {
        parserData->namArray[parserData->kounter] = parserData->nameAttribute;
    }
  | valueAttribute
    {
        if (parserData->valueAttribute == "")
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected an integer or floating point value");
        parserData->valArray[parserData->kounter] = os_strtod((parserData->valueAttribute).c_str(), NULL);
    };

initObjValueContent: GREATERTHAN OBJEND | ENDOFELEMENT;

/* -------------------------------------------- */
initialObjectiveBounds: | initialObjectiveBoundsStart numberOfObjATT initialObjectiveBoundsContent
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitObjBounds(parserData->numberOfObj, parserData->idxArray, parserData->lbValArray, parserData->ubValArray, parserData->namArray) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <initialObjectiveBounds> failed");
    delete[] parserData->idxArray;
    delete[] parserData->namArray;
    delete[] parserData->lbValArray;
    delete[] parserData->ubValArray;
    parserData->idxArray = NULL;
    parserData->namArray = NULL;
    parserData->lbValArray = NULL;
    parserData->ubValArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};


initialObjectiveBoundsStart: INITIALOBJECTIVEBOUNDSSTART
{
    parserData->numberOfObjAttributePresent = false;
};

numberOfObjATT: numberOfObjAttribute 
{
    parserData->kounter = 0;
    parserData->idxArray   = new         int[parserData->numberOfObj];
    parserData->lbValArray = new      double[parserData->numberOfObj];
    parserData->ubValArray = new      double[parserData->numberOfObj];
    parserData->namArray   = new std::string[parserData->numberOfObj];
    for (int i=0; i < parserData->numberOfObj; i++) parserData->idxArray[i] = -1;
    for (int i=0; i < parserData->numberOfObj; i++) parserData->namArray[i] = "";
    for (int i=0; i < parserData->numberOfObj; i++) parserData->lbValArray[i] = OSNaN();
    for (int i=0; i < parserData->numberOfObj; i++) parserData->ubValArray[i] = OSNaN();
}; 

initialObjectiveBoundsContent: 
    initialObjectiveBoundsEmpty 
    {
        if (parserData->numberOfObj > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<initialObjectiveBounds>: expected at least one <obj> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
  | initialObjectiveBoundsLaden
    {
        if (parserData->kounter < parserData->numberOfObj)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<initialObjectiveBounds>: fewer <obj> elements than specified");
            parserData->ignoreDataAfterErrors = true;        
        }
    };

initialObjectiveBoundsEmpty: GREATERTHAN INITIALOBJECTIVEBOUNDSEND | ENDOFELEMENT;

initialObjectiveBoundsLaden: GREATERTHAN initialObjectiveBoundsBody INITIALOBJECTIVEBOUNDSEND;

initialObjectiveBoundsBody:  initObjBoundArray;

initObjBoundArray: initObjBound | initObjBoundArray initObjBound;

/* -------------------------------------------- */
initObjBound: initObjBoundStart initObjBoundAttributes initObjBoundContent
{
    parserData->kounter++;
}; 

initObjBoundStart: OBJSTART
{    
    if (parserData->kounter >= parserData->numberOfObj)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <var> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->idxAttributePresent = false;
    parserData->nameAttributePresent = false;
    parserData->lbValueAttributePresent = false;
    parserData->ubValueAttributePresent = false;
    parserData->idxAttribute = -1;
    parserData->lbValueAttribute = "-INF";
    parserData->ubValueAttribute = "INF";
};

initObjBoundAttributes: initObjBoundAttList;

initObjBoundAttList: | initObjBoundAttList initObjBoundAtt;

initObjBoundAtt: 
    idxAttribute 
    {
        if (parserData->idxAttribute >= 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "objective index must be nonnegative");
        if (osoption->optimization->numberOfObjectives >= 0)
        {
            if (parserData->idxAttribute < -osoption->optimization->numberOfVariables)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "objective index exceeds limit");
        };
        parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
    }
  | nameAttribute
    {
        parserData->namArray[parserData->kounter] = parserData->nameAttribute;
    }
  | lbValueAttribute
    {
        if (parserData->lbValueAttribute == "")
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected an integer or floating point value");
        parserData->lbValArray[parserData->kounter] = os_strtod((parserData->lbValueAttribute).c_str(), NULL);
    }
  | ubValueAttribute
    {
        if (parserData->ubValueAttribute == "")
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected an integer or floating point value");
        parserData->ubValArray[parserData->kounter] = os_strtod((parserData->ubValueAttribute).c_str(), NULL);
    };

initObjBoundContent: GREATERTHAN OBJEND | ENDOFELEMENT;


/* -------------------------------------------- */
objectiveInitialBasis: | objectiveInitialBasisStart objectiveInitialBasisContent;

objectiveInitialBasisStart: INITIALBASISSTATUSSTART
{
    osoption->optimization->objectives->initialBasisStatus = new BasisStatus();
};

objectiveInitialBasisContent: objectiveInitialBasisEmpty | objectiveInitialBasisLaden;
 
objectiveInitialBasisEmpty: ENDOFELEMENT;

objectiveInitialBasisLaden: GREATERTHAN objectiveInitialBasisBody INITIALBASISSTATUSEND;

objectiveInitialBasisBody:  objectivesBasic objectivesAtLower objectivesAtUpper objectivesAtEquality objectivesIsFree objectivesSuperbasic objectivesUnknown;

/* -------------------------------------------- */
objectivesBasic: | objectivesBasicStart objectivesBasicNumberOfElATT objectivesBasicContent
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set objectives basic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

objectivesBasicStart: BASICSTART
{
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
};

objectivesBasicNumberOfElATT: numberOfElAttribute
{
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    if (parserData->numberOf > 0)
        osglData->osglIntArray = new int[parserData->numberOf];
}; 

objectivesBasicContent: objectivesBasicEmpty | objectivesBasicLaden;

objectivesBasicEmpty: ENDOFELEMENT;

objectivesBasicLaden: GREATERTHAN objectivesBasicBody BASICEND;

objectivesBasicBody:  osglIntArrayData;

/* -------------------------------------------- */
objectivesAtLower: | objectivesAtLowerStart objectivesAtLowerNumberOfElATT objectivesAtLowerContent
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set objectives atLower failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

objectivesAtLowerStart: ATLOWERSTART
{
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
};

objectivesAtLowerNumberOfElATT: numberOfElAttribute
{
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    if (parserData->numberOf > 0)
        osglData->osglIntArray = new int[parserData->numberOf];
}; 

objectivesAtLowerContent: objectivesAtLowerEmpty | objectivesAtLowerLaden;

objectivesAtLowerEmpty: ENDOFELEMENT;

objectivesAtLowerLaden: GREATERTHAN objectivesAtLowerBody ATLOWEREND;

objectivesAtLowerBody:  osglIntArrayData;

/* -------------------------------------------- */
objectivesAtUpper: | objectivesAtUpperStart objectivesAtUpperNumberOfElATT objectivesAtUpperContent
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set objectives atUpper failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

objectivesAtUpperStart: ATUPPERSTART
{
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
};

objectivesAtUpperNumberOfElATT: numberOfElAttribute
{
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    if (parserData->numberOf > 0)
        osglData->osglIntArray = new int[parserData->numberOf];
}; 

objectivesAtUpperContent: objectivesAtUpperEmpty | objectivesAtUpperLaden;

objectivesAtUpperEmpty: ENDOFELEMENT;

objectivesAtUpperLaden: GREATERTHAN objectivesAtUpperBody ATUPPEREND;

objectivesAtUpperBody:  osglIntArrayData;

/* -------------------------------------------- */
objectivesAtEquality: | objectivesAtEqualityStart objectivesAtEqualityNumberOfElATT objectivesAtEqualityContent
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atEquality, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set objectives atEquality failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

objectivesAtEqualityStart: ATEQUALITYSTART
{
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
};

objectivesAtEqualityNumberOfElATT: numberOfElAttribute
{
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    if (parserData->numberOf > 0)
        osglData->osglIntArray = new int[parserData->numberOf];
}; 

objectivesAtEqualityContent: objectivesAtEqualityEmpty | objectivesAtEqualityLaden;

objectivesAtEqualityEmpty: ENDOFELEMENT;

objectivesAtEqualityLaden: GREATERTHAN objectivesAtEqualityBody ATEQUALITYEND;

objectivesAtEqualityBody:  osglIntArrayData;

/* -------------------------------------------- */
objectivesIsFree: | objectivesIsFreeStart objectivesIsFreeNumberOfElATT objectivesIsFreeContent
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set objectives isFree failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

objectivesIsFreeStart: ISFREESTART
{
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
};

objectivesIsFreeNumberOfElATT: numberOfElAttribute
{
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    if (parserData->numberOf > 0)
        osglData->osglIntArray = new int[parserData->numberOf];
}; 

objectivesIsFreeContent: objectivesIsFreeEmpty | objectivesIsFreeLaden;

objectivesIsFreeEmpty: ENDOFELEMENT;

objectivesIsFreeLaden: GREATERTHAN objectivesIsFreeBody ISFREEEND;

objectivesIsFreeBody:  osglIntArrayData;

/* -------------------------------------------- */
objectivesSuperbasic: | objectivesSuperbasicStart objectivesSuperbasicNumberOfElATT objectivesSuperbasicContent
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set objectives superbasic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

objectivesSuperbasicStart: SUPERBASICSTART
{
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
};


objectivesSuperbasicNumberOfElATT: numberOfElAttribute
{
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    if (parserData->numberOf > 0)
        osglData->osglIntArray = new int[parserData->numberOf];
}; 

objectivesSuperbasicContent: objectivesSuperbasicEmpty | objectivesSuperbasicLaden;

objectivesSuperbasicEmpty: ENDOFELEMENT;

objectivesSuperbasicLaden: GREATERTHAN objectivesSuperbasicBody SUPERBASICEND;

objectivesSuperbasicBody:  osglIntArrayData;


/* -------------------------------------------- */
objectivesUnknown: | objectivesUnknownStart objectivesUnknownNumberOfElATT objectivesUnknownContent
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set objectives unknown failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

objectivesUnknownStart: UNKNOWNSTART
{
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
};

objectivesUnknownNumberOfElATT: numberOfElAttribute
{
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    if (parserData->numberOf > 0)
        osglData->osglIntArray = new int[parserData->numberOf];
}; 

objectivesUnknownContent: objectivesUnknownEmpty | objectivesUnknownLaden;

objectivesUnknownEmpty: ENDOFELEMENT;

objectivesUnknownLaden: GREATERTHAN objectivesUnknownBody UNKNOWNEND;

objectivesUnknownBody:  osglIntArrayData;


/* -------------------------------------------- */
otherObjectiveOptionsArray: | otherObjectiveOptionsArray otherObjectiveOption;

otherObjectiveOption: otherObjectiveOptionStart otherObjectiveOptionAttributes otherObjectiveOptionContent
    {      
        parserData->iOther++;  
    }
;

otherObjectiveOptionStart: OTHERSTART
{
    if (parserData->iOther >= parserData->numberOfOtherObjectiveOptions)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <otherObjectiveOptions> than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->numberOfObjAttributePresent = false;    
    parserData->numberOfObj = 0;
    parserData->numberOfEnumerationsAttributePresent = false;    
    parserData->numberOfEnumerations = 0;
    parserData->nameAttributePresent = false;    
    parserData->valueAttributePresent = false;    
    parserData->valueAttribute = "";
    parserData->solverAttributePresent = false;    
    parserData->solverAttribute = "";
    parserData->categoryAttributePresent = false;    
    parserData->categoryAttribute = "";
    parserData->typeAttributePresent = false;    
    parserData->typeAttribute = "";
    parserData->objTypeAttributePresent = false;    
    parserData->objTypeAttribute = "";
    parserData->enumTypeAttributePresent = false;    
    parserData->enumTypeAttribute = "";
    parserData->descriptionAttributePresent = false;    
    parserData->descriptionAttribute = "";    
    parserData->otherOptionType = ENUM_PROBLEM_COMPONENT_objectives;
}; 

otherObjectiveOptionAttributes: otherObjectiveOptionAttList
    {
        if (!parserData->nameAttributePresent) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<other> element requires name attribute"); 
        if (!parserData->ignoreDataAfterErrors)
            if (!osoption->setOtherObjectiveOptionAttributes(
                    parserData->iOther,
                    parserData->numberOfObj,
                    parserData->numberOfEnumerations,
                    parserData->nameAttribute,
                    parserData->valueAttribute,
                    parserData->solverAttribute,
                    parserData->categoryAttribute,
                    parserData->typeAttribute,
                    parserData->objTypeAttribute,
                    parserData->enumTypeAttribute,
                    parserData->descriptionAttribute) )
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<other> element could not be initialed"); 
    };


otherObjectiveOptionAttList: | otherObjectiveOptionAttList otherObjectiveOptionATT;

otherObjectiveOptionATT: 
    numberOfObjAttribute 
    {
        parserData->kounter = 0;
    }
  | numberOfEnumerationsAttribute
    {
        parserData->kounter = 0;
    }  
  | nameAttribute 
  | valueAttribute 
  | solverAttribute 
  | categoryAttribute 
  | typeAttribute 
  | objTypeAttribute 
  | enumTypeAttribute 
  | descriptionAttribute
  ;
    
otherObjectiveOptionContent: otherObjectiveOptionEmpty | otherObjectiveOptionLaden;

otherObjectiveOptionEmpty: GREATERTHAN OTHEREND | ENDOFELEMENT;

otherObjectiveOptionLaden: GREATERTHAN otherObjectiveOptionBody OTHEREND;

otherObjectiveOptionBody:  otherObjList | otherEnumerationList;

otherObjList: otherObj | otherObjList otherObj;

/* -------------------------------------------- */
otherObj: otherObjStart otherObjAttributes  otherObjContent 
{  
    if (!parserData->ignoreDataAfterErrors)
        if (!osoption->setOtherObjectiveOptionObj(
                parserData->iOther, 
                parserData->kounter,
                parserData->idxAttribute, 
                parserData->nameAttribute,
                parserData->valueAttribute,
                parserData->lbValueAttribute, 
                parserData->ubValueAttribute) )
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set other objective option <obj> element failed");
    parserData->kounter++;
};

otherObjStart: OBJSTART
{

    if (parserData->kounter >= parserData->numberOfObj)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <obj> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->idxAttributePresent = false;    
    parserData->idxAttribute = -1;
    parserData->nameAttributePresent = false;    
    parserData->nameAttribute = "";
    parserData->valueAttributePresent = false;    
    parserData->valueAttribute = "";
    parserData->lbValueAttributePresent = false;    
    parserData->lbValueAttribute = "";
    parserData->ubValueAttributePresent = false;    
    parserData->ubValueAttribute = "";
}; 

otherObjAttributes: otherObjAttList;

otherObjAttList: | otherObjAttList otherObjAtt;

otherObjAtt:
    idxAttribute
    {
        if (parserData->idxAttribute >= 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "objective index must be negative");
        if (osoption->optimization->numberOfObjectives >= 0)
        {
            if (parserData->idxAttribute < -osoption->optimization->numberOfObjectives)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "objective index exceeds limit");
        };
    }
  | nameAttribute
  | valueAttribute
  | lbValueAttribute
  | ubValueAttribute
  ;

otherObjContent: otherObjEmpty;

otherObjEmpty: GREATERTHAN OBJEND | ENDOFELEMENT;


/**
 * ========================================================== 
 * <optimization> <constraints> 
 * ==========================================================
 */
constraints: | constraintsStart constraintsAttributes constraintsContent;

constraintsStart: CONSTRAINTSSTART
{
    parserData->numberOfOtherConstraintOptions = 0; 
    osoption->optimization->constraints = new ConstraintOption();
};

constraintsAttributes: numberOfOtherConstraintOptions
{    
    if (osoption->setNumberOfOtherConstraintOptions(parserData->numberOfOtherConstraintOptions) == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setNumberOfOtherConstraintOptions failed");
    parserData->iOther = 0;
};

numberOfOtherConstraintOptions: | numberOfOtherConstraintOptionsAttribute
{    
    parserData->numberOfOtherConstraintOptions = parserData->tempInt;
};

constraintsContent: constraintsEmpty | constraintsLaden;

constraintsEmpty: ENDOFELEMENT;

constraintsLaden: GREATERTHAN constraintsBody CONSTRAINTSEND;

constraintsBody:  initialConstraintValues initialDualValues slacksInitialBasis otherConstraintOptionsArray
{
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        

};


/* -------------------------------------------- */
initialConstraintValues: | initialConstraintValuesStart initialConstraintValuesAttributes initialConstraintValuesContent
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitConValues(parserData->numberOfCon, parserData->idxArray, parserData->valArray, parserData->namArray) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <initialConstraintValues> failed");
    delete[] parserData->idxArray;
    delete[] parserData->namArray;
    delete[] parserData->valArray;
    parserData->idxArray = NULL;
    parserData->namArray = NULL;
    parserData->valArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};


initialConstraintValuesStart:  INITIALCONSTRAINTVALUESSTART
{
    parserData->numberOfConAttributePresent = false;
};

initialConstraintValuesAttributes: numberOfConAttribute 
{
    parserData->kounter = 0;
    parserData->idxArray = new         int[parserData->numberOfCon];
    parserData->namArray = new std::string[parserData->numberOfCon];
    parserData->valArray = new      double[parserData->numberOfCon];
    for (int i=0; i < parserData->numberOfCon; i++) parserData->namArray[i] = "";
    for (int i=0; i < parserData->numberOfCon; i++) parserData->valArray[i] = OSNaN();
}; 

initialConstraintValuesContent:
    initialConstraintValuesEmpty 
    {
        if (parserData->numberOfCon > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<initialConstraintValues>: expected at least one <con element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
  | initialConstraintValuesLaden
    {
        if (parserData->kounter < parserData->numberOfCon)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<initialConstraintValues>: fewer <con> elements than specified");
            parserData->ignoreDataAfterErrors = true;        
        }
    };

initialConstraintValuesEmpty: GREATERTHAN INITIALCONSTRAINTVALUESEND | ENDOFELEMENT;

initialConstraintValuesLaden: GREATERTHAN initialConstraintValuesBody INITIALCONSTRAINTVALUESEND;

initialConstraintValuesBody:  initConValueArray;

initConValueArray: initConValue | initConValueArray initConValue;

/* -------------------------------------------- */
initConValue: initConValueStart initConValueAttributes initConValueContent
{
    parserData->kounter++;
}; 

initConValueStart: CONSTART
{    
    if (parserData->kounter >= parserData->numberOfCon)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <con> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->idxAttributePresent = false;
    parserData->nameAttribute = "";
    parserData->nameAttributePresent = false;
    parserData->valueAttributePresent = false;
};

initConValueAttributes: initConValueAttList
{
    if (parserData->idxAttributePresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<con> element must have idx attribute");
};

initConValueAttList: | initConValueAttList initConValueAtt;

initConValueAtt: 
    idxAttribute 
    {
        if (parserData->idxAttribute < 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "constraint index must be nonnegative");
        if (osoption->optimization->numberOfConstraints >= 0)
        {
            if (parserData->idxAttribute >= osoption->optimization->numberOfConstraints)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "constraint index exceeds upper limit");
        };
        parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
    }
  | nameAttribute
    {
        parserData->namArray[parserData->kounter] = parserData->nameAttribute;
    }
  | valueAttribute
    {
        if (parserData->valueAttribute == "")
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected an integer or floating point value");
        parserData->valArray[parserData->kounter] = os_strtod((parserData->valueAttribute).c_str(), NULL);
    };

initConValueContent: GREATERTHAN CONEND | ENDOFELEMENT;


/* -------------------------------------------- */
initialDualValues: | initialDualValuesStart initialDualValuesAttributes initialDualValuesContent
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitDualValues(parserData->numberOfCon, parserData->idxArray, parserData->lbValArray, parserData->ubValArray, parserData->namArray) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <initialConstraintValues> failed");
    delete[] parserData->idxArray;
    delete[] parserData->namArray;
    delete[] parserData->lbValArray;
    delete[] parserData->ubValArray;
    parserData->idxArray = NULL;
    parserData->namArray = NULL;
    parserData->lbValArray = NULL;
    parserData->ubValArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};


initialDualValuesStart: INITIALDUALVALUESSTART
{
    parserData->numberOfConAttributePresent = false;
};

initialDualValuesAttributes: numberOfConAttribute 
{
    parserData->kounter = 0;
    parserData->idxArray   = new         int[parserData->numberOfCon];
    parserData->namArray   = new std::string[parserData->numberOfCon];
    parserData->lbValArray = new      double[parserData->numberOfCon];
    parserData->ubValArray = new      double[parserData->numberOfCon];
    for (int i=0; i < parserData->numberOfCon; i++) parserData->namArray[i] = "";
    for (int i=0; i < parserData->numberOfCon; i++) parserData->lbValArray[i] = OSNaN();
    for (int i=0; i < parserData->numberOfCon; i++) parserData->ubValArray[i] = OSNaN();
}; 

initialDualValuesContent: 
    initialDualValuesEmpty 
    {
        if (parserData->numberOfCon > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<initialDualValues>: expected at least one <con> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
  | initialDualValuesLaden
    {
        if (parserData->kounter < parserData->numberOfCon)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<initialDualValues>: fewer <con> elements than specified");
            parserData->ignoreDataAfterErrors = true;        
        }
    };

initialDualValuesEmpty: GREATERTHAN INITIALDUALVALUESEND | ENDOFELEMENT;

initialDualValuesLaden: GREATERTHAN initialDualValuesBody INITIALDUALVALUESEND;

initialDualValuesBody:  initDualValueArray;

initDualValueArray: initDualValue | initDualValueArray initDualValue;

/* -------------------------------------------- */
initDualValue: initDualValueStart  initDualValueAttributes initDualValueContent
{    
    parserData->kounter++;
}; 

initDualValueStart: CONSTART
{    
    if (parserData->kounter >= parserData->numberOfCon)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <con> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->idxAttributePresent = false;
    parserData->nameAttributePresent = false;
    parserData->nameAttribute = "";
    parserData->lbValueAttributePresent = false;
    parserData->ubValueAttributePresent = false;
    parserData->lbDualValue = OSNaN();
    parserData->ubDualValue = OSNaN();
};

initDualValueAttributes: initDualValueAttList
{
    if (parserData->idxAttributePresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<con> element must have idx attribute");
};

initDualValueAttList: | initDualValueAttList initDualValueAtt;

initDualValueAtt: 
    idxAttribute
    {
        if (parserData->idxAttribute < 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "constraint index must be nonnegative");
        if (osoption->optimization->numberOfConstraints >= 0)
        {
            if (parserData->idxAttribute >= osoption->optimization->numberOfConstraints)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "constraint index exceeds upper limit");
        };
        parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
    }
  | nameAttribute
    {
        parserData->namArray[parserData->kounter] = parserData->nameAttribute;
    }
  | lbDualValueAttribute
    {
        parserData->lbValArray[parserData->kounter] = parserData->lbDualValue;
    }
  | ubDualValueAttribute
    {
        parserData->ubValArray[parserData->kounter] = parserData->ubDualValue;
    }
  ;

initDualValueContent: GREATERTHAN CONEND | ENDOFELEMENT;


/* -------------------------------------------- */
slacksInitialBasis: | slacksInitialBasisStart slacksInitialBasisContent;

slacksInitialBasisStart: INITIALBASISSTATUSSTART
{
    osoption->optimization->constraints->initialBasisStatus = new BasisStatus();
};

slacksInitialBasisContent: slacksInitialBasisEmpty | slacksInitialBasisLaden;
 
slacksInitialBasisEmpty: ENDOFELEMENT;

slacksInitialBasisLaden: GREATERTHAN slacksInitialBasisBody INITIALBASISSTATUSEND;

slacksInitialBasisBody:  slacksBasic slacksAtLower slacksAtUpper slacksAtEquality slacksIsFree slacksSuperbasic slacksUnknown;

/* -------------------------------------------- */
slacksBasic: | slacksBasicStart slacksBasicNumberOfElATT slacksBasicContent
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set slacks basic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

slacksBasicStart: BASICSTART
{
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
};

slacksBasicNumberOfElATT: numberOfElAttribute
{
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    if (parserData->numberOf > 0)
        osglData->osglIntArray = new int[parserData->numberOf];
}; 

slacksBasicContent: slacksBasicEmpty | slacksBasicLaden;

slacksBasicEmpty: ENDOFELEMENT;

slacksBasicLaden: GREATERTHAN slacksBasicBody BASICEND;

slacksBasicBody:  osglIntArrayData;

/* -------------------------------------------- */
slacksAtLower: | slacksAtLowerStart slacksAtLowerNumberOfElATT slacksAtLowerContent
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set slacks atLower failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

slacksAtLowerStart: ATLOWERSTART
{
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
};

slacksAtLowerNumberOfElATT: numberOfElAttribute
{
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    if (parserData->numberOf > 0)
        osglData->osglIntArray = new int[parserData->numberOf];
}; 

slacksAtLowerContent: slacksAtLowerEmpty | slacksAtLowerLaden;

slacksAtLowerEmpty: ENDOFELEMENT;

slacksAtLowerLaden: GREATERTHAN slacksAtLowerBody ATLOWEREND;

slacksAtLowerBody:  osglIntArrayData;


/* -------------------------------------------- */
slacksAtUpper: | slacksAtUpperStart slacksAtUpperNumberOfElATT slacksAtUpperContent
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set slacks atUpper failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

slacksAtUpperStart: ATUPPERSTART
{
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
};

slacksAtUpperNumberOfElATT: numberOfElAttribute
{
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    if (parserData->numberOf > 0)
        osglData->osglIntArray = new int[parserData->numberOf];
}; 

slacksAtUpperContent: slacksAtUpperEmpty | slacksAtUpperLaden;

slacksAtUpperEmpty: ENDOFELEMENT;

slacksAtUpperLaden: GREATERTHAN slacksAtUpperBody ATUPPEREND;

slacksAtUpperBody:  osglIntArrayData;


/* -------------------------------------------- */
slacksAtEquality: | slacksAtEqualityStart slacksAtEqualityNumberOfElATT slacksAtEqualityContent
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atEquality, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set slacks atEquality failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

slacksAtEqualityStart: ATEQUALITYSTART
{
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
};

slacksAtEqualityNumberOfElATT: numberOfElAttribute
{
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    if (parserData->numberOf > 0)
        osglData->osglIntArray = new int[parserData->numberOf];
}; 

slacksAtEqualityContent: slacksAtEqualityEmpty | slacksAtEqualityLaden;

slacksAtEqualityEmpty: ENDOFELEMENT;

slacksAtEqualityLaden: GREATERTHAN slacksAtEqualityBody ATEQUALITYEND;

slacksAtEqualityBody:  osglIntArrayData;


/* -------------------------------------------- */
slacksIsFree: | slacksIsFreeStart slacksIsFreeNumberOfElATT slacksIsFreeContent
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set slacks isFree failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

slacksIsFreeStart: ISFREESTART
{
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
};

slacksIsFreeNumberOfElATT: numberOfElAttribute
{
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    if (parserData->numberOf > 0)
        osglData->osglIntArray = new int[parserData->numberOf];
}; 

slacksIsFreeContent: slacksIsFreeEmpty | slacksIsFreeLaden;

slacksIsFreeEmpty: ENDOFELEMENT;

slacksIsFreeLaden: GREATERTHAN slacksIsFreeBody ISFREEEND;

slacksIsFreeBody:  osglIntArrayData;


/* -------------------------------------------- */
slacksSuperbasic: | slacksSuperbasicStart slacksSuperbasicNumberOfElATT slacksSuperbasicContent
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set variables superbasic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

slacksSuperbasicStart: SUPERBASICSTART
{
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
};

slacksSuperbasicNumberOfElATT: numberOfElAttribute
{
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    if (parserData->numberOf > 0)
        osglData->osglIntArray = new int[parserData->numberOf];
}; 

slacksSuperbasicContent: slacksSuperbasicEmpty | slacksSuperbasicLaden;

slacksSuperbasicEmpty: ENDOFELEMENT;

slacksSuperbasicLaden: GREATERTHAN slacksSuperbasicBody SUPERBASICEND;

slacksSuperbasicBody:  osglIntArrayData;


/* -------------------------------------------- */
slacksUnknown: | slacksUnknownStart slacksUnknownNumberOfElATT slacksUnknownContent
{
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set slacks unknown failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

slacksUnknownStart: UNKNOWNSTART
{
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
};

slacksUnknownNumberOfElATT: numberOfElAttribute
{
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    if (parserData->numberOf > 0)
        osglData->osglIntArray = new int[parserData->numberOf];
}; 

slacksUnknownContent: slacksUnknownEmpty | slacksUnknownLaden;

slacksUnknownEmpty: ENDOFELEMENT;

slacksUnknownLaden: GREATERTHAN slacksUnknownBody UNKNOWNEND;

slacksUnknownBody:  osglIntArrayData;


/* -------------------------------------------- */
otherConstraintOptionsArray: | otherConstraintOptionsArray otherConstraintOption;

otherConstraintOption: otherConstraintOptionStart otherConstraintOptionAttributes otherConstraintOptionContent
    {      
        parserData->iOther++;  
    }
;

otherConstraintOptionStart: OTHERSTART
{
    if (parserData->iOther >= parserData->numberOfOtherConstraintOptions)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <otherConstraintOptions> than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->numberOfConAttributePresent = false;    
    parserData->numberOfCon = 0;
    parserData->numberOfEnumerationsAttributePresent = false;    
    parserData->numberOfEnumerations = 0;
    parserData->nameAttributePresent = false;    
    parserData->valueAttributePresent = false;    
    parserData->valueAttribute = "";
    parserData->solverAttributePresent = false;    
    parserData->solverAttribute = "";
    parserData->categoryAttributePresent = false;    
    parserData->categoryAttribute = "";
    parserData->typeAttributePresent = false;    
    parserData->typeAttribute = "";
    parserData->conTypeAttributePresent = false;    
    parserData->conTypeAttribute = "";
    parserData->enumTypeAttributePresent = false;    
    parserData->enumTypeAttribute = "";
    parserData->descriptionAttributePresent = false;    
    parserData->descriptionAttribute = "";    
    parserData->otherOptionType = ENUM_PROBLEM_COMPONENT_constraints;
}; 

otherConstraintOptionAttributes: otherConstraintOptionAttList
    {
        if(!parserData->nameAttributePresent) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<other> element requires name attribute"); 
        if (!parserData->ignoreDataAfterErrors)
            if (!osoption->setOtherConstraintOptionAttributes(
                    parserData->iOther,
                    parserData->numberOfCon,
                    parserData->numberOfEnumerations,
                    parserData->nameAttribute,
                    parserData->valueAttribute,
                    parserData->solverAttribute,
                    parserData->categoryAttribute,
                    parserData->typeAttribute,
                    parserData->conTypeAttribute,
                    parserData->enumTypeAttribute,
                    parserData->descriptionAttribute) )
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<other> element could not be initialed"); 
    };

otherConstraintOptionAttList: | otherConstraintOptionAttList otherConstraintOptionATT;

otherConstraintOptionATT: 
    numberOfConAttribute
    {
        parserData->kounter = 0;
    } 
  | numberOfEnumerationsAttribute
    {
        parserData->kounter = 0;
    }  
  | nameAttribute 
  | valueAttribute 
  | solverAttribute 
  | categoryAttribute 
  | typeAttribute 
  | conTypeAttribute 
  | enumTypeAttribute 
  | descriptionAttribute
  ;
  
otherConstraintOptionContent: otherConstraintOptionEmpty | otherConstraintOptionLaden;

otherConstraintOptionEmpty: GREATERTHAN OTHEREND | ENDOFELEMENT    

otherConstraintOptionLaden: GREATERTHAN otherConstraintOptionBody OTHEREND;

otherConstraintOptionBody:  otherConList | otherEnumerationList;

otherConList: otherCon | otherConList otherCon;

/* -------------------------------------------- */
otherCon: otherConStart otherConAttributes  otherConContent 
{     
    if (!parserData->ignoreDataAfterErrors)
        if (!osoption->setOtherConstraintOptionCon(
                parserData->iOther, 
                parserData->kounter,
                parserData->idxAttribute, 
                parserData->nameAttribute,
                parserData->valueAttribute,
                parserData->lbValueAttribute, 
                parserData->ubValueAttribute) )
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set other constraint option <con> element failed");
    parserData->kounter++;
};
  
otherConStart: CONSTART
{
    if (parserData->kounter >= parserData->numberOfCon)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <con> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->idxAttributePresent = false;    
    parserData->nameAttributePresent = false;    
    parserData->nameAttribute = "";
    parserData->valueAttributePresent = false;    
    parserData->valueAttribute = "";
    parserData->lbValueAttributePresent = false;    
    parserData->lbValueAttribute = "";
    parserData->ubValueAttributePresent = false;    
    parserData->ubValueAttribute = "";
}; 

otherConAttributes: otherConAttList;

otherConAttList: | otherConAttList otherConAtt;

otherConAtt:
    idxAttribute
    {
        if (parserData->idxAttribute < 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "constraint index must be nonnegative");
        if (osoption->optimization->numberOfConstraints >= 0)
        {
            if (parserData->idxAttribute >= osoption->optimization->numberOfConstraints)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "constraint index exceeds upper limit");
        };
    }
  | nameAttribute
  | valueAttribute
  | lbValueAttribute
  | ubValueAttribute
  ;

otherConContent: otherConEmpty;

otherConEmpty: GREATERTHAN CONEND | ENDOFELEMENT;


/**
 * ========================================================== 
 * solver options
 * ==========================================================
 */
solverOptions: | solverOptionsStart numberOfSolverOptionsATT solverOptionsContent
    {
        parserData->suppressFurtherErrorMessages = false;
        parserData->ignoreDataAfterErrors = false;        
    };

solverOptionsStart: SOLVEROPTIONSSTART;

numberOfSolverOptionsATT: numberOfSolverOptionsAttribute
{
    if (!osoption->setNumberOfSolverOptions(parserData->numberOfSolverOptions) )
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setNumberOfSolverOptions failed");
    parserData->iOption = 0;
}; 

solverOptionsContent:
    solverOptionsEmpty
    {
        if (parserData->numberOfSolverOptions > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected at least one <solverOption> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
  | solverOptionsLaden
    {
        if (parserData->iOption != parserData->numberOfSolverOptions)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "fewer <solverOption> elements than specified");
            parserData->ignoreDataAfterErrors = true;        
        }
    };

solverOptionsEmpty: ENDOFELEMENT;

solverOptionsLaden: GREATERTHAN solverOptionArray SOLVEROPTIONSEND;

solverOptionArray: | solverOptionArray solverOption;


/* -------------------------------------------- */
solverOption: solverOptionStart solverOptionAttributes solverOptionContent
{
    if (!parserData->ignoreDataAfterErrors)
        if (!osoption->setSolverOptionContent(
                    parserData->iOption, 
                    parserData->numberOfItems,
                    parserData->nameAttribute,
                    parserData->valueAttribute,
                    parserData->solverAttribute,
                    parserData->categoryAttribute,
                    parserData->typeAttribute,
                    parserData->descriptionAttribute,
                    parserData->itemList) )
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setSolverOptionContent failed");
    if (parserData->numberOfItems > 0)
        delete[] parserData->itemList;
    parserData->itemList = NULL;
    parserData->iOption++;
};

solverOptionStart: SOLVEROPTIONSTART
{
    parserData->nameAttributePresent = false;
    parserData->valueAttributePresent = false;
    parserData->solverAttributePresent = false;
    parserData->categoryAttributePresent = false;
    parserData->typeAttributePresent = false;
    parserData->descriptionAttributePresent = false;
    parserData->numberOfItemsPresent = false;
    parserData->valueAttribute = "";
    parserData->solverAttribute = "";
    parserData->categoryAttribute = "";
    parserData->typeAttribute = "";
    parserData->descriptionAttribute = "";
    parserData->numberOfItems = 0;
    parserData->kounter = 0;
};

solverOptionAttributes: solverOptionAttList
{
    if (!parserData->nameAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "name attribute must be present");
};

solverOptionAttList: solverOptionATT | solverOptionAttList solverOptionATT;

solverOptionATT:
     nameAttribute 
  | valueAttribute 
  | solverAttribute
  | categoryAttribute 
  | typeAttribute 
  | descriptionAttribute
  | numberOfItemsAttribute
    {
            parserData->itemList = new std::string[parserData->numberOfItems];
    }
  ;

solverOptionContent:
    solverOptionEmpty
    {
        if (parserData->numberOfItems > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected at least one <item> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
 | solverOptionLaden
    {
        if (parserData->kounter < parserData->numberOfItems)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "fewer <item> elements than specified");
            parserData->ignoreDataAfterErrors = true;        
        }
    };

solverOptionEmpty: GREATERTHAN SOLVEROPTIONEND | ENDOFELEMENT;

solverOptionLaden: GREATERTHAN solverOptionBody SOLVEROPTIONEND;

solverOptionBody: solverOptionItemArray;

solverOptionItemArray: solverOptionItem | solverOptionItemArray solverOptionItem;

solverOptionItem: solverOptionItemContent
{    
    parserData->itemList[parserData->kounter] = parserData->itemContent;
    parserData->kounter++;
};    

solverOptionItemContent: 
    solverOptionItemEmpty
    {
        if (parserData->kounter >= parserData->numberOfItems)
            if (!parserData->suppressFurtherErrorMessages)
            {
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <item> elements than specified");
                parserData->suppressFurtherErrorMessages = true;
                parserData->ignoreDataAfterErrors = true;
            }
        parserData->itemContent = "";            
    }    
  | solverOptionItemLaden; 

solverOptionItemEmpty: ITEMSTARTANDEND | ITEMEMPTY;

solverOptionItemLaden: ITEMSTART solverOptionItemBody ITEMEND;

solverOptionItemBody:  ITEMTEXT 
{
    if (parserData->kounter >= parserData->numberOf)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <item> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->itemContent = $1; 
    free($1);
};


/**
 *  PathList is an object used repeatedly within the <job> element
 */
PathList: Path | PathList Path;

Path: PATHSTART GREATERTHAN ELEMENTTEXT PATHEND
{
    if (parserData->kounter >= parserData->numberOf)
    {
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too many paths in <requiredDirectories> element");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    }
    else
    {
        parserData->paths[parserData->kounter] = $3;
        parserData->kounter++;
    }
    free($3); 
};

/**
 *  PathPair is an object used repeatedly within the <job> element
 */
PathPair: PathPairStart PathPairAttributes PathPairEnd
{    
    if (parserData->kounter >= parserData->numberOfPathPairs)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too many path pairs");
    else
    {
        if (!parserData->pathPairFromPresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "\"from\" attribute must be present");
        if (!parserData->pathPairToPresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "\"to\" attribute must be present");
           parserData->fromPaths[parserData->kounter] = parserData->pathPairFrom;
           parserData->toPaths[parserData->kounter] = parserData->pathPairTo;
        parserData->makeCopy[parserData->kounter] = parserData->pathPairMakeCopy;
         parserData->kounter++;
    }
};

PathPairStart: PATHPAIRSTART
{
//    if (parserData->kounter >= parserData->numberOfPathPairs)
//        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too many path pairs");
    parserData->pathPairFrom = "";
    parserData->pathPairTo = "";
    parserData->pathPairFromPresent = false;
    parserData->pathPairToPresent = false;
    parserData->pathPairMakeCopyPresent = false;
    parserData->pathPairMakeCopy = false;
};
    
PathPairAttributes: PathPairAttList
{
//    parserData->makeCopy[parserData->kounter] = parserData->pathPairMakeCopy;
};

PathPairAttList: | PathPairAttList PathPairAttribute;

PathPairAttribute:
    PathPairFromATT
  | PathPairToATT
  | PathPairMakeCopyATT;
      
PathPairFromATT: FROMATT ATTRIBUTETEXT QUOTE
{
    if (parserData->pathPairFromPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one \"from\" attribute allowed");
    parserData->pathPairFromPresent = true;
    parserData->pathPairFrom = $2;
    free($2);
};

PathPairToATT: TOATT ATTRIBUTETEXT QUOTE
{
    if (parserData->pathPairToPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one \"to\" attribute allowed");
    parserData->pathPairToPresent = true;
    parserData->pathPairTo = $2;
    free($2);
};

PathPairMakeCopyATT: MAKECOPYATT ATTRIBUTETEXT QUOTE
{
    if (parserData->pathPairMakeCopyPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one \"makeCopy\" attribute allowed");
    parserData->pathPairMakeCopyPresent = true;
    parserData->pathPairMakeCopy = (strcmp($2,"true") == 0);
    free($2);
};

PathPairEnd: GREATERTHAN PATHPAIREND | ENDOFELEMENT;


/****************************************************************************
 *  Here we collect the rules for some attributes that are used repeatedly  *
 ****************************************************************************/
categoryAttribute: categoryAtt
{   
    if (parserData->categoryAttributePresent ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one category attribute allowed for this element");
    parserData->categoryAttributePresent = true;
};

categoryAtt: categoryAttEmpty | categoryAttContent;

categoryAttEmpty: EMPTYCATEGORYATT
{ 
    parserData->categoryAttribute = "";
};

categoryAttContent: CATEGORYATT ATTRIBUTETEXT quote 
{ 
    parserData->categoryAttribute = $2; 
    free($2); 
};

/* ----------------------------------------------------------------------- */
conTypeAttribute: conTypeAtt
        {   if (parserData->conTypeAttributePresent ) 
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one conType attribute allowed for this element");
            parserData->conTypeAttributePresent = true;
        };

conTypeAtt: conTypeAttEmpty | conTypeAttContent;

conTypeAttEmpty: EMPTYCONTYPEATT
{ parserData->conTypeAttribute = ""; };

conTypeAttContent: CONTYPEATT ATTRIBUTETEXT QUOTE 
{ 
    parserData->conTypeAttribute = $2; 
    free($2);
};

/* ----------------------------------------------------------------------- */
descriptionAttribute: descriptionAtt
{
    if (parserData->descriptionAttributePresent ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one description attribute allowed for this element");
    parserData->descriptionAttributePresent = true;
};

descriptionAtt: descriptionAttEmpty | descriptionAttContent;

descriptionAttEmpty: EMPTYDESCRIPTIONATT
{ parserData->descriptionAttribute = ""; };

descriptionAttContent: DESCRIPTIONATT ATTRIBUTETEXT quote 
{ 
    parserData->descriptionAttribute = $2; 
    free($2);
};

/* ----------------------------------------------------------------------- */
enumTypeAttribute: enumTypeAtt
        {   if (parserData->enumTypeAttributePresent ) 
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one enumType attribute allowed for this element");
            parserData->enumTypeAttributePresent = true;
        };

enumTypeAtt: enumTypeAttEmpty | enumTypeAttContent;

enumTypeAttEmpty: EMPTYENUMTYPEATT
{ parserData->enumTypeAttribute = ""; };

enumTypeAttContent: ENUMTYPEATT ATTRIBUTETEXT QUOTE 
{ 
    parserData->enumTypeAttribute = $2; 
    free($2);
};


/* ----------------------------------------------------------------------- */
groupWeightAttribute: groupWeightAtt
{
    if (parserData->groupWeightAttributePresent ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one groupWeight attribute allowed for this element");
    parserData->groupWeightAttributePresent = true;
};

groupWeightAtt: GROUPWEIGHTATT QUOTE aNumber QUOTE
{
    parserData->groupWeight = parserData->tempVal;
};


/* ----------------------------------------------------------------------- */
idxAttribute: idxAtt
{   
    if (parserData->idxAttributePresent ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one idx attribute allowed for this element");
    parserData->idxAttributePresent = true;
};

idxAtt: idxAttContent;

idxAttContent: IDXATT quote INTEGER quote 
{ 
    parserData->idxAttribute = $3;
};

/* ----------------------------------------------------------------------- */
lbValueAttribute: lbValueAtt
{   
    if (parserData->lbValueAttributePresent ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one lb attribute allowed for this element");
    parserData->lbValueAttributePresent = true;
};

lbValueAtt: lbValueAttEmpty | lbValueAttContent;

lbValueAttEmpty: EMPTYLBVALUEATT
{ 
    parserData->lbValueAttribute = ""; 
};

lbValueAttContent: LBVALUEATT ATTRIBUTETEXT quote
{ 
    parserData->lbValueAttribute = $2; 
    free($2);
};

/* ----------------------------------------------------------------------- */
lbDualValueAttribute: lbDualValueAtt
        {   if (parserData->lbValueAttributePresent ) 
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one lb attribute allowed for this element");
            parserData->lbValueAttributePresent = true;
        };

lbDualValueAtt: lbDualValueAttEmpty | lbDualValueAttContent;

lbDualValueAttEmpty: EMPTYLBDUALVALUEATT
{ 
    parserData->lbDualValue = 0.0; 
};

lbDualValueAttContent: LBDUALVALUEATT quote aNumber quote
{
    parserData->lbDualValue = parserData->tempVal;
};

/* ----------------------------------------------------------------------- */
nameAttribute: nameAtt
    {
        if (parserData->nameAttributePresent ) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one name attribute allowed for this element");
        parserData->nameAttributePresent = true;
    };

nameAtt: nameAttEmpty | nameAttContent;

nameAttEmpty: EMPTYNAMEATT
    { 
        parserData->nameAttribute = ""; 
    };

nameAttContent: NAMEATT ATTRIBUTETEXT quote 
    { 
        parserData->nameAttribute = $2; 
        free($2);
    };

/* ----------------------------------------------------------------------- */
objTypeAttribute: objTypeAtt
        {   if (parserData->objTypeAttributePresent ) 
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one objType attribute allowed for this element");
            parserData->objTypeAttributePresent = true;
        };

objTypeAtt: objTypeAttEmpty | objTypeAttContent;

objTypeAttEmpty: EMPTYOBJTYPEATT
{ parserData->objTypeAttribute = ""; };

objTypeAttContent: OBJTYPEATT ATTRIBUTETEXT QUOTE 
{ 
    parserData->objTypeAttribute = $2; 
    free($2);
};


/* ----------------------------------------------------------------------- */
solverAttribute: solverAtt
    {   if (parserData->solverAttributePresent ) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one solver attribute allowed for this element");
        parserData->solverAttributePresent = true;
    };

solverAtt: solverAttEmpty | solverAttContent;

solverAttEmpty: EMPTYSOLVERATT
{ parserData->solverAttribute = ""; };

solverAttContent: SOLVERATT ATTRIBUTETEXT quote 
{ 
    parserData->solverAttribute = $2; 
    free($2);
};

/* ----------------------------------------------------------------------- */
sosIdxAttribute: sosIdxAtt
    {   if (parserData->sosIdxAttributePresent ) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one sosIdx attribute allowed for this element");
        parserData->sosIdxAttributePresent = true;
    };

sosIdxAtt: sosIdxAttContent;

sosIdxAttContent: SOSIDXATT quote INTEGER quote 
{
    if ($3 < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "SOS index must be nonnegative");
    parserData->sosIdx = $3;
};

/* ----------------------------------------------------------------------- */
typeAttribute: typeAtt
        {   if (parserData->typeAttributePresent ) 
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one type attribute allowed for this element");
            parserData->typeAttributePresent = true;
        };

typeAtt: typeAttEmpty | typeAttContent;

typeAttEmpty: EMPTYTYPEATT
{ parserData->typeAttribute = ""; };

typeAttContent: TYPEATT ATTRIBUTETEXT QUOTE 
{ 
    parserData->typeAttribute = $2; 
    free($2);
};

/* ----------------------------------------------------------------------- */
ubValueAttribute: ubValueAtt
{
   if (parserData->ubValueAttributePresent ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one ub attribute allowed for this element");
    parserData->ubValueAttributePresent = true;
};

ubValueAtt: ubValueAttEmpty | ubValueAttContent;

ubValueAttEmpty: EMPTYUBVALUEATT
{ 
    parserData->ubValueAttribute = ""; 
};

ubValueAttContent: UBVALUEATT ATTRIBUTETEXT quote
{ 
    parserData->ubValueAttribute = $2; 
    free($2);
};

/* ----------------------------------------------------------------------- */
ubDualValueAttribute: ubDualValueAtt
        {   if (parserData->ubValueAttributePresent ) 
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one ub attribute allowed for this element");
            parserData->ubValueAttributePresent = true;
        };

ubDualValueAtt: ubDualValueAttEmpty | ubDualValueAttContent;

ubDualValueAttEmpty: EMPTYUBDUALVALUEATT
{ parserData->ubDualValue = 0.0; };

ubDualValueAttContent: UBDUALVALUEATT quote aNumber quote
{ 
    parserData->ubDualValue = parserData->tempVal;
};


/* ----------------------------------------------------------------------- */
unitAttribute: unitAtt
        {   if (parserData->unitAttributePresent ) 
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one unit attribute allowed for this element");
            parserData->unitAttributePresent = true;
        };
        
unitAtt: unitAttEmpty | unitAttContent;

unitAttEmpty: EMPTYUNITATT
{ parserData->unitAttribute = ""; };

unitAttContent: UNITATT ATTRIBUTETEXT QUOTE 
{ 
    parserData->unitAttribute = $2; 
    free($2);
};

/* ----------------------------------------------------------------------- */
valueAttribute: valueAtt
        {   if (parserData->valueAttributePresent ) 
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one value attribute allowed for this element");
            parserData->valueAttributePresent = true;
        };

valueAtt: valueAttEmpty | valueAttContent;

valueAttEmpty: EMPTYVALUEATT
{ parserData->valueAttribute = ""; };

valueAttContent: VALUEATT ATTRIBUTETEXT QUOTE 
{
    parserData->valueAttribute = $2; 
    free($2);
};

/* ----------------------------------------------------------------------- */
varTypeAttribute: varTypeAtt
        {   if (parserData->varTypeAttributePresent ) 
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one varType attribute allowed for this element");
            parserData->varTypeAttributePresent = true;
        };

varTypeAtt: varTypeAttEmpty | varTypeAttContent;

varTypeAttEmpty: EMPTYVARTYPEATT
{ parserData->varTypeAttribute = ""; };

varTypeAttContent: VARTYPEATT ATTRIBUTETEXT QUOTE 
{ 
    parserData->varTypeAttribute = $2; 
    free($2);
};




/*************************************************************************************
 *  There are so many numberOf... attributes that they warrant their own section...  *
 *************************************************************************************/
numberOfConAttribute: NUMBEROFCONATT quote INTEGER quote
{
    if (parserData->numberOfConAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfCon attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <con> cannot be negative");
    parserData->numberOfConAttributePresent = true;        
    parserData->numberOfCon = $3;
};

numberOfConstraintsAttribute: NUMBEROFCONSTRAINTSATT quote INTEGER quote 
{
    if (parserData->numberOfConstraintsPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfConstraints attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of constraints cannot be negative");
    parserData->numberOfConstraintsPresent = true;        
    parserData->tempInt = $3; 
};

numberOfElAttribute: NUMBEROFELATT quote INTEGER quote 
{
    if (osglData->osglNumberOfElPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfEl attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <el> cannot be negative");
    osglData->osglNumberOfElPresent = true;
    parserData->numberOf = $3; 
}; 

numberOfEnumerationsAttribute: NUMBEROFENUMERATIONSATT quote INTEGER quote 
{
    if (parserData->numberOfEnumerationsAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfEnumerations attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <enumeration> elements cannot be negative");
    parserData->numberOfEnumerationsAttributePresent = true;        
    parserData->numberOfEnumerations = $3; 
}; 

numberOfItemsAttribute: NUMBEROFITEMSATT quote INTEGER quote 
{    
   if (parserData->numberOfItemsPresent ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one numberOfItems attribute allowed");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of items cannot be negative");
    parserData->numberOfItemsPresent = true;
    parserData->numberOfItems = $3;
};

numberOfJobIDsATT: NUMBEROFJOBIDSATT QUOTE INTEGER QUOTE
{
    if ($3 < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Number of job IDs cannot be negative");
    else
        parserData->jobDependencies = new std::string[$3];
    parserData->numberOf = $3;
    parserData->kounter = 0;
};

numberOfObjAttribute: NUMBEROFOBJATT quote INTEGER quote
{
    if (parserData->numberOfObjAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfObj attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <obj> cannot be negative");
    parserData->numberOfObjAttributePresent = true;        
    parserData->numberOfObj = $3;
}; 

numberOfObjectivesAttribute: NUMBEROFOBJECTIVESATT quote INTEGER quote 
{
    if (parserData->numberOfObjectivesPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfObjectives attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of objectives cannot be negative");
    parserData->numberOfObjectivesPresent = true;
    parserData->tempInt = $3; 
};

numberOfOtherConstraintOptionsAttribute: NUMBEROFOTHERCONSTRAINTOPTIONSATT quote INTEGER quote 
{
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of other constraint options cannot be negative");
    parserData->tempInt = $3;
};

numberOfOtherObjectiveOptionsAttribute: NUMBEROFOTHEROBJECTIVEOPTIONSATT quote INTEGER quote 
{
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of other objective options cannot be negative");
    parserData->tempInt = $3;
};

numberOfOtherOptionsAttribute: NUMBEROFOTHEROPTIONSATT quote INTEGER quote
{
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of other options cannot be negative");
    parserData->tempInt = $3;
};

numberOfOtherVariableOptionsAttribute: NUMBEROFOTHERVARIABLEOPTIONSATT quote INTEGER quote 
{    
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of other variable options cannot be negative");
    parserData->tempInt = $3;
};

numberOfPathPairsAttribute: NUMBEROFPATHPAIRSATT QUOTE INTEGER QUOTE
{
    if ($3 < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Number of path pairs cannot be negative");
    else if ($3 > 0)
    {
        parserData->fromPaths = new std::string[$3];
        parserData->toPaths   = new std::string[$3];
        parserData->makeCopy  = new bool[$3];
    }
    parserData->numberOfPathPairs = $3;
    parserData->kounter = 0;
};

numberOfPathsAttribute: NUMBEROFPATHSATT QUOTE INTEGER QUOTE
{
    if ($3 < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Number of paths cannot be negative");
    else
        parserData->paths = new std::string[$3];
    parserData->numberOf = $3;
    parserData->kounter = 0;
};

numberOfProcessesATT: NUMBEROFPROCESSESATT QUOTE INTEGER QUOTE
{
    if ($3 < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Number of job IDs cannot be negative");
    else
        parserData->processesToKill = new std::string[$3];
    parserData->numberOf = $3;
    parserData->kounter = 0;
};


numberOfSolverOptionsAttribute: NUMBEROFSOLVEROPTIONSATT quote INTEGER quote 
{    
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of solver options cannot be negative");
    parserData->numberOfSolverOptions = $3;
};

numberOfVarAttribute: NUMBEROFVARATT quote INTEGER quote 
{
    if (parserData->numberOfVarAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfVar attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <var> cannot be negative");
    parserData->numberOfVarAttributePresent = true;        
    parserData->numberOfVar = $3; 
}; 

numberOfVariablesAttribute: NUMBEROFVARIABLESATT quote INTEGER quote 
{    if (parserData->numberOfVariablesPresent)

        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfVariables attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of variables cannot be negative");
    parserData->numberOfVariablesPresent = true;    
    parserData->tempInt = $3; 
};

//numberOfVarIdxAttribute: NUMBEROFVARIDXATT quote INTEGER quote 
//{
//    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <varIdx> cannot be negative");
//    parserData->numberOfVarIdx = $3; 
//}; 


/**
 *  <enumeration> lists occur three times in the OSoL schema:
 *  for variables, objectives and constraints. 
 *  The code below can be used for all three situations.
 */
otherEnumerationList: otherEnumeration | otherEnumerationList otherEnumeration;

otherEnumeration: otherEnumerationStart otherEnumerationAttributes otherEnumerationContent 
{     
    if (!parserData->ignoreDataAfterErrors)
        if (!osoption->setOtherOptionEnumeration(parserData->otherOptionType, 
                parserData->iOther,
                parserData->kounter,
                osglData->osglNumberOfEl, 
                parserData->valueAttribute, 
                parserData->descriptionAttribute, 
                osglData->osglIntArray) )
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <other> option enumeration failed");

    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
    parserData->kounter++;
};

otherEnumerationStart: ENUMERATIONSTART
{
    if (parserData->kounter >= parserData->numberOfEnumerations)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <enumeration> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    osglData->osglNumberOfElPresent = false;
    parserData->valueAttributePresent = false;
    parserData->descriptionAttributePresent = false;
    parserData->valueAttribute = "";
    parserData->descriptionAttribute = "";
};    

otherEnumerationAttributes: otherEnumerationAttList 
    {
        if(!osglData->osglNumberOfElPresent) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<other> element enumeration requires numberOfEl attribute"); 
        if(!parserData->valueAttributePresent) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<other> element enumeration requires value attribute"); 
    };
      
otherEnumerationAttList: | otherEnumerationAttList otherEnumerationATT;

otherEnumerationATT: 
    numberOfElAttribute 
    {
        osglData->osglCounter = 0; 
        osglData->osglNumberOfElPresent = true;
        osglData->osglNumberOfEl = parserData->numberOf;
        if (parserData->numberOf > 0)
            osglData->osglIntArray = new int[parserData->numberOf];
    } 
  | valueAttribute
  | descriptionAttribute
  ;


otherEnumerationContent: otherEnumerationEmpty | otherEnumerationLaden;

otherEnumerationEmpty: ENDOFELEMENT;


otherEnumerationLaden: GREATERTHAN otherEnumerationBody ENUMERATIONEND;

otherEnumerationBody:  osglIntArrayData;  


aNumber:
    INTEGER {parserData->tempVal = $1;}
  | DOUBLE  {parserData->tempVal = $1;};

//ElementValue: 
//    ELEMENTTEXT  { parserData->tempStr = $1;       /*free($1);*/ }
//  | INTEGER      { parserData->tempStr = os_dtoa_format($1); }
//  | DOUBLE       { parserData->tempStr = os_dtoa_format($1); };
  
quote: xmlWhiteSpace QUOTE;

xmlWhiteSpace:  | xmlWhiteSpace xmlWhiteSpaceChar;

xmlWhiteSpaceChar: ' ' 
                 | '\t'
                 | '\r'
                 | '\n';
            

/* $Id$ */
/** @file OSParseosgl.y.syntax
 *
 * @author  Horand Gassmann, Jun Ma, Kipp Martin 
 *
 * \remarks
 * Copyright (C) 2005-2014, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 *
 * This file contains parser elements that are contained in the OSgL schema
 * and are shared between several of the main schemas, OSiL, OSoL and OSrL.
 *
 * The code is maintained in such a way that it can be inserted into any one
 * of these parsers by a makefile with minimal changes. 
 * The only change required is to change every occurrence of the
 * placeholder "osoption, parserData, osglData, osnlData" to the appropriate reference, which is
 * for OSiL files "osinstance, parserData, osglData, osnlData", 
 * for OSoL files,  "osoption, parserData, osglData, osnlData", and
 * for OSrL files,  "osresult, parserData, osglData, osnlData".
 * Other schemas with their own separate syntax elements can be added as needed.
 * The makefile accomplishes this through maintaining each parser 
 * in several parts and to copy this include file between the OSxL syntax rules
 * and the postamble to make the final OSParseosxl.y file.
 * 
 */

/** ==========================================================================
 *    This portion parses a header object used in OSoL and OSrL schema files
 *  ==========================================================================
 */
osglFileHeader: headerElementStart headerElementContent;
 
headerElementStart: HEADERSTART
{
    osglData->fileName    = "";
    osglData->source      = "";
    osglData->description = "";
    osglData->fileCreator = "";
    osglData->licence     = "";
    osglData->fileNamePresent    = false;
    osglData->sourcePresent      = false;
    osglData->descriptionPresent = false;
    osglData->fileCreatorPresent = false;
    osglData->licencePresent     = false;
};

headerElementContent: headerElementEmpty | headerElementLaden;

headerElementEmpty: ENDOFELEMENT;

headerElementLaden: GREATERTHAN headerElementBody HEADEREND; 

headerElementBody: headerElementList;

headerElementList: | headerElementList headerChild;

headerChild:
    fileName 
  | fileSource 
  | fileDescription 
  | fileCreator 
  | fileLicence;

fileName: fileNameContent
{
    if (osglData->fileNamePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated header information: file name");
    else
        osglData->fileNamePresent = true;
};

fileNameContent: fileNameEmpty | fileNameLaden;

fileNameEmpty: FILENAMESTARTANDEND | FILENAMEEMPTY;

fileNameLaden: FILENAMESTART ITEMTEXT FILENAMEEND
{
    osglData->fileName = $2;
    free($2);
};

fileSource: fileSourceContent
{
    if (osglData->sourcePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated header information: source");
    else
        osglData->sourcePresent = true;
};

fileSourceContent: fileSourceEmpty | fileSourceLaden;

fileSourceEmpty: FILESOURCESTARTANDEND | FILESOURCEEMPTY;

fileSourceLaden: FILESOURCESTART ITEMTEXT FILESOURCEEND
{
    osglData->source = $2;
    free($2);
};

fileDescription: fileDescriptionContent
{
    if (osglData->descriptionPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated header information: description");
    else
        osglData->descriptionPresent = true;
};

fileDescriptionContent: fileDescriptionEmpty | fileDescriptionLaden;

fileDescriptionEmpty: FILEDESCRIPTIONSTARTANDEND | FILEDESCRIPTIONEMPTY;

fileDescriptionLaden: FILEDESCRIPTIONSTART ITEMTEXT FILEDESCRIPTIONEND
{
    osglData->description = $2;
    free($2);
};

fileCreator: fileCreatorContent
{
    if (osglData->fileCreatorPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated header information: file creator");
    else
        osglData->fileCreatorPresent = true;
};

fileCreatorContent: fileCreatorEmpty | fileCreatorLaden;

fileCreatorEmpty: FILECREATORSTARTANDEND | FILECREATOREMPTY;

fileCreatorLaden: FILECREATORSTART ITEMTEXT FILECREATOREND
{
    osglData->fileCreator = $2;
    free($2);
};

fileLicence: fileLicenceContent
{
    if (osglData->licencePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated header information: licence");
    else
        osglData->licencePresent = true;
};

fileLicenceContent: fileLicenceEmpty | fileLicenceLaden;

fileLicenceEmpty: FILELICENCESTARTANDEND | FILELICENCEEMPTY;

fileLicenceLaden: FILELICENCESTART ITEMTEXT FILELICENCEEND
{
    osglData->licence = $2;
    free($2);
};

/** ==========================================================================
 *         This portion parses the content of an IntVector <el> array
 *  ==========================================================================
 */

osglIntArrayData:
    osglIntVectorElArray 
    {
         if (osglData->osglCounter < osglData->osglNumberOfEl)
        {
std::cout << "expected " << osglData->osglNumberOfEl << " elements; got " << osglData->osglCounter << std::endl;
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "fewer data elements than specified");
            parserData->ignoreDataAfterErrors = true;
        }
    }
 | osglIntVectorBase64;

osglIntVectorElArray: | osglIntVectorElArray osglIntVectorEl;

osglIntVectorEl: osglIntVectorElStart osglIntVectorElAttributes osglIntVectorElContent;

osglIntVectorElStart: ELSTART
{    
    osglData->osglMultPresent = false;
    osglData->osglIncrPresent = false;
    osglData->osglMult = 1;
    osglData->osglIncr = 0;
};


osglIntVectorElAttributes: osglIntVectorElAttList;

osglIntVectorElAttList: | osglIntVectorElAttList osglIntVectorElAtt;

osglIntVectorElAtt: osglMultATT | osglIncrATT;

osglIntVectorElContent: GREATERTHAN INTEGER ELEND
{
    if (osglData->osglCounter + osglData->osglMult > osglData->osglNumberOfEl)
    {
std::cout << "IntVec: expected " << osglData->osglNumberOfEl << " elements; got " << osglData->osglCounter + osglData->osglMult << std::endl;
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more data elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    }
    else
        for (int i=0; i<osglData->osglMult; i++)
            osglData->osglIntArray[osglData->osglCounter++] = $2 + i*osglData->osglIncr;    
};

osglIntVectorBase64: BASE64START osglBase64SizeATT osglIntVectorBase64Content;


osglIntVectorBase64Content: osglIntVectorBase64Empty | osglIntVectorBase64Laden;

osglIntVectorBase64Empty: GREATERTHAN BASE64END | ENDOFELEMENT;


osglIntVectorBase64Laden: GREATERTHAN ELEMENTTEXT BASE64END
{
    char* b64string = $2;
    if( b64string == NULL) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "base 64 data expected"); 
    if (osglData->osglSize != sizeof(int))
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "base 64 encoded with a size of int different than on this machine"); 

    std::string base64decodeddata = Base64::decodeb64( b64string );
    int base64decodeddatalength = base64decodeddata.length();
    int *intvec = NULL;
    if ( parserData->numberOf != (base64decodeddatalength/osglData->osglSize) )
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "base 64 data length does not match numberOfEl"); 
    else
    {
        intvec = (int*)&base64decodeddata[0];
        for(int i = 0; i < (base64decodeddatalength/osglData->osglSize); i++)
        {
            osglData->osglIntArray[i] = *(intvec++);
        }
    }
    //delete[] b64string;
    free($2);
};

/** ==========================================================================
 *        This portion parses the content of a DoubleVector <el> element
 *  ==========================================================================
 */

osglDblArrayData: 
    osglDblVectorElArray 
    {
        if (osglData->osglCounter < osglData->osglNumberOfEl)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "fewer data elements than specified");
            parserData->ignoreDataAfterErrors = true;
        }
    }
 | osglDblVectorBase64;

osglDblVectorElArray: | osglDblVectorElArray osglDblVectorEl;

osglDblVectorEl: osglDblVectorElStart osglDblVectorElAttributes osglDblVectorElContent;

osglDblVectorElStart: ELSTART
{    
    osglData->osglMultPresent = false;
    osglData->osglIncrPresent = false;
    osglData->osglMult = 1;
};


osglDblVectorElAttributes: | osglMultATT;

osglDblVectorElContent: GREATERTHAN aNumber ELEND
{
    if (osglData->osglCounter + osglData->osglMult > osglData->osglNumberOfEl)
    {
std::cout << "DblVec: expected " << osglData->osglNumberOfEl << " elements; got " << osglData->osglCounter + osglData->osglMult << std::endl;
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more data elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    }
    else
        for (int i=0; i<osglData->osglMult; i++)
            osglData->osglDblArray[osglData->osglCounter++] = parserData->tempVal;    
};

osglDblVectorBase64: BASE64START osglBase64SizeATT osglDblVectorBase64Content;

osglDblVectorBase64Content: osglDblVectorBase64Empty | osglDblVectorBase64Laden;

osglDblVectorBase64Empty: GREATERTHAN BASE64END | ENDOFELEMENT;

osglDblVectorBase64Laden: GREATERTHAN ELEMENTTEXT BASE64END
{
    char* b64string = $2;
    if( b64string == NULL) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "base 64 data expected"); 
    if (osglData->osglSize != sizeof(int))
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "base 64 encoded with a size of int different than on this machine"); 

    std::string base64decodeddata = Base64::decodeb64( b64string );
    int base64decodeddatalength = base64decodeddata.length();
    double *dblvec = NULL;
    if ( parserData->numberOf != (base64decodeddatalength/osglData->osglSize) )
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "base 64 data length does not match numberOfEl"); 
    else
    {
        dblvec = (double*)&base64decodeddata[0];
        for(int i = 0; i < (base64decodeddatalength/osglData->osglSize); i++)
        {
            osglData->osglDblArray[i] = *(dblvec++);
        }
    }
    //delete[] b64string;
    free($2);
};


/** ==========================================================================
 *              This portion parses the content of a SparseVector object
 *  ==========================================================================
 */

osglSparseVector: osglSparseVectorNumberOfElATT GREATERTHAN osglSparseVectorIndexes osglSparseVectorValues
{
};

osglSparseVectorNumberOfElATT: osglNumberOfElATT
{
    osglData->osglCounter = 0; 
    if (osglData->osglNumberOfEl > 0)
    {
        osglData->osglIntArray = new    int[osglData->osglNumberOfEl];
        osglData->osglDblArray = new double[osglData->osglNumberOfEl];
    }
}; 

osglSparseVectorIndexes: INDEXESSTART GREATERTHAN osglIntVectorElArray INDEXESEND
{
    osglData->osglCounter = 0;
};

osglSparseVectorValues:  VALUESSTART  GREATERTHAN osglDblVectorElArray VALUESEND
{
    osglData->osglCounter = 0;
};


/** ==========================================================================
 *          This portion parses the content of a SparseIntVector object
 *  ==========================================================================
 */

osglSparseIntVector: osglSparseIntVectorNumberOfElATT GREATERTHAN osglSparseIntVectorIndexes osglSparseIntVectorValues
{
};

osglSparseIntVectorNumberOfElATT: osglNumberOfElATT
{
    osglData->osglCounter = 0; 
    if (osglData->osglNumberOfEl > 0)
    {
        osglData->osglIntArray = new int[osglData->osglNumberOfEl];
        osglData->osglValArray = new int[osglData->osglNumberOfEl];
    }
}; 

osglSparseIntVectorIndexes: INDEXESSTART GREATERTHAN osglIntVectorElArray INDEXESEND
{
    osglData->osglCounter = 0;
};

osglSparseIntVectorValues:  VALUESSTART  GREATERTHAN osglIntVectorElArray VALUESEND
{
    osglData->osglCounter = 0;
};

/** ===================================================================================
 *    This portion parses an OSMatrix object used in OSiL, OSoL and OSrL schema files
 *  ===================================================================================
 */

/**
 *  Note: A matrix is essentially a list of constructors.
 *  This is very similar to parsing an expression tree.
 */
osglMatrix: matrixStart matrixAttributes matrixContent
{
//  IMPORTANT -- HERE IS WHERE WE CREATE THE CONSTRUCTOR LISTS
    osglData->matrix[osglData->matrixCounter] = 
        ((OSMatrix*)osglData->mtxConstructorVec[0])->createConstructorTreeFromPrefix(osglData->mtxConstructorVec);
    osglData->matrix[osglData->matrixCounter]->idx = osglData->matrixCounter;
    osglData->matrixCounter++;
};
 
matrixStart: MATRIXSTART
{
    if (osglData->matrixCounter >= parserData->numberOfMatrices)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more matrices than specified");
    osglData->symmetryPresent = false;
    osglData->typePresent = false;
    osglData->numberOfRowsPresent = false;
    osglData->numberOfColumnsPresent = false;
    osglData->namePresent = false;
    osglData->mtxConstructorVec.clear();
    osglData->mtxBlkVec.clear();

    /**
     *  The <matrix> tag combines the functions of the <nl> tag and the top OSnLNode,
     *  so we also initial the storage vectors here
     */
    osglData->tempC = new OSMatrix();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->mtxBlkVec.push_back(osglData->tempC);
};

matrixAttributes: matrixAttributeList
{
    if (osglData->numberOfRowsPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "mandatory attribute numberOfRows is missing");    
    else
        ((OSMatrix*)osglData->tempC)->numberOfRows = osglData->numberOfRows;
    if (osglData->numberOfColumnsPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "mandatory attribute numberOfColumns is missing");
    else
        ((OSMatrix*)osglData->tempC)->numberOfColumns = osglData->numberOfColumns;
    if (osglData->symmetryPresent == true)
        ((OSMatrix*)osglData->tempC)->symmetry = (ENUM_MATRIX_SYMMETRY)returnMatrixSymmetry(osglData->symmetry);
    if (osglData->namePresent == true)
        ((OSMatrix*)osglData->tempC)->name = osglData->name;
    if (osglData->typePresent == true)
        ((OSMatrix*)osglData->tempC)->matrixType = (ENUM_MATRIX_TYPE)returnMatrixType(osglData->type);
};

matrixAttributeList: | matrixAttributeList matrixAttribute;

matrixAttribute:
      osglSymmetryATT
    | osglNumberOfRowsATT
    | osglNumberOfColumnsATT
    | osglMatrixNameATT
    | osglMatrixTypeATT
;

osglSymmetryATT: SYMMETRYATT ATTRIBUTETEXT QUOTE 
{ 
    if (osglData->symmetryPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one symmetry attribute in <matrix> element");
    osglData->symmetryPresent = true;   
    osglData->symmetry = $2; 
    free($2);
};

osglMatrixNameATT: NAMEATT ATTRIBUTETEXT QUOTE 
{ 
    if (osglData->namePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one name attribute in <matrix> element");
    osglData->namePresent = true;   
    osglData->name = $2; 
    free($2);
};

osglMatrixTypeATT: TYPEATT ATTRIBUTETEXT QUOTE 
{
    if (osglData->typePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one type attribute in <matrix> element");
    osglData->typePresent = true;
    osglData->type = $2; 
    free($2);
};

matrixContent: matrixEmpty | matrixLaden;

matrixEmpty: ENDOFELEMENT;

matrixLaden: GREATERTHAN matrixBody MATRIXEND
{
    osglData->mtxBlkVec.back()->m_mChildren = 
        new MatrixNode*[osglData->mtxBlkVec.back()->inumberOfChildren];
    osglData->mtxBlkVec.pop_back();
}; 

matrixBody: baseMatrix matrixConstructorList;

baseMatrix: | baseMatrixStart baseMatrixAttributes baseMatrixEnd
{
    osglData->mtxBlkVec.back()->inumberOfChildren++; 
};

baseMatrixStart: BASEMATRIXSTART
{
    osglData->tempC = new BaseMatrix();
    osglData->mtxConstructorVec.push_back(osglData->tempC);

    osglData->baseMatrixIdxPresent = false;
    osglData->targetMatrixFirstRowPresent = false;
    osglData->targetMatrixFirstColPresent = false;
    osglData->baseMatrixStartRowPresent = false;
    osglData->baseMatrixStartColPresent = false;
    osglData->baseMatrixEndRowPresent = false;
    osglData->baseMatrixEndColPresent = false;
    osglData->baseTransposePresent = false;
    osglData->scalarMultiplierPresent = false;
    osglData->baseMatrixEndRow = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfRows;
    osglData->baseMatrixEndCol = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfColumns;
};

baseMatrixAttributes: baseMatrixAttList
{
    if (osglData->baseMatrixIdxPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "mandatory attribute baseMatrixIdx is missing");
    else
        ((BaseMatrix*)osglData->tempC)->baseMatrixIdx = osglData->baseMatrixIdx;
    if (osglData->targetMatrixFirstRowPresent == true)
        ((BaseMatrix*)osglData->tempC)->targetMatrixFirstRow = osglData->targetMatrixFirstRow;
    if (osglData->targetMatrixFirstColPresent == true)
        ((BaseMatrix*)osglData->tempC)->targetMatrixFirstCol = osglData->targetMatrixFirstCol;
    if (osglData->baseMatrixStartRowPresent == true)
        ((BaseMatrix*)osglData->tempC)->baseMatrixStartRow = osglData->baseMatrixStartRow;
    if (osglData->baseMatrixStartColPresent == true)
        ((BaseMatrix*)osglData->tempC)->baseMatrixStartCol = osglData->baseMatrixStartCol;
    if (osglData->baseMatrixEndRowPresent == true)
        ((BaseMatrix*)osglData->tempC)->baseMatrixEndRow = osglData->baseMatrixEndRow;
    if (osglData->baseMatrixEndColPresent == true)
        ((BaseMatrix*)osglData->tempC)->baseMatrixEndCol = osglData->baseMatrixEndCol;
    if (osglData->baseTransposePresent == true)
        ((BaseMatrix*)osglData->tempC)->baseTranspose = osglData->baseTranspose;
    if (osglData->scalarMultiplierPresent == true)
        ((BaseMatrix*)osglData->tempC)->scalarMultiplier = osglData->scalarMultiplier;
};

baseMatrixAttList: | baseMatrixAttList baseMatrixAtt;

baseMatrixAtt:
      osglBaseMatrixIdxATT
    | osglTargetMatrixFirstRowATT
    | osglTargetMatrixFirstColATT
    | osglBaseMatrixStartRowATT
    | osglBaseMatrixStartColATT
    | osglBaseMatrixEndRowATT
    | osglBaseMatrixEndColATT
    | baseTransposeAttribute
    | osglScalarMultiplierATT;

osglBaseMatrixIdxATT: BASEMATRIXIDXATT QUOTE INTEGER QUOTE 
{ 
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->baseMatrixIdxPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one baseMatrixIdx attribute in <baseMatrix> element");
    if ($3 < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "baseMatrix idx cannot be negative");
    if ($3 > osglData->matrixCounter)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "baseMatrix idx exceeds number of matrices so far");
    ((MatrixType*)osglData->mtxBlkVec.back())->matrixType  = 
        mergeMatrixType(((MatrixType*)osglData->mtxBlkVec.back())->matrixType, osglData->matrix[$3]->matrixType);
    osglData->baseMatrixIdxPresent = true;   
    osglData->baseMatrixIdx = $3; 
};

osglTargetMatrixFirstRowATT: TARGETMATRIXFIRSTROWATT QUOTE INTEGER QUOTE 
{ 
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->targetMatrixFirstRowPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one targetMatrixFirstRow attribute in <baseMatrix> element");
    if ($3 < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "targetMatrix first row cannot be negative");
    osglData->targetMatrixFirstRowPresent = true;   
    osglData->targetMatrixFirstRow = $3; 
};

osglTargetMatrixFirstColATT: TARGETMATRIXFIRSTCOLATT QUOTE INTEGER QUOTE
{ 
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->targetMatrixFirstColPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one targetMatrixFirstCol attribute in <baseMatrix> element");
    if ($3 < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "targetMatrix first col cannot be negative");
    osglData->targetMatrixFirstColPresent = true;   
    osglData->targetMatrixFirstCol = $3; 
};

osglBaseMatrixStartRowATT: BASEMATRIXSTARTROWATT QUOTE INTEGER QUOTE
{ 
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->baseMatrixStartRowPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one baseMatrixStartRow attribute in <baseMatrix> element");
    if ($3 < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "baseMatrix first row cannot be negative");
    osglData->baseMatrixStartRowPresent = true;   
    osglData->baseMatrixStartRow = $3; 
};

osglBaseMatrixStartColATT: BASEMATRIXSTARTCOLATT QUOTE INTEGER QUOTE
{ 
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->baseMatrixStartColPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one baseMatrixStartCol attribute in <baseMatrix> element");
    if ($3 < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "baseMatrix first col cannot be negative");
    osglData->baseMatrixStartColPresent = true;   
    osglData->baseMatrixStartCol = $3; 
};

osglBaseMatrixEndRowATT: BASEMATRIXENDROWATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->baseMatrixEndRowPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one baseMatrixEndRow attribute in <baseMatrix> element");
    if ($3 < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "baseMatrix last row cannot be negative");
    if ($3 > ((MatrixType*)osglData->mtxBlkVec.back())->numberOfRows)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "baseMatrix last row exceeds matrix dimensions");
    osglData->baseMatrixEndRowPresent = true;   
    osglData->baseMatrixEndRow = $3; 
};

osglBaseMatrixEndColATT: BASEMATRIXENDCOLATT QUOTE INTEGER QUOTE
{ 
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->baseMatrixEndColPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one baseMatrixEndCol attribute in <baseMatrix> element");
    if ($3 < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "baseMatrix last col cannot be negative");
    if ($3 > ((MatrixType*)osglData->mtxBlkVec.back())->numberOfColumns)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "baseMatrix last col exceeds matrix dimensions");
    osglData->baseMatrixEndColPresent = true;   
    osglData->baseMatrixEndCol = $3; 
};

baseTransposeAttribute: osglBaseTransposeATT
{ 
    if (osglData->baseTransposePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one baseTranspose attribute in <baseMatrix> element");
    osglData->baseTransposePresent = true;   
};

osglBaseTransposeATT: baseTransposeAttEmpty | baseTransposeAttContent;

baseTransposeAttEmpty: EMPTYBASETRANSPOSEATT
{
    osglData->baseTranspose = true;
};

baseTransposeAttContent: BASETRANSPOSEATT ATTRIBUTETEXT quote 
{
    if      (strcmp($2,"false") == 0) osglData->baseTranspose = false;
    else if (strcmp($2,"true" ) == 0) osglData->baseTranspose = true;
    else parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "baseTranspose attribute in <baseMatrix> element must be \"true\" or \"false\"");
    free($2);
};

osglScalarMultiplierATT: SCALARMULTIPLIERATT QUOTE aNumber QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->scalarMultiplierPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one scalar multiplier attribute in <baseMatrix> element");
    osglData->scalarMultiplierPresent = true;   
    osglData->scalarMultiplier = parserData->tempVal;
};

baseMatrixEnd: GREATERTHAN BASEMATRIXEND | ENDOFELEMENT;

matrixConstructorList: | matrixConstructorList matrixConstructor
{
    osglData->mtxBlkVec.back()->inumberOfChildren++; 
};

matrixConstructor: matrixElements | matrixTransformation | matrixBlocks;

matrixElements: matrixElementsStart matrixElementsContent;


matrixElementsStart: ELEMENTSSTART
{
    osglData->tempC = new MatrixElements();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
};


matrixElementsContent: matrixElementsEmpty | matrixElementsLaden;

matrixElementsEmpty: ENDOFELEMENT;

matrixElementsLaden: GREATERTHAN constantElements varReferenceElements linearElements generalElements 
                                 objReferenceElements conReferenceElements matrixElementsEnd;

matrixElementsEnd: ELEMENTSEND;

constantElements: | constantElementsStart constantElementsAttributes GREATERTHAN constantElementsContent; 

constantElementsStart: CONSTANTELEMENTSSTART
{
    ((MatrixElements*)osglData->tempC)->constantElements = new ConstantMatrixElements(); 
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
};

constantElementsAttributes: constantElementsAttList
{
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<constantElements>: numberOfValues attribute missing");    
};

constantElementsAttList: | constantElementsAttList constantElementsAtt;

constantElementsAtt: 
    osglNumberOfValuesATT
    {
        ((MatrixElements*)osglData->tempC)->constantElements->numberOfValues = osglData->numberOfValues;
    }
  | osglRowMajorATT
    {
        ((MatrixElements*)osglData->tempC)->constantElements->rowMajor = osglData->rowMajor;
    }
;

constantElementsContent: constantElementsStartVector constantElementsNonzeros CONSTANTELEMENTSEND;

constantElementsNonzeros: | constantElementsIndexes constantElementsValues;

constantElementsStartVector: constantElementsStartVectorStart constantElementsStartVectorContent
{
    ((MatrixElements*)osglData->tempC)->constantElements->start = new IntVector();
    ((MatrixElements*)osglData->tempC)->constantElements->start->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->constantElements->start->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

constantElementsStartVectorStart: STARTVECTORSTART
{
    if (osglData->rowMajor == false)
        osglData->osglNumberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfColumns + 1;
    else
        osglData->osglNumberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfRows + 1;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
};

constantElementsStartVectorContent: constantElementsStartVectorEmpty | constantElementsStartVectorLaden;

constantElementsStartVectorEmpty: ENDOFELEMENT;

constantElementsStartVectorLaden: GREATERTHAN constantElementsStartVectorBody STARTVECTOREND;

constantElementsStartVectorBody: osglIntArrayData;


constantElementsIndexes: constantElementsIndexesStart constantElementsIndexesContent
{
    ((MatrixElements*)osglData->tempC)->constantElements->indexes = new IntVector();
    ((MatrixElements*)osglData->tempC)->constantElements->indexes->numberOfEl
        = ((MatrixElements*)osglData->tempC)->constantElements->numberOfValues;
    ((MatrixElements*)osglData->tempC)->constantElements->indexes->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

constantElementsIndexesStart: INDEXESSTART
{
    osglData->osglNumberOfEl = ((MatrixElements*)osglData->tempC)->constantElements->numberOfValues;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
};

constantElementsIndexesContent: constantElementsIndexesEmpty | constantElementsIndexesLaden;

constantElementsIndexesEmpty: ENDOFELEMENT;

constantElementsIndexesLaden: GREATERTHAN constantElementsIndexesBody INDEXESEND;

constantElementsIndexesBody: osglIntArrayData;


constantElementsValues: constantElementsValuesStart constantElementsValuesContent
{
    ((MatrixElements*)osglData->tempC)->constantElements->values = new DoubleVector();
    ((MatrixElements*)osglData->tempC)->constantElements->values->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->constantElements->values->el = osglData->osglDblArray;
    osglData->osglDblArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

constantElementsValuesStart: VALUESSTART
{
    osglData->osglNumberOfEl = ((MatrixElements*)osglData->tempC)->constantElements->numberOfValues;
    osglData->osglDblArray = new double[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
};

constantElementsValuesContent: constantElementsValuesEmpty | constantElementsValuesLaden;

constantElementsValuesEmpty: ENDOFELEMENT;

constantElementsValuesLaden: GREATERTHAN constantElementsValuesBody VALUESEND;

constantElementsValuesBody: osglDblArrayData;

varReferenceElements: | varReferenceElementsStart varReferenceElementsAttributes GREATERTHAN varReferenceElementsContent; 

varReferenceElementsStart: VARREFERENCEELEMENTSSTART
{
    ((MatrixElements*)osglData->tempC)->varReferenceElements = new VarReferenceMatrixElements();
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
};

varReferenceElementsAttributes: varReferenceElementsAttList
{
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<varReferenceElements>: numberOfValues attribute missing");    
};

varReferenceElementsAttList: | varReferenceElementsAttList varReferenceElementsAtt;

varReferenceElementsAtt: 
    osglNumberOfValuesATT
    {
        ((MatrixElements*)osglData->tempC)->varReferenceElements->numberOfValues = osglData->numberOfValues;
    }
  | osglRowMajorATT
    {
        ((MatrixElements*)osglData->tempC)->varReferenceElements->rowMajor = osglData->rowMajor;
    }
;

varReferenceElementsContent: varReferenceElementsStartVector varReferenceElementsNonzeros VARREFERENCEELEMENTSEND;

varReferenceElementsNonzeros: | varReferenceElementsIndexes varReferenceElementsValues;

varReferenceElementsStartVector: varReferenceElementsStartVectorStart varReferenceElementsStartVectorContent
{
    ((MatrixElements*)osglData->tempC)->varReferenceElements->start = new IntVector();
    ((MatrixElements*)osglData->tempC)->varReferenceElements->start->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->varReferenceElements->start->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

varReferenceElementsStartVectorStart: STARTVECTORSTART
{
    if (osglData->rowMajor == false)
        osglData->osglNumberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfColumns + 1;
    else
        osglData->osglNumberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfRows + 1;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
};

varReferenceElementsStartVectorContent: varReferenceElementsStartVectorEmpty | varReferenceElementsStartVectorLaden;

varReferenceElementsStartVectorEmpty: ENDOFELEMENT;

varReferenceElementsStartVectorLaden: GREATERTHAN varReferenceElementsStartVectorBody STARTVECTOREND;

varReferenceElementsStartVectorBody:  osglIntArrayData;

varReferenceElementsIndexes: varReferenceElementsIndexesStart varReferenceElementsIndexesContent
{
    ((MatrixElements*)osglData->tempC)->varReferenceElements->indexes = new IntVector();
    ((MatrixElements*)osglData->tempC)->varReferenceElements->indexes->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->varReferenceElements->indexes->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

varReferenceElementsIndexesStart: INDEXESSTART
{
    osglData->osglNumberOfEl = ((MatrixElements*)osglData->tempC)->varReferenceElements->numberOfValues;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
};

varReferenceElementsIndexesContent:varReferenceElementsIndexesEmpty | varReferenceElementsIndexesLaden;

varReferenceElementsIndexesEmpty: ENDOFELEMENT;

varReferenceElementsIndexesLaden: GREATERTHAN varReferenceElementsIndexesBody INDEXESEND;

varReferenceElementsIndexesBody: osglIntArrayData;


varReferenceElementsValues: varReferenceElementsValuesStart varReferenceElementsValuesContent
{
    ((MatrixElements*)osglData->tempC)->varReferenceElements->values = new IntVector();
    ((MatrixElements*)osglData->tempC)->varReferenceElements->values->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->varReferenceElements->values->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

varReferenceElementsValuesStart: VALUESSTART
{
    osglData->osglNumberOfEl = ((MatrixElements*)osglData->tempC)->varReferenceElements->numberOfValues;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
};

varReferenceElementsValuesContent: varReferenceElementsValuesEmpty | varReferenceElementsValuesLaden;

varReferenceElementsValuesEmpty: ENDOFELEMENT;

varReferenceElementsValuesLaden: GREATERTHAN varReferenceElementsValuesBody VALUESEND;

varReferenceElementsValuesBody: osglIntArrayData;

linearElements: | linearElementsStart linearElementsAttributes GREATERTHAN linearElementsContent; 

linearElementsStart: LINEARELEMENTSSTART
{
    ((MatrixElements*)osglData->tempC)->linearElements = new LinearMatrixElements();
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
};

linearElementsAttributes: linearElementsAttList
{
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<linearElements>: numberOfValues attribute missing");    
};

linearElementsAttList: | linearElementsAttList linearElementsAtt;

linearElementsAtt: 
    osglNumberOfValuesATT
    {
        ((MatrixElements*)osglData->tempC)->linearElements->numberOfValues = osglData->numberOfValues;
    }
  | osglRowMajorATT
    {
        ((MatrixElements*)osglData->tempC)->linearElements->rowMajor = osglData->rowMajor;
    }
;

linearElementsContent: linearElementsStartVector linearElementsNonzeros LINEARELEMENTSEND;

linearElementsNonzeros: | linearElementsIndexes linearElementsValues;

linearElementsStartVector: linearElementsStartVectorStart linearElementsStartVectorContent
{
    ((MatrixElements*)osglData->tempC)->linearElements->start = new IntVector();
    ((MatrixElements*)osglData->tempC)->linearElements->start->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->linearElements->start->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

linearElementsStartVectorStart: STARTVECTORSTART
{
    if (osglData->rowMajor == false)
        osglData->osglNumberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfColumns + 1;
    else
        osglData->osglNumberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfRows + 1;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglNumberOfElPresent = false;
    osglData->osglCounter = 0;
};

linearElementsStartVectorContent: linearElementsStartVectorEmpty | linearElementsStartVectorLaden;

linearElementsStartVectorEmpty: ENDOFELEMENT;

linearElementsStartVectorLaden: GREATERTHAN linearElementsStartVectorBody STARTVECTOREND;

linearElementsStartVectorBody:  osglIntArrayData;


linearElementsIndexes: linearElementsIndexesStart linearElementsIndexesContent
{
    ((MatrixElements*)osglData->tempC)->linearElements->indexes = new IntVector();
    ((MatrixElements*)osglData->tempC)->linearElements->indexes->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->linearElements->indexes->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

linearElementsIndexesStart: INDEXESSTART
{
    osglData->osglNumberOfEl = ((MatrixElements*)osglData->tempC)->linearElements->numberOfValues;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
};

linearElementsIndexesContent: linearElementsIndexesEmpty | linearElementsIndexesLaden;

linearElementsIndexesEmpty: ENDOFELEMENT;

linearElementsIndexesLaden: GREATERTHAN linearElementsIndexesBody INDEXESEND;

linearElementsIndexesBody: osglIntArrayData;

linearElementsValues:
    {
        if (osglData->osglNumberOfNonzeros > 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected <values> element");
    };    
  | 
    linearElementsValuesStart linearElementsValuesContent
    {
        if (osglData->osglNumberOfNonzeros > osglData->osglNonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few <el> elements");
        else if (osglData->osglNumberOfNonzeros < osglData->osglNonzeroCounter)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too many <el> elements");        
        ((MatrixElements*)osglData->tempC)->linearElements->values->numberOfEl = osglData->osglNumberOfEl;
        parserData->suppressFurtherErrorMessages = false;
        parserData->ignoreDataAfterErrors = false;        
    };

linearElementsValuesStart: VALUESSTART
{
    osglData->osglNumberOfNonzeros = ((MatrixElements*)osglData->tempC)->linearElements->numberOfValues;
    osglData->osglNonzeroCounter = 0;
    ((MatrixElements*)osglData->tempC)->linearElements->values = new LinearMatrixValues();
    ((MatrixElements*)osglData->tempC)->linearElements->values->numberOfEl
        = ((MatrixElements*)osglData->tempC)->linearElements->numberOfValues;    
    ((MatrixElements*)osglData->tempC)->linearElements->values->el
        = new LinearMatrixElement*[((MatrixElements*)osglData->tempC)->linearElements->numberOfValues]; 
    for (int i=0; i < ((MatrixElements*)osglData->tempC)->linearElements->numberOfValues; i++)
        ((MatrixElements*)osglData->tempC)->linearElements->values->el[i]
            = new LinearMatrixElement(); 
    osglData->osglCounter = 0;
    osglData->numberOfVarIdxPresent = false;
};

linearElementsValuesContent: linearElementsValuesEmpty | linearElementsValuesLaden;

linearElementsValuesEmpty: ENDOFELEMENT;

linearElementsValuesLaden: GREATERTHAN linearElementsValuesBody VALUESEND;

linearElementsValuesBody: linearElementsValuesElList;

linearElementsValuesElList:  | linearElementsValuesElList linearElementsValuesEl;

linearElementsValuesEl: linearElementsValuesElStart linearElementsValuesElAttributes linearElementsValuesElContent
{
    osglData->osglNonzeroCounter++;
    if (osglData->osglNonzeroCounter > osglData->osglNumberOfNonzeros)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "linear matrix elements: too many nonzeros");    
        
};

linearElementsValuesElStart: ELSTART
{
    osglData->numberOfVarIdxPresent = false;
    osglData->osglConstantPresent = false;
};  

linearElementsValuesElAttributes: linearElementsValuesElAttList
{
    if (!osglData->numberOfVarIdxPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfVarIdx attribute missing");
    ((MatrixElements*)osglData->tempC)->linearElements->values->el[osglData->osglNonzeroCounter]->numberOfVarIdx
        = osglData->numberOfVarIdx;
    ((MatrixElements*)osglData->tempC)->linearElements->values->el[osglData->osglNonzeroCounter]->varIdx
        = new LinearMatrixElementTerm*[osglData->numberOfVarIdx];
    osglData->osglCounter = 0;
};

linearElementsValuesElAttList: | linearElementsValuesElAttList linearElementsValuesElAtt;

linearElementsValuesElAtt: 
      osglNumberOfVarIdxATT
    | osglConstantATT;

osglConstantATT: CONSTANTATT QUOTE aNumber QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->osglConstantPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "linear matrix elements: duplicate constant");    
    else
    {
        ((MatrixElements*)osglData->tempC)->linearElements->values->el[osglData->osglNonzeroCounter]->constant
             = parserData->tempVal;
        osglData->osglConstantPresent = true;
    }
};

linearElementsValuesElContent: linearElementsValuesElEmpty | linearElementsValuesElLaden;

linearElementsValuesElEmpty: ENDOFELEMENT;

linearElementsValuesElLaden: GREATERTHAN linearElementsValuesVarIdxList ELEND;

linearElementsValuesVarIdxList: | linearElementsValuesVarIdxList linearElementsValuesVarIdx;

linearElementsValuesVarIdx: 
    linearElementsValuesVarIdxStart osglLinearElementsValuesVarIdxCoefATT linearElementsValuesVarIdxContent;

linearElementsValuesVarIdxStart: VARIDXSTART
{
    osglData->osglCoefPresent = false;
    osglData->osglCoef = 1.0;
    ((MatrixElements*)osglData->tempC)->linearElements->values->el[osglData->osglNonzeroCounter]->varIdx[osglData->osglCounter]
        = new LinearMatrixElementTerm();
};

osglLinearElementsValuesVarIdxCoefATT: | COEFATT QUOTE aNumber QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    ((MatrixElements*)osglData->tempC)->linearElements->values->el[osglData->osglNonzeroCounter]->varIdx[osglData->osglCounter]->coef = parserData->tempVal;
}; 

linearElementsValuesVarIdxContent: GREATERTHAN INTEGER VARIDXEND
{
    ((MatrixElements*)osglData->tempC)->linearElements->values->el[osglData->osglNonzeroCounter]->varIdx[osglData->osglCounter]->idx = $2;
    osglData->osglCounter++;
};


generalElements: | generalElementsStart generalElementsAttributes GREATERTHAN generalElementsContent; 

generalElementsStart: GENERALELEMENTSSTART
{
    ((MatrixElements*)osglData->tempC)->generalElements = new GeneralMatrixElements();
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
};

generalElementsAttributes: generalElementsAttList
{
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<generalElements>: numberOfValues attribute missing");    
};

generalElementsAttList: | generalElementsAttList generalElementsAtt;

generalElementsAtt: 
    osglNumberOfValuesATT
    {
        ((MatrixElements*)osglData->tempC)->generalElements->numberOfValues = osglData->numberOfValues;
    }
  | osglRowMajorATT
    {
        ((MatrixElements*)osglData->tempC)->generalElements->rowMajor = osglData->rowMajor;
    }
;

generalElementsContent: generalElementsStartVector generalElementsNonzeros GENERALELEMENTSEND;

generalElementsNonzeros: | generalElementsIndexes generalElementsValues;

generalElementsStartVector: generalElementsStartVectorStart generalElementsStartVectorContent
{
    ((MatrixElements*)osglData->tempC)->generalElements->start = new IntVector();
    ((MatrixElements*)osglData->tempC)->generalElements->start->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->generalElements->start->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

generalElementsStartVectorStart: STARTVECTORSTART
{
    if (osglData->rowMajor == false)
        osglData->osglNumberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfColumns + 1;
    else
        osglData->osglNumberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfRows + 1;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglNumberOfElPresent = false;
    osglData->osglCounter = 0;
};

generalElementsStartVectorContent: generalElementsStartVectorEmpty | generalElementsStartVectorLaden;

generalElementsStartVectorEmpty: ENDOFELEMENT;

generalElementsStartVectorLaden: GREATERTHAN generalElementsStartVectorBody STARTVECTOREND;

generalElementsStartVectorBody:  osglIntArrayData;


generalElementsIndexes: generalElementsIndexesStart generalElementsIndexesContent
{
    ((MatrixElements*)osglData->tempC)->generalElements->indexes = new IntVector();
    ((MatrixElements*)osglData->tempC)->generalElements->indexes->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->generalElements->indexes->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

generalElementsIndexesStart: INDEXESSTART
{
    osglData->osglNumberOfEl = ((MatrixElements*)osglData->tempC)->generalElements->numberOfValues;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
};

generalElementsIndexesContent: generalElementsIndexesEmpty | generalElementsIndexesLaden;

generalElementsIndexesEmpty: ENDOFELEMENT;

generalElementsIndexesLaden: GREATERTHAN generalElementsIndexesBody INDEXESEND;

generalElementsIndexesBody: osglIntArrayData;

generalElementsValues:
    | generalElementsValuesStart generalElementsValuesContent;

generalElementsValuesStart: VALUESSTART
{
    osglData->osglNonzeroCounter = 0;
    osglData->osglNumberOfNonzeros = ((MatrixElements*)osglData->tempC)->generalElements->numberOfValues;

    ((MatrixElements*)osglData->tempC)->generalElements->values = new GeneralMatrixValues();
    ((MatrixElements*)osglData->tempC)->generalElements->values->numberOfEl
        = osglData->osglNumberOfNonzeros;
    ((MatrixElements*)osglData->tempC)->generalElements->values->el
        = new ScalarExpressionTree*[osglData->osglNumberOfNonzeros];

    for (int i=0; i<osglData->osglNumberOfNonzeros; i++)
        ((MatrixElements*)osglData->tempC)->generalElements->values->el[i] = new ScalarExpressionTree();
};

generalElementsValuesContent: generalElementsValuesEmpty | generalElementsValuesLaden;

generalElementsValuesEmpty: ENDOFELEMENT;

generalElementsValuesLaden: GREATERTHAN generalElementsElList VALUESEND;

generalElementsElList:  | generalElementsElList generalElementsEl;

generalElementsEl: generalElementsElStart generalElementsElContent;

generalElementsElStart: ELSTART
    {
        if (osglData->osglNonzeroCounter >= osglData->osglNumberOfNonzeros) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <el> terms greater than expected");
        // clear the vectors of pointers
        osnlData->nlNodeVec.clear();
        osnlData->sumVec.clear();
        osnlData->allDiffVec.clear();
        osnlData->maxVec.clear();
        osnlData->minVec.clear();
        osnlData->productVec.clear();
        osnlData->matrixSumVec.clear();
        osnlData->matrixProductVec.clear();
    };

generalElementsElContent: generalElementsElEmpty | generalElementsElLaden;

generalElementsElEmpty: ENDOFELEMENT;

generalElementsElLaden: GREATERTHAN nlnode ELEND
    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE

        ((MatrixElements*)osglData->tempC)->generalElements->values->el[osglData->osglNonzeroCounter]->m_treeRoot = 
            ((OSnLNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
        osglData->osglNonzeroCounter++;
    };


conReferenceElements: | conReferenceElementsStart conReferenceElementsAttributes GREATERTHAN conReferenceElementsContent; 

conReferenceElementsStart: CONREFERENCEELEMENTSSTART
{
    ((MatrixElements*)osglData->tempC)->conReferenceElements = new ConReferenceMatrixElements();
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
};

conReferenceElementsAttributes: conReferenceElementsAttList
{
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<conReferenceElements>: numberOfValues attribute missing");    
};

conReferenceElementsAttList: | conReferenceElementsAttList conReferenceElementsAtt;

conReferenceElementsAtt: 
    osglNumberOfValuesATT
    {
        ((MatrixElements*)osglData->tempC)->conReferenceElements->numberOfValues = osglData->numberOfValues;
    }
  | osglRowMajorATT
    {
        ((MatrixElements*)osglData->tempC)->conReferenceElements->rowMajor = osglData->rowMajor;
    }
;

conReferenceElementsContent: conReferenceElementsStartVector conReferenceElementsNonzeros CONREFERENCEELEMENTSEND;

conReferenceElementsNonzeros: | conReferenceElementsIndexes conReferenceElementsValues;

conReferenceElementsStartVector: conReferenceElementsStartVectorStart conReferenceElementsStartVectorContent
{
    ((MatrixElements*)osglData->tempC)->conReferenceElements->start = new IntVector();
    ((MatrixElements*)osglData->tempC)->conReferenceElements->start->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->conReferenceElements->start->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

conReferenceElementsStartVectorStart: STARTVECTORSTART
{
    if (osglData->rowMajor == false)
        osglData->osglNumberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfColumns + 1;
    else
        osglData->osglNumberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfRows + 1;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglNumberOfElPresent = false;
    osglData->osglCounter = 0;
};

conReferenceElementsStartVectorContent: conReferenceElementsStartVectorEmpty | conReferenceElementsStartVectorLaden;

conReferenceElementsStartVectorEmpty: ENDOFELEMENT;

conReferenceElementsStartVectorLaden: GREATERTHAN conReferenceElementsStartVectorBody STARTVECTOREND;

conReferenceElementsStartVectorBody:  osglIntArrayData;

conReferenceElementsIndexes: conReferenceElementsIndexesStart conReferenceElementsIndexesContent
{
    ((MatrixElements*)osglData->tempC)->conReferenceElements->indexes = new IntVector();
    ((MatrixElements*)osglData->tempC)->conReferenceElements->indexes->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->conReferenceElements->indexes->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

conReferenceElementsIndexesStart: INDEXESSTART
{
    osglData->osglNumberOfEl = ((MatrixElements*)osglData->tempC)->conReferenceElements->numberOfValues;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
};

conReferenceElementsIndexesContent:conReferenceElementsIndexesEmpty | conReferenceElementsIndexesLaden;

conReferenceElementsIndexesEmpty: ENDOFELEMENT;

conReferenceElementsIndexesLaden: GREATERTHAN conReferenceElementsIndexesBody INDEXESEND;

conReferenceElementsIndexesBody: osglIntArrayData;


conReferenceElementsValues: conReferenceElementsValuesStart conReferenceElementsValuesContent
{
    ((MatrixElements*)osglData->tempC)->conReferenceElements->values = new IntVector();
    ((MatrixElements*)osglData->tempC)->conReferenceElements->values->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->conReferenceElements->values->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

conReferenceElementsValuesStart: VALUESSTART
{
    osglData->osglNumberOfEl = ((MatrixElements*)osglData->tempC)->conReferenceElements->numberOfValues;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
};

conReferenceElementsValuesContent: conReferenceElementsValuesEmpty | conReferenceElementsValuesLaden;

conReferenceElementsValuesEmpty: ENDOFELEMENT;

conReferenceElementsValuesLaden: GREATERTHAN conReferenceElementsValuesBody VALUESEND;

conReferenceElementsValuesBody: osglIntArrayData;

objReferenceElements: | objReferenceElementsStart objReferenceElementsAttributes GREATERTHAN objReferenceElementsContent; 

objReferenceElementsStart: OBJREFERENCEELEMENTSSTART
{
    ((MatrixElements*)osglData->tempC)->objReferenceElements = new ObjReferenceMatrixElements();
    osglData->numberOfValuesPresent = false;        
    osglData->rowMajorPresent = false;
    osglData->rowMajor = false;
};

objReferenceElementsAttributes: objReferenceElementsAttList
{
    if (osglData->numberOfValuesPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<objReferenceElements>: numberOfValues attribute missing");    
};

objReferenceElementsAttList: | objReferenceElementsAttList objReferenceElementsAtt;

objReferenceElementsAtt: 
    osglNumberOfValuesATT
    {
        ((MatrixElements*)osglData->tempC)->objReferenceElements->numberOfValues = osglData->numberOfValues;
    }
  | osglRowMajorATT
    {
        ((MatrixElements*)osglData->tempC)->objReferenceElements->rowMajor = osglData->rowMajor;
    }
;

objReferenceElementsContent: objReferenceElementsStartVector objReferenceElementsNonzeros OBJREFERENCEELEMENTSEND;

objReferenceElementsNonzeros: | objReferenceElementsIndexes objReferenceElementsValues;

objReferenceElementsStartVector: objReferenceElementsStartVectorStart objReferenceElementsStartVectorContent
{
    ((MatrixElements*)osglData->tempC)->objReferenceElements->start = new IntVector();
    ((MatrixElements*)osglData->tempC)->objReferenceElements->start->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->objReferenceElements->start->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

objReferenceElementsStartVectorStart: STARTVECTORSTART
{
    if (osglData->rowMajor == false)
        osglData->osglNumberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfColumns + 1;
    else
        osglData->osglNumberOfEl = ((MatrixType*)osglData->mtxBlkVec.back())->numberOfRows + 1;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglNumberOfElPresent = false;
    osglData->osglCounter = 0;
};

objReferenceElementsStartVectorContent: objReferenceElementsStartVectorEmpty | objReferenceElementsStartVectorLaden;

objReferenceElementsStartVectorEmpty: ENDOFELEMENT;

objReferenceElementsStartVectorLaden: GREATERTHAN objReferenceElementsStartVectorBody STARTVECTOREND;

objReferenceElementsStartVectorBody:  osglIntArrayData;


objReferenceElementsIndexes: objReferenceElementsIndexesStart objReferenceElementsIndexesContent
{
    ((MatrixElements*)osglData->tempC)->objReferenceElements->indexes = new IntVector();
    ((MatrixElements*)osglData->tempC)->objReferenceElements->indexes->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->objReferenceElements->indexes->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

objReferenceElementsIndexesStart: INDEXESSTART
{
    osglData->osglNumberOfEl = ((MatrixElements*)osglData->tempC)->objReferenceElements->numberOfValues;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
};

objReferenceElementsIndexesContent:objReferenceElementsIndexesEmpty | objReferenceElementsIndexesLaden;

objReferenceElementsIndexesEmpty: ENDOFELEMENT;

objReferenceElementsIndexesLaden: GREATERTHAN objReferenceElementsIndexesBody INDEXESEND;

objReferenceElementsIndexesBody: osglIntArrayData;


objReferenceElementsValues: objReferenceElementsValuesStart objReferenceElementsValuesContent
{
    ((MatrixElements*)osglData->tempC)->objReferenceElements->values = new IntVector();
    ((MatrixElements*)osglData->tempC)->objReferenceElements->values->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixElements*)osglData->tempC)->objReferenceElements->values->el = osglData->osglIntArray;
    osglData->osglIntArray = NULL;   // to facilitate garbage collection without a segfault
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

objReferenceElementsValuesStart: VALUESSTART
{
    osglData->osglNumberOfEl = ((MatrixElements*)osglData->tempC)->objReferenceElements->numberOfValues;
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
    osglData->osglCounter = 0;
};

objReferenceElementsValuesContent: objReferenceElementsValuesEmpty | objReferenceElementsValuesLaden;

objReferenceElementsValuesEmpty: ENDOFELEMENT;

objReferenceElementsValuesLaden: GREATERTHAN objReferenceElementsValuesBody VALUESEND;

objReferenceElementsValuesBody: osglIntArrayData;


matrixTransformation: matrixTransformationStart GREATERTHAN OSnLMNode matrixTransformationEnd
{
//    osglData->matrix->matrixConstructor.push_back(osglData->tempC);
};

matrixTransformationStart: TRANSFORMATIONSTART
{
    osglData->tempC = new MatrixTransformation();
    osglData->mtxConstructorVec.push_back(osglData->tempC);

    // clear the vectors of pointers
    osnlData->nlNodeVec.clear();
    osnlData->sumVec.clear();
    osnlData->allDiffVec.clear();
    osnlData->maxVec.clear();
    osnlData->minVec.clear();
    osnlData->productVec.clear();
    osnlData->matrixSumVec.clear();
    osnlData->matrixProductVec.clear();
};

matrixTransformationEnd: TRANSFORMATIONEND
{
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
    ((MatrixTransformation*)osglData->tempC)->transformation = 
        ((OSnLMNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
};

matrixBlocks: matrixBlocksStart matrixBlocksAttributes matrixBlocksContent
{
    // clean up temporary arrays without deleting the information
    osglData->rowOffsets.back() = NULL;
    osglData->colOffsets.back() = NULL;
    osglData->rowOffsets.pop_back();
    osglData->colOffsets.pop_back();
};

matrixBlocksStart: BLOCKSSTART
{
    osglData->tempC = new MatrixBlocks();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->numberOfBlocksPresent = false;
};

matrixBlocksAttributes: osglNumberOfBlocksATT
{
    ((MatrixBlocks*)osglData->tempC)->numberOfBlocks    = osglData->numberOfBlocks;
    ((MatrixBlocks*)osglData->tempC)->inumberOfChildren = osglData->numberOfBlocks;
    ((MatrixBlocks*)osglData->tempC)->m_mChildren       = new MatrixNode*[osglData->numberOfBlocks];
};

matrixBlocksContent: GREATERTHAN colOffsets rowOffsets blockList matrixBlocksEnd;

matrixBlocksEnd: BLOCKSEND;

colOffsets: colOffsetsStart colOffsetsNumberOfElAttribute colOffsetsContent
{
    if (osglData->osglCounter != osglData->osglNumberOfEl)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of colOffsets does not match numberOfEl");
    ((MatrixBlocks*)osglData->tempC)->colOffsets = new IntVector();
    ((MatrixBlocks*)osglData->tempC)->colOffsets->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixBlocks*)osglData->tempC)->colOffsets->el = osglData->osglIntArray;
    osglData->colOffsets.push_back(osglData->osglIntArray);
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

colOffsetsStart: COLOFFSETSSTART
{
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
};

colOffsetsNumberOfElAttribute: osglNumberOfElATT
{
    osglData->osglCounter = 0; 
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
}; 

colOffsetsContent: colOffsetsEmpty | colOffsetsLaden;

colOffsetsEmpty: ENDOFELEMENT;

colOffsetsLaden: GREATERTHAN colOffsetsBody COLOFFSETSEND;

colOffsetsBody:  osglIntArrayData;

rowOffsets: rowOffsetsStart rowOffsetsNumberOfElAttribute rowOffsetsContent
{
    ((MatrixBlocks*)osglData->tempC)->rowOffsets = new IntVector();
    ((MatrixBlocks*)osglData->tempC)->rowOffsets->numberOfEl = osglData->osglNumberOfEl;
    ((MatrixBlocks*)osglData->tempC)->rowOffsets->el = osglData->osglIntArray;
    osglData->rowOffsets.push_back(osglData->osglIntArray);
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
};

rowOffsetsStart: ROWOFFSETSSTART
{
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent = false;
};

rowOffsetsNumberOfElAttribute: osglNumberOfElATT
{
    osglData->osglCounter = 0; 
    osglData->osglIntArray = new int[osglData->osglNumberOfEl];
}; 

rowOffsetsContent: rowOffsetsEmpty | rowOffsetsLaden;

rowOffsetsEmpty: ENDOFELEMENT;

rowOffsetsLaden: GREATERTHAN rowOffsetsBody ROWOFFSETSEND;

rowOffsetsBody:  osglIntArrayData;

blockList: | blockList matrixBlock;

matrixBlock: matrixBlockStart matrixBlockAttributes matrixBlockContent
{
    osglData->mtxBlkVec.pop_back();
};

matrixBlockStart: BLOCKSTART
{
    osglData->tempC = new MatrixBlock();
    osglData->mtxConstructorVec.push_back(osglData->tempC);
    osglData->mtxBlkVec.push_back(osglData->tempC);

    osglData->symmetryPresent = false;
    osglData->blockRowIdxPresent = false;
    osglData->blockColIdxPresent = false;   
}; 

matrixBlockAttributes: matrixBlockAttList;

matrixBlockAttList: | matrixBlockAttList matrixBlockAtt;

matrixBlockAtt:
      osglBlockRowIdxATT
    | osglBlockColIdxATT 
    | osglSymmetryATT
    {
        if (verifyMatrixSymmetry(osglData->symmetry) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "symmetry type not recognized");
        parserData->errorText = NULL;
    };

osglBlockRowIdxATT: BLOCKROWIDXATT quote INTEGER quote
{
    if (osglData->blockRowIdxPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "blockRowIdx attribute previously set");
    else
    {
        if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "blockRowIdx cannot be negative");
        osglData->blockRowIdxPresent = true;        
        osglData->blockRowIdx = $3;       
        ((MatrixBlock*)osglData->tempC)->blockRowIdx = $3;
    }

    // compute the size of the block
    ((MatrixBlock*)osglData->tempC)->numberOfRows 
        = osglData->rowOffsets.back()[osglData->blockRowIdx+1] 
        - osglData->rowOffsets.back()[osglData->blockRowIdx];
};

osglBlockColIdxATT: BLOCKCOLIDXATT quote INTEGER quote
{
    if (osglData->blockColIdxPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "blockColIdx attribute previously set");
    else
    {
        if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "blockColIdx cannot be negative");
        osglData->blockColIdxPresent = true;
        osglData->blockColIdx = $3;       
        ((MatrixBlock*)osglData->tempC)->blockColIdx = $3;
    }

    // compute the size of the block
    ((MatrixBlock*)osglData->tempC)->numberOfColumns 
        = osglData->colOffsets.back()[osglData->blockColIdx+1] 
        - osglData->colOffsets.back()[osglData->blockColIdx];
};

matrixBlockContent: blockEmpty | blockLaden;

blockEmpty: ENDOFELEMENT;

blockLaden: GREATERTHAN blockBody BLOCKEND
{
    osglData->mtxBlkVec.back()->m_mChildren = 
        new MatrixNode*[osglData->mtxBlkVec.back()->inumberOfChildren];
}; 

blockBody: baseMatrix matrixConstructorList;

osglNumberOfBlocksATT: NUMBEROFBLOCKSATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfBlocksPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfBlocks attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <blocks> cannot be negative");
    osglData->numberOfBlocksPresent = true;        
    osglData->numberOfBlocks = $3;
};

osglNumberOfColumnsATT: NUMBEROFCOLUMNSATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfColumnsPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfColumns attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <blocks> cannot be negative");
    osglData->numberOfColumnsPresent = true;        
    osglData->numberOfColumns = $3;
};

osglNumberOfElATT: NUMBEROFELATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->osglNumberOfElPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfEl attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <el> cannot be negative");
    osglData->osglNumberOfElPresent = true;        
    osglData->osglNumberOfEl = $3;
};

osglNumberOfRowsATT: NUMBEROFROWSATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfRowsPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfRows attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <rows> cannot be negative");
    osglData->numberOfRowsPresent = true;        
    osglData->numberOfRows = $3;
};

osglNumberOfValuesATT: NUMBEROFVALUESATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfValuesPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfValues attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <values> cannot be negative");
    osglData->numberOfValuesPresent = true;        
    osglData->numberOfValues = $3;
};

osglNumberOfVarIdxATT: NUMBEROFVARIDXATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->numberOfVarIdxPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfVarIdx attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <varIdx> cannot be negative");
    osglData->numberOfVarIdxPresent = true;        
    osglData->numberOfVarIdx = $3;
};

osglBase64SizeATT: SIZEOFATT QUOTE INTEGER QUOTE
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    osglData->osglSize = $3;
};

osglIncrATT: INCRATT QUOTE INTEGER QUOTE 
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->osglIncrPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one incr attribute allowed");
    osglData->osglIncrPresent = true;
    osglData->osglIncr = $3;
};

osglMultATT: MULTATT QUOTE INTEGER QUOTE 
{
    if ( *$2 != *$4 ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    if (osglData->osglMultPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one mult attribute allowed");
    if ($3 <= 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "mult must be positive");
    osglData->osglMultPresent = true;
    osglData->osglMult = $3;
};

osglNameATT: NAMEATT ATTRIBUTETEXT QUOTE 
{ 
    if (osglData->namePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one name attribute");
    osglData->namePresent = true;   
    osglData->name = $2; 
    free($2);
};

osglTypeATT: TYPEATT ATTRIBUTETEXT QUOTE 
{ 
    if (osglData->typePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one type attribute");
    osglData->typePresent = true;
    osglData->type = $2; 
    free($2);
};

osglIdxATT: IDXATT QUOTE INTEGER QUOTE 
    { 
        if (osglData->idxPresent == true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one idx attribute");
        osglData->idxPresent = true;
        if ( *$2 != *$4 ) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
        osglData->idx = $3;
    };

osglShapeATT: SHAPEATT ATTRIBUTETEXT QUOTE 
{
    if (osglData->shapePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more than one shape attribute");
    osglData->shapePresent = true;   
    osglData->shape = (ENUM_NL_EXPR_SHAPE)returnNlExprShape($2);
    free($2);
};

osglRowMajorATT: rowMajorAttEmpty | rowMajorAttContent;

rowMajorAttEmpty: EMPTYROWMAJORATT
{
    if (osglData->rowMajorPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "rowMajor attribute encountered more than once");
    else
        osglData->rowMajor = true;
    osglData->rowMajorPresent = true;
};

rowMajorAttContent: ROWMAJORATT ATTRIBUTETEXT QUOTE 
{
    if (osglData->rowMajorPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "rowMajor attribute encountered more than once");
    else
    {
        if      (strcmp($2,"false") == 0) osglData->rowMajor = false;
        else if (strcmp($2,"true" ) == 0) osglData->rowMajor = true;
        else parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "rowMajor attribute must be \"true\" or \"false\"");
    }
    osglData->rowMajorPresent = true;
    free($2);
};

/* $Id$ */
/** @file OSParseosnl.y.syntax
 *
 * @author  Horand Gassmann, Jun Ma, Kipp Martin 
 *
 * \remarks
 * Copyright (C) 2005-2014, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 *
 * This file contains parser elements that are contained in the OSnL schema
 * and are shared between several of the main schemas, OSiL, OSoL and OSrL.
 *
 * The code is maintained in such a way that it can be inserted into any one
 * of these parsers by a makefile with minimal changes. 
 * The only change required is to change every occurrence of the placeholder
 * "targetObject" to the appropriate reference ("osinstance" for OSiL files, 
 * "osoption" for OSoL files and "osresult" for OSrL files). 
 * The makefile accomplishes this through maintaining each parser 
 * in several parts and to copy this include file between the OSxL syntax rules
 * and the postamble to make the final OSParseosxl.y file.
 * 
 */

/** ==========================================================================
 *           This portion parses nonlinear and matrix expressions
 *  ==========================================================================
 */

nonlinearExpressions:  
                | nonlinearExpressionsStart nlnumberatt nlnodes  NONLINEAREXPRESSIONSEND
    {  
        if (osnlData->tmpnlcount < osnlData->nlnodenumber)  
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "actual number of nl terms less than number attribute");   
    };

nonlinearExpressionsStart: NONLINEAREXPRESSIONSSTART
    {               
        osinstance->instanceData->nonlinearExpressions = new NonlinearExpressions();
        osnlData->tmpnlcount = 0;
    };

nlnumberatt: NUMBEROFNONLINEAREXPRESSIONS QUOTE INTEGER QUOTE GREATERTHAN 
    { 
        if ( *$2 != *$4 ) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
        if ($3 < 0) parserData->parser_errors += 
            addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, "number of expressions cannot be negative");
        osnlData->nlnodenumber = $3;
        osinstance->instanceData->nonlinearExpressions->numberOfNonlinearExpressions = $3;  
        if (osinstance->instanceData->nonlinearExpressions->numberOfNonlinearExpressions > 0 ) 
            osinstance->instanceData->nonlinearExpressions->nl = new Nl*[ $3 ];
        for (int i = 0; i < osinstance->instanceData->nonlinearExpressions->numberOfNonlinearExpressions; i++)
        {
            osinstance->instanceData->nonlinearExpressions->nl[i] = new Nl();
        }
    };

/**
 *  Note: In order to be semantically correct, the sequence of nlnodes must be structured
 *  such that the nodes can be partitioned into one or more expression trees. 
 *  The expression tree is eventually identified with its root node.
 */                  
nlnodes: 
        | nlnodes scalarExpressionTree;

scalarExpressionTree: nlstart nlAttributes GREATERTHAN nlnode NLEND
    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
        osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->m_treeRoot = 
            ((OSnLNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
        osnlData->tmpnlcount++;
    };

nlstart: NLSTART
    {
        if (osnlData->tmpnlcount >= osnlData->nlnodenumber) 
            parserData->parser_errors += 
                addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "actual number of nl terms greater than number attribute");
        osglData->idxPresent = false;
        osglData->shapePresent = false;   

        // clear the vectors of pointers
        osnlData->nlNodeVec.clear();
        osnlData->sumVec.clear();
        osnlData->allDiffVec.clear();
        osnlData->maxVec.clear();
        osnlData->minVec.clear();
        osnlData->productVec.clear();
        osnlData->matrixSumVec.clear();
        osnlData->matrixProductVec.clear();
    };

nlAttributes: nlAttributeList
{
    if (osglData->idxPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "mandatory attribute idx is missing");    
};


nlAttributeList: | nlAttributeList nlAttribute;

nlAttribute: 
      osglIdxATT 
    { 
        osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->idx = osglData->idx;
        osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree
            = new ScalarExpressionTree();
    }
    | osglShapeATT
    {
        osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->shape = osglData->shape;
    };

nlnode: number
      | variable 
      | times 
      | plus 
      | sum 
      | minus 
      | negate
      | divide 
      | power 
      | product
      | ln 
      | sqrt 
      | square
      | sin
      | cos
      | exp
      | if
      | abs
      | erf
      | max
      | min
      | E
      | PI
      | allDiff 

      | matrixDeterminant
      | matrixTrace
      | matrixToScalar
;

/** The first two nodes are terminal nodes; they have no descendants */
E: ESTART {    osnlData->nlNodePoint = new OSnLNodeE();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);} eend;
    
eend: ENDOFELEMENT
            | GREATERTHAN EEND;
            
PI: PISTART {    osnlData->nlNodePoint = new OSnLNodePI();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);} piend;
    
piend: ENDOFELEMENT
            | GREATERTHAN PIEND;

   
/** These nodes have a fixed number of descendants (which get allocated automatically in the constructor) */
times: TIMESSTART {
    osnlData->nlNodePoint = new OSnLNodeTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
} nlnode nlnode TIMESEND;

plus: PLUSSTART {
    osnlData->nlNodePoint = new OSnLNodePlus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
} nlnode nlnode PLUSEND;

minus: MINUSSTART {
    osnlData->nlNodePoint = new OSnLNodeMinus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
} nlnode nlnode MINUSEND;

negate: NEGATESTART {
    osnlData->nlNodePoint = new OSnLNodeNegate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
} nlnode  NEGATEEND;

divide: DIVIDESTART { 
    osnlData->nlNodePoint = new OSnLNodeDivide();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
} nlnode nlnode DIVIDEEND;

power: POWERSTART {
    osnlData->nlNodePoint = new OSnLNodePower();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
} nlnode nlnode POWEREND;

ln: LNSTART {
    osnlData->nlNodePoint = new OSnLNodeLn();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
} nlnode LNEND;

sqrt: SQRTSTART {
    osnlData->nlNodePoint = new OSnLNodeSqrt();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
} nlnode SQRTEND;

square: SQUARESTART {
    osnlData->nlNodePoint = new OSnLNodeSquare();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
} nlnode SQUAREEND;

cos: COSSTART {
    osnlData->nlNodePoint = new OSnLNodeCos();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
} nlnode COSEND;

sin: SINSTART {
    osnlData->nlNodePoint = new OSnLNodeSin();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
} nlnode SINEND;

exp: EXPSTART {
    osnlData->nlNodePoint = new OSnLNodeExp();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
} nlnode EXPEND;

abs: ABSSTART {
    osnlData->nlNodePoint = new OSnLNodeAbs();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
} nlnode ABSEND {
osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
};

erf: ERFSTART {
    osnlData->nlNodePoint = new OSnLNodeErf();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
} nlnode ERFEND {
};

if: IFSTART {
    osnlData->nlNodePoint = new OSnLNodeIf();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
} nlnode nlnode nlnode IFEND {
osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
};


/** some more scalar-valued nodes that involve matrix children */
matrixDeterminant: MATRIXDETERMINANTSTART {
    osnlData->nlNodePoint = new OSnLNodeMatrixDeterminant();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
} OSnLMNode MATRIXDETERMINANTEND;

matrixTrace: MATRIXTRACESTART {
    osnlData->nlNodePoint = new OSnLNodeMatrixTrace();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
} OSnLMNode MATRIXTRACEEND;

matrixToScalar: MATRIXTOSCALARSTART {
    osnlData->nlNodePoint = new OSnLNodeMatrixToScalar();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
} OSnLMNode MATRIXTOSCALAREND;


/** These next two nodes have attributes
 *  In addition <variable> has an optional OSnLNode descendant 
 *  (for variable index expressions) --- not implemented yet.
 */
number: NUMBERSTART {
    osnlData->nlNodeNumberPoint = new OSnLNodeNumber();
    osnlData->nlNodeVec.push_back( osnlData->nlNodeNumberPoint);
} anotherNumberATT  numberend {osnlData->numbervalueattON = false; osnlData->numbertypeattON = false; osnlData->numberidattON = false;};

numberend: ENDOFELEMENT
         | GREATERTHAN NUMBEREND;

anotherNumberATT:
         | anotherNumberATT numberATT;
            
numberATT: numbertypeATT
         | numbervalueATT
         | numberidATT            
            ;
            
numbertypeATT: TYPEATT ATTRIBUTETEXT 
{
    if (osnlData->numbertypeattON) parserData->parser_errors += 
        addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too many number type attributes"); 
    osnlData->numbertypeattON = true;
    osnlData->nlNodeNumberPoint->type = $2;
    free($2);
} QUOTE;

numberidATT:   IDATT   ATTRIBUTETEXT 
{
    if (osnlData->numberidattON) parserData->parser_errors += 
        addErrorMsg( NULL, osoption, parserData, osglData, osnlData,"too many number id attributes"); 
    osnlData->numberidattON = true;
    osnlData->nlNodeNumberPoint->id = $2;
    free($2);
} QUOTE;

numbervalueATT: VALUEATT QUOTE aNumber QUOTE 
{
    if (osnlData->numbervalueattON) parserData->parser_errors += 
        addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too many number value attributes"); 
    osnlData->numbervalueattON = true;
    osnlData->nlNodeNumberPoint->value = parserData->tempVal;
};


variable: VARIABLESTART 
{
    osnlData->nlNodeVariablePoint = new OSnLNodeVariable();
    osnlData->nlNodeVec.push_back( osnlData->nlNodeVariablePoint);
} anotherVariableATT  variableend {osnlData->variablecoefattON = false; osnlData->variableidxattON = false;} ;
              
variableend: 
      ENDOFELEMENT
    | GREATERTHAN VARIABLEEND
    | GREATERTHAN nlnode 
        {
            osnlData->nlNodeVariablePoint->inumberOfChildren = 1;
            osnlData->nlNodeVariablePoint->m_mChildren = new OSnLNode*[ 1];
        }    
        VARIABLEEND;
            
anotherVariableATT:
            | anotherVariableATT variableATT;
            
variableATT: 
      variablecoefATT  
        {
            if (osnlData->variablecoefattON) parserData->parser_errors += 
                addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too many variable coef attributes"); 
            osnlData->variablecoefattON = true; 
        }
    | variableidxATT
        {
            if (osnlData->variableidxattON) parserData->parser_errors += 
                addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too many variable idx attributes"); 
            osnlData->variableidxattON = true; 
        }
;
            
variablecoefATT: COEFATT  QUOTE aNumber QUOTE 
{ 
    if ( *$2 != *$4 ) parserData->parser_errors += 
        addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlNodeVariablePoint->coef = parserData->tempVal;
};
                
variableidxATT: IDXATT QUOTE  INTEGER QUOTE 
{ 
    if ( *$2 != *$4 ) parserData->parser_errors += 
        addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlNodeVariablePoint->idx = $3;
    if ( $3 >= osinstance->instanceData->variables->numberOfVariables)
         parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "variable index exceeds number of variables");
}; 


/** 
 *  These nodes have a variable number of descendants that cannot be allocated beforehand.
 *  Some dirty trickery is involved in accomplishing everything.
 *  First, when such a node is encountered, it is pushed onto two vectors simultaneously:
 *  the vector of all nl nodes and a vector of special nodes (to cater for the possibility
 *  that there might be nested sums, etc.). Both vectors point to the same memory location,
 *  which can be manipulated through whichever vector is more convenient. This is used in
 *  SUMEND below to allocate the right number of descendants (once this is known) and in
 *  nlnode below it to increment the number of descendants.
 */
sum: SUMSTART {
    osnlData->nlNodePoint = new OSnLNodeSum();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->sumVec.push_back( osnlData->nlNodePoint);
}
anothersumnlnode SUMEND {
    ((OSnLNode*)osnlData->sumVec.back())->m_mChildren 
        = new OSnLNode*[ ((OSnLNode*)osnlData->sumVec.back())->inumberOfChildren];
    osnlData->sumVec.pop_back();
};

anothersumnlnode: | anothersumnlnode nlnode { ((OSnLNode*)osnlData->sumVec.back())->inumberOfChildren++; };
            

allDiff: ALLDIFFSTART {    
    osnlData->nlNodePoint = new OSnLNodeAllDiff ();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->allDiffVec.push_back( osnlData->nlNodePoint);
}
anotherallDiffnlnode ALLDIFFEND {
    ((OSnLNode*)osnlData->allDiffVec.back())->m_mChildren 
        = new OSnLNode*[ ((OSnLNode*)osnlData->allDiffVec.back())->inumberOfChildren];
    osnlData->allDiffVec.pop_back();
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
};

anotherallDiffnlnode: 
            | anotherallDiffnlnode nlnode { ((OSnLNode*)osnlData->allDiffVec.back())->inumberOfChildren++; };
            
            
max: MAXSTART {
    osnlData->nlNodePoint = new OSnLNodeMax();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->maxVec.push_back( osnlData->nlNodePoint);
}
anothermaxnlnode MAXEND {
    osnlData->maxVec.back()->m_mChildren = new OSnLNode*[ osnlData->maxVec.back()->inumberOfChildren];
    osnlData->maxVec.pop_back();
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
};

anothermaxnlnode: 
            | anothermaxnlnode nlnode { osnlData->maxVec.back()->inumberOfChildren++; };


min: MINSTART {
    osnlData->nlNodePoint = new OSnLNodeMin();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->minVec.push_back( osnlData->nlNodePoint);
}
anotherminnlnode MINEND {
    osnlData->minVec.back()->m_mChildren = new OSnLNode*[ osnlData->minVec.back()->inumberOfChildren];
    osnlData->minVec.pop_back();
    osinstance->instanceData->nonlinearExpressions->nl[ osnlData->tmpnlcount]->osExpressionTree->bADMustReTape = true;
};

anotherminnlnode: 
            | anotherminnlnode nlnode { osnlData->minVec.back()->inumberOfChildren++; };

            
product: PRODUCTSTART {
    osnlData->nlNodePoint = new OSnLNodeProduct();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->productVec.push_back( osnlData->nlNodePoint);
}
anotherproductnlnode PRODUCTEND {
    osnlData->productVec.back()->m_mChildren = new OSnLNode*[ osnlData->productVec.back()->inumberOfChildren];
    osnlData->productVec.pop_back();
};

anotherproductnlnode: 
            | anotherproductnlnode nlnode { osnlData->productVec.back()->inumberOfChildren++; };



/** OSnLMNodes are parsed in essentially the same way as OSnLNodes */

OSnLMNode: matrixReference
         | matrixDiagonal
         | matrixDotTimes
         | matrixInverse
         | matrixLowerTriangle
         | matrixUpperTriangle
         | matrixMerge
         | matrixMinus
         | matrixNegate
         | matrixPlus
         | matrixTimes
         | matrixProduct
         | matrixScalarTimes
         | matrixSubMatrixAt
         | matrixTranspose
         | identityMatrix
;

matrixReference: matrixReferenceStart matrixIdxATT matrixreferenceend 
{
    osnlData->matrixidxattON = false;
};

matrixReferenceStart: MATRIXREFERENCESTART
{
    osnlData->nlMNodeMatrixRef = new OSnLMNodeMatrixReference();
    osnlData->nlNodeVec.push_back(osnlData->nlMNodeMatrixRef);
};

              
matrixreferenceend: ENDOFELEMENT
           | GREATERTHAN MATRIXREFERENCEEND;
                           
matrixIdxATT: IDXATT QUOTE INTEGER QUOTE 
{
    if ( *$2 != *$4 )
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "start and end quotes are not the same");
    osnlData->nlMNodeMatrixRef->idx = $3;
}; 


matrixDiagonal: matrixDiagonalStart matrixDiagonalContent;

matrixDiagonalStart: MATRIXDIAGONALSTART 
{
    osnlData->nlNodePoint = new OSnLMNodeMatrixDiagonal();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
};

matrixDiagonalContent: OSnLMNode MATRIXDIAGONALEND;

matrixDotTimes: matrixDotTimesStart matrixDotTimesContent;

matrixDotTimesStart: MATRIXDOTTIMESSTART 
{
    osnlData->nlNodePoint = new OSnLMNodeMatrixDotTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
};

matrixDotTimesContent: OSnLMNode OSnLMNode MATRIXDOTTIMESEND;

identityMatrix: identityMatrixStart identityMatrixContent;

identityMatrixStart: IDENTITYMATRIXSTART 
{
    osnlData->nlNodePoint = new OSnLMNodeIdentityMatrix();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
};

identityMatrixContent: nlnode IDENTITYMATRIXEND;

matrixInverse: matrixInverseStart matrixInverseContent;

matrixInverseStart: MATRIXINVERSESTART 
{
    osnlData->nlNodePoint = new OSnLMNodeMatrixInverse();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
};

matrixInverseContent: OSnLMNode MATRIXINVERSEEND;

matrixLowerTriangle: matrixLowerTriangleStart matrixLowerTriangleAttribute GREATERTHAN matrixLowerTriangleContent;

matrixLowerTriangleStart: MATRIXLOWERTRIANGLESTART 
{
    osnlData->nlNodePoint = new OSnLMNodeMatrixLowerTriangle();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
};

matrixLowerTriangleAttribute: | includeDiagonalATT
{
    ((OSnLMNodeMatrixLowerTriangle*)osnlData->nlNodeVec.back())->includeDiagonal = osnlData->includeDiagonalAttribute;
};

matrixLowerTriangleContent: OSnLMNode MATRIXLOWERTRIANGLEEND;

matrixUpperTriangle: matrixUpperTriangleStart matrixUpperTriangleAttribute GREATERTHAN matrixUpperTriangleContent;

matrixUpperTriangleStart: MATRIXUPPERTRIANGLESTART 
{
    osnlData->nlNodePoint = new OSnLMNodeMatrixUpperTriangle();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
};

matrixUpperTriangleAttribute: | includeDiagonalATT
{
    ((OSnLMNodeMatrixUpperTriangle*)osnlData->nlNodeVec.back())->includeDiagonal = osnlData->includeDiagonalAttribute;
};

matrixUpperTriangleContent: OSnLMNode MATRIXUPPERTRIANGLEEND;

includeDiagonalATT: INCLUDEDIAGONALATT ATTRIBUTETEXT QUOTE 
{
    if      (strcmp($2,"false") == 0) osnlData->includeDiagonalAttribute = false;
    else if (strcmp($2,"true" ) == 0) osnlData->includeDiagonalAttribute = true;
    else parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "osnlData->includeDiagonal attribute must be \"true\" or \"false\"");
    free($2);
};


matrixMerge: matrixMergeStart matrixMergeEnd;

matrixMergeStart: MATRIXMERGESTART 
{
     parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "matrix merge not yet implemented");
};

matrixMergeEnd: ENDOFELEMENT | GREATERTHAN MATRIXMERGEEND;

matrixMinus: matrixMinusStart matrixMinusContent;

matrixMinusStart: MATRIXMINUSSTART 
{
    osnlData->nlNodePoint = new OSnLMNodeMatrixMinus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
};

matrixMinusContent: OSnLMNode OSnLMNode MATRIXMINUSEND;


matrixNegate: matrixNegateStart matrixNegateContent;

matrixNegateStart: MATRIXNEGATESTART 
{
    osnlData->nlNodePoint = new OSnLMNodeMatrixNegate();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
};

matrixNegateContent: OSnLMNode MATRIXNEGATEEND;


matrixPlus: matrixPlusStart matrixPlusContent;

matrixPlusStart: MATRIXPLUSSTART 
{
    osnlData->nlNodePoint = new OSnLMNodeMatrixPlus();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
};

matrixPlusContent: OSnLMNode OSnLMNode MATRIXPLUSEND;


matrixTimes: matrixTimesStart matrixTimesContent;

matrixTimesStart: MATRIXTIMESSTART 
{
    osnlData->nlNodePoint = new OSnLMNodeMatrixTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
};

matrixTimesContent: OSnLMNode OSnLMNode MATRIXTIMESEND;

            
matrixProduct: MATRIXPRODUCTSTART 
{
    osnlData->nlNodePoint = new OSnLMNodeMatrixProduct();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
    osnlData->matrixProductVec.push_back( osnlData->nlNodePoint);
}
anothermatrixproductnode MATRIXPRODUCTEND 
{
    osnlData->matrixProductVec.back()->m_mMatrixChildren = new OSnLMNode*[ osnlData->matrixProductVec.back()->inumberOfMatrixChildren];
    osnlData->matrixProductVec.pop_back();
};

anothermatrixproductnode: | anothermatrixproductnode OSnLMNode 
{ 
    osnlData->matrixProductVec.back()->inumberOfMatrixChildren++; 
};



matrixScalarTimes: matrixScalarTimesStart matrixScalarTimesContent;

matrixScalarTimesStart: MATRIXSCALARTIMESSTART 
{
    osnlData->nlNodePoint = new OSnLMNodeMatrixScalarTimes();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
};

matrixScalarTimesContent: nlnode OSnLMNode MATRIXSCALARTIMESEND;

matrixSubMatrixAt: matrixSubMatrixAtStart matrixSubMatrixAtContent;

matrixSubMatrixAtStart: MATRIXSUBMATRIXATSTART 
{
    osnlData->nlNodePoint = new OSnLMNodeMatrixSubmatrixAt();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
};

matrixSubMatrixAtContent: nlnode nlnode nlnode nlnode OSnLMNode MATRIXSUBMATRIXATEND;


matrixTranspose: matrixTransposeStart matrixTransposeContent;

matrixTransposeStart: MATRIXTRANSPOSESTART 
{
    osnlData->nlNodePoint = new OSnLMNodeMatrixTranspose();
    osnlData->nlNodeVec.push_back( osnlData->nlNodePoint);
};

matrixTransposeContent: OSnLMNode MATRIXTRANSPOSEEND;



/**
 *  Here we have the parser for the <matrixExpressions> <expr> element,
 *  which is essentially the same as a nonlinear expression, except that
 *  the root node returns a matrix. We reuse as much of the code and
 *  data structures as possible. 
 */
matrixExpressions: | matrixExpressionsStart matrixExpressionsAtt matrixExpressionsContent
    {  
        if (osnlData->tmpnlcount < osnlData->nlnodenumber)  
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "actual number of matrix expressions less than number attribute");   
    };

matrixExpressionsStart: MATRIXEXPRESSIONSSTART
    {               
        osinstance->instanceData->matrixProgramming->matrixExpressions = new MatrixExpressions();
        osnlData->tmpnlcount = 0;
    };

matrixExpressionsAtt: numberOfExprATT;

numberOfExprATT: NUMBEROFEXPR QUOTE INTEGER QUOTE 
    {
        if (*$2 != *$4) 
            parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, 
                        "mismatched quotes");
        if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osinstance, parserData, osglData, osnlData, 
                        "number of expressions cannot be negative");
        osnlData->nlnodenumber = $3;
        osinstance->instanceData->matrixProgramming->matrixExpressions->numberOfExpr = $3;  
        if (osinstance->instanceData->matrixProgramming->matrixExpressions->numberOfExpr > 0 ) 
            osinstance->instanceData->matrixProgramming->matrixExpressions->expr = new MatrixExpression*[ $3 ];
        for (int i = 0; i < osinstance->instanceData->matrixProgramming->matrixExpressions->numberOfExpr; i++)
            osinstance->instanceData->matrixProgramming->matrixExpressions->expr[i] = new MatrixExpression();
}; 

matrixExpressionsContent: matrixExpressionsEmpty | matrixExpressionsLaden;

matrixExpressionsEmpty: ENDOFELEMENT;

matrixExpressionsLaden: GREATERTHAN matrixExprList MATRIXEXPRESSIONSEND;

matrixExprList: | matrixExprList matrixExpr;

matrixExpr: matrixExprStart matrixExprAttributes GREATERTHAN OSnLMNode EXPREND
    {
    // IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
        osinstance->instanceData->matrixProgramming->matrixExpressions->expr[ osnlData->tmpnlcount]->matrixExpressionTree->m_treeRoot = 
            ((OSnLMNode*)osnlData->nlNodeVec[ 0])->createExpressionTreeFromPrefix( osnlData->nlNodeVec);
        osnlData->tmpnlcount++;
    };

matrixExprStart: EXPRSTART
    {
        if (osnlData->tmpnlcount >= osnlData->nlnodenumber) 
            parserData->parser_errors += 
                addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "actual number of matrix expressions greater than number attribute");
        osglData->idxPresent = false;
        osglData->shapePresent = false;   

        // clear the vectors of pointers
        osnlData->nlNodeVec.clear();
        osnlData->sumVec.clear();
        osnlData->allDiffVec.clear();
        osnlData->maxVec.clear();
        osnlData->minVec.clear();
        osnlData->productVec.clear();
        osnlData->matrixSumVec.clear();
        osnlData->matrixProductVec.clear();
    };

matrixExprAttributes: matrixExprAttributeList
{
    if (osglData->idxPresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "mandatory attribute idx is missing");    
};

matrixExprAttributeList: | matrixExprAttributeList exprAttribute;

exprAttribute: 
      osglIdxATT 
    { 
        osinstance->instanceData->matrixProgramming->matrixExpressions->expr[ osnlData->tmpnlcount]->idx = osglData->idx;
        osinstance->instanceData->matrixProgramming->matrixExpressions->expr[ osnlData->tmpnlcount]->matrixExpressionTree
            = new MatrixExpressionTree();
    }
    | osglShapeATT
    {
        osinstance->instanceData->matrixProgramming->matrixExpressions->expr[ osnlData->tmpnlcount]->shape = osglData->shape;
    };


/* $Id$ */
/** @file OSParseosol.y.3
 *
 * @author  Horand Gassmann, Jun Ma, Kipp Martin 
 *
 * \remarks
 * Copyright (C) 2005-2014, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 * In order to allow easier maintenance of the parsers, 
 * the files OSParseosol.y and OSParseosrl.y are stored in several pieces
 * that are combined in the makefile.
 * This is the last part of the file OSParseosol.y containing the postamble.
 * It is appended as the last file.
 */

%%

#if 0
void addErrorMsg(YYLTYPE* mytype, OSOption *osoption, OSoLParserData* parserData, OSgLParserData* osglData, const char* errormsg )
{
    osol_empty_vectors( parserData);
    osgl_empty_vectors( osglData);
    std::ostringstream outStr;
    std::string error = errormsg;
    error = "OSoL input is either not valid or well formed: "  + error;
    outStr << error << std::endl;
    outStr << "Error occurred when reading: " << osolget_text ( scanner ) << std::endl; 
    outStr << "See line number: " << osolget_lineno( scanner) << std::endl; 
    error = outStr.str();

} //end addErrorMsg
#endif

std::string addErrorMsg(YYLTYPE* mytype, OSOption *osoption, OSoLParserData* parserData, OSgLParserData* osglData, OSnLParserData *osnlData, std::string errormsg )
{
    std::ostringstream outStr;
    outStr << "At line number " << osolget_lineno( scanner) << ": "; 
    outStr << osolget_text ( scanner ) << std::endl; 
    outStr << errormsg << std::endl;

    return outStr.str();
} //end addErrorMsg

void osolerror(YYLTYPE* mytype, OSOption *osoption, OSoLParserData* parserData, OSgLParserData* osglData, OSnLParserData *osnlData, std::string errormsg )
{
    osol_empty_vectors( parserData);
    osgl_empty_vectors( osglData);
    osnl_empty_vectors( osnlData);
    throw ErrorClass( errormsg);
} //end osolerror

void  yygetOSOption(const char *parsestring, OSOption *osoption, 
      OSoLParserData *parserData, OSgLParserData *osglData, OSnLParserData *osnlData) throw(ErrorClass)
{
    try{
        osol_scan_string( parsestring, scanner);
        osolset_lineno (1 , scanner );
        //
        // call the Bison parser
        //
        if(  osolparse( osoption,  parserData, osglData, osnlData) != 0) {
            //osollex_destroy(scanner);
              throw ErrorClass(  "Error parsing the OSoL file");
         }
    }
    catch(const ErrorClass& eclass){
        throw ErrorClass(  eclass.errormsg); 
    }
} //end yygetOSOption


void osol_empty_vectors( OSoLParserData* parserData){
/*
    int k;
    int numOtherVarVec = parserData->otherVarVec.size();
   
    for( k = 0; k < numOtherVarVec; k++){
        if( (parserData->otherVarVec[ k]  != NULL) && (parserData->otherVarVec[ k]->otherVarText != NULL) ) 
            delete[] parserData->otherVarVec[ k]->otherVarText;
        if( (parserData->otherVarVec[ k]  != NULL) && (parserData->otherVarVec[ k]->otherVarIndex != NULL) ) 
            delete[] parserData->otherVarVec[ k]->otherVarIndex;
            
        if( parserData->otherVarVec[ k]  != NULL) delete parserData->otherVarVec[ k];
    }

      parserData->otherVarVec.clear(); 
      
      int numDualVals =  parserData->dualVals.size();
      for(k = 0; k < numDualVals; k++){
          if( parserData->dualVals[ k]  != NULL  ) 
            delete parserData->dualVals[ k];
      }
      parserData->dualVals.clear();
      
      
       int numObjVals =  parserData->objVals.size();
      for(k = 0; k < numObjVals; k++){
          if( parserData->objVals[ k]  != NULL  ) 
            delete parserData->objVals[ k];
      }
      parserData->objVals.clear();
      
      
       int numPrimalVals =  parserData->primalVals.size();
      for(k = 0; k < numPrimalVals; k++){    
          if( parserData->primalVals[ k]  != NULL  ) 
            delete parserData->primalVals[ k];
      }
      parserData->primalVals.clear();
*/      
}//end osol_empty_vectors

