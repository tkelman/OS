/** @file OSrLParserData.h
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
 */
#ifndef OSRLPARSERDATA_H
#define OSRLPARSERDATA_H

#include "OSnLNode.h"
#include <vector> 
#include <sstream>



/*! \struct OtherVariableResultStruct
 * \brief A structure to information about an OtherVariableResult 
 * element
 */
struct OtherVariableResultStruct{
	/** name holds the text of the name attribute of the 
	 * OtherVariableResult element 
	 */
	std::string name;

	/** description holds the text of the description attribute 
	 * of the OtherVariableResult element
	 */ 
	std::string description;
	
	/** value holds the text of the value attribute 
	 * of the OtherVariableResult element
	 */ 
	std::string value;
	
	/** numberOfVar holds the number of variables in the <var> array
	 * of the OtherVariableResult element
	 */ 
	int numberOfVar;

	/** otherVarText is a pointer to an array with number of 
	 * elements equal to the number of variables. Each element of the
	 * array is the value of the variable corresponding to the
	 * OtherVariableResult, e.g. a variable name or variable
	 * reduced cost, etc.
	 */
	std::string *otherVarText;
	

	/** otherVarIndex is a pointer to an array with number of 
	 * elements equal to the number of variables. Each element of the
	 * array is the index of the variable corresponding to the
	 * OtherVariableResult, e.g. a variable name or variable
	 * reduced cost, etc.
	 */
	int *otherVarIndex;
		
};


/*! \class OSrLParserData
 *  \brief The OSrLParserData  Class.
 * 
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 * 
 * \remarks
 * the OSrLParserData class is used to temporarily 
 * hold data found in parsing the OSrL instance
 * we do this so we can have a reentrant parser.
 */
class OSrLParserData{
public:
	
	/** the OSrLParserData class constructor */
	OSrLParserData( );
	
	//** the OSrLParserData class destructor */
	~OSrLParserData() ;
	
	
	/**  the status type of the result */ 
	std::string statusType;
	
	/** the status Description of the solution */
	std::string statusDescription;

	/** the next few variables store a time measurement and associated 
	    attribute values */
	double timeValue;
	std::string timeType;
	std::string timeCategory;
	std::string timeUnit;
	std::string timeDescription;

	/** There could be more than one time measurement;
	 *  numberOfTimes stores the number of them */
	int numberOfTimes;

	/** Provide temporary storage for attribute values associated with an OtherVarResult */
	std::string tmpOtherValue;
	std::string tmpOtherName;
	std::string tmpOtherDescription;

	/** scanner is used to store data in a reentrant lexer 
	 *  we use this to pass an OSrLParserData object to the parser*/
	void* scanner;
	
	/** number of result solutions */
	int numberOfSolutions;
	
	/** number of variables in the solution instance */
	int numberOfVariables;
	
	/** number of constraints in the solution instance */
	int numberOfConstraints;
	
	/** number of Objectives in the solution instance */
	int numberOfObjectives;
	
	/** a temporary counter to count variables, number of attributes, etc. */
	int kounter;

	/** a temporary counter to count other variable, objective and constraint results */
	int iOther;

	/** a temporary variable to hold an integer index value */
	int ivar;

	/** a temporary variable to hold an integer or double value */
	double tempVal;
	
	/** a temporary variable to hold an output stream value */
	std::ostringstream outStr;
	
	/** the number of types of variable results other
	 * than the value of the variable
	 */	
	int numberOfOtherVariableResults;
	
	/** and index on which solution we have found */
	int solutionIdx;

	/** set statusTypePresent to true if there is
	 * a status attribute parsed
	 */
	bool statusTypePresent;
	
	/** set generalStatusTypePresent to true if there is
	 * a general status attribute parsed
	 */	
	bool generalStatusTypePresent;
	
	/** set otherNamePresent to true if there is
	 * a name attribute in anotherVarResult
	 */	
	bool otherNamePresent;
	
	/** pointer to the array of objective function indexes
	 * in each solution
	 */
	int *objectiveIdx;
	
	/**  for each solution we have a pointer to the value of
	 * each objective function
	 */
	double **objectiveValues;
	
	/**  for each solution we have a pointer to each primal solution */
	double **primalSolution;
	
	/**  for each solution we have a pointer to each dual solution */
	double **dualSolution;
	
	


	/** a pointer to an OtherVariableResultStruct structure  */
	struct OtherVariableResultStruct *otherVarStruct;
	
	/** store a vector of pointers to otherVarVec structures */
	std::vector<OtherVariableResultStruct*> otherVarVec;
	
	/**  if the parser finds invalid text it is held here and we delete
	 *   if the file was not valid
	 */
	char *errorText;
};

#endif /*OSRLPARSERDATA_H_*/
