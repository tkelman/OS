/* $Id: OSGeneral.h 3172 2010-02-05 04:59:24Z Gassmann $ */
/** @file OSGeneral.h
 * 
 *
 * @author  Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin, 
 * @version 1.0, 19/07/2010
 * @since   OS2.2
 *
 * \remarks
 * Copyright (C) 2005-2010, Robert Fourer, Jun Ma, Horand Gassmann, Kipp Martin,
 * Northwestern University, Dalhousie University and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */

#ifndef OSGENERAL_H
#define OSGENERAL_H


#ifdef HAVE_CSTDLIB
# include <cstdlib>
#else
# ifdef HAVE_STDLIB_H
#  include <stdlib.h>
# endif
#endif

#include "OSConfig.h"

#include <string>
#include <vector>


/*! \class SparseMatrix
 * \brief a sparse matrix data structure
 */
class SparseMatrix {
	public:
	
	/**
	 * bDeleteArrays is true if we delete the arrays in garbage collection
	 * set to true by default
	 */
	bool bDeleteArrays;
	
	/**
	 * isColumnMajor holds whether the coefMatrix (AMatrix) holding linear program
	 * data is stored by column. If false, the matrix is stored by row.
	 */
	bool isColumnMajor;
	
	/**
	 * startSize is the dimension of the starts array
	 */
	int startSize;
	
	/**
	 * valueSize is the dimension of the starts array
	 */
	int valueSize;
	
	/**
	 * starts holds an integer array of start elements in coefMatrix (AMatrix),
	 * which points to the start of a column (row) of nonzero elements in coefMatrix (AMatrix).
	 */
	int* starts; 
	
	/**
	 * indexes holds an integer array of rowIdx (or colIdx) elements in coefMatrix (AMatrix).
	 * If the matrix is stored by column (row), rowIdx (colIdx) is the array of row (column) indices.
	 */
	int* indexes;

	/**
	 * values holds a double array of value elements in coefMatrix (AMatrix),
	 * which contains nonzero elements.
	 */
	double* values;
	
	/**
	 *
	 * Default constructor. 
	 */
	SparseMatrix();
	
	/**
	 * Constructor.
	 * 
	 * @param isColumnMajor holds whether the coefMatrix (AMatrix) holding linear program
	 * data is stored by column. If false, the matrix is stored by row.
	 * @param startSize holds the size of the start array.
	 * @param valueSize holds the size of the value and index arrays.
	 */
	SparseMatrix(bool isColumnMajor_, int startSize, int valueSize);
	/**
	 *
	 * Default destructor. 
	 */	
	~SparseMatrix();
	
	/**
	 * This method displays data structure in the matrix format.
	 * </p>
	 * @return
	 */
	bool display(int secondaryDim);

}; //SparseMatrix


/*! \class SparseVector
 * \brief a sparse vector data structure
 */
class SparseVector{
	public:
	
	/**
	 * Constructor.
	 * 
	 * @param number holds the size of the vector.
	 */
	SparseVector(int number);
	
	/**
	 *
	 * Default Constructor. 
	 */	
	SparseVector();
	
	/**
	 *
	 * Default destructor. 
	 */	
	~SparseVector();

	/**
	 * bDeleteArrays is true if we delete the arrays in garbage collection
	 * set to true by default
	 */
	bool bDeleteArrays;
	
	/**
	 * number is the number of elements in the indexes and values arrays.
	 */
	int number;
	
	/**
	 * indexes holds an integer array of indexes, which corresponding values are nonzero.
	 */
	int* indexes;

	/**
	 * values holds a double array of nonzero values.
	 */
	double* values;

}; //SparseVector


/*! \class SparseJacobianMatrix
 * \brief a sparse Jacobian matrix data structure
 */
class SparseJacobianMatrix {
	public:
	
	/**
	 * bDeleteArrays is true if we delete the arrays in garbage collection
	 * set to true by default
	 */
	bool bDeleteArrays;
	
	/**
	 * startSize is the dimension of the starts array -- should equal number of rows + 1
	 */
	int startSize;
	
	/**
	 * valueSize is the dimension of the values array
	 */
	int valueSize;
	
	/**
	 * starts holds an integer array of start elements, each start element
	 * pints to the start of partials for that row
	 */
	int* starts; 
	
	/**
	 * conVals holds an integer array of integers, conVals[i] is the number of constant terms
	 * in the gradient for row i.
	 */
	int* conVals; 
	
	/**
	 * indexes holds an integer array of variable indicies.
	 */
	int* indexes;

	/**
	 * values holds a double array of nonzero partial derivatives
	 */
	double* values;
	
	/**
	 *
	 * Default constructor. 
	 */
	SparseJacobianMatrix();
	
	/**
	 * Constructor.
	 * 
	 * @param startSize holds the size of the start array.
	 * @param valueSize holds the size of the value and index arrays.
	 */
	SparseJacobianMatrix(int startSize, int valueSize);

	/**
	 *
	 * Default destructor. 
	 */	
	~SparseJacobianMatrix();

}; //SparseJacobianMatrix





/*! \class SparseHessianMatrix SparseHessianMatrix.h "SparseHessianMatrix.h"
 *  \brief The in-memory representation of a SparseHessianMatrix..
 *
 * \remarks 
<p>  Store and uppertriangular Hessian Matrix in sparse format </p>
<p>  Assume there are n variables in what follows </p>

 *
 * 
 */
class SparseHessianMatrix {
	public:
	
	/**
	 * bDeleteArrays is true if we delete the arrays in garbage collection
	 * set to true by default
	 */
	bool bDeleteArrays;

	/**
	 * hessDimension is the number of nonzeros in each array.
	 */
	int hessDimension;
	
	/**
	 * hessRowIdx is an integer array of row indicies in the range 0, ..., n - 1.
	 */
	int* hessRowIdx; 
	
	/**
	 * hessColIdx is an integer array of column indicies in the range 0, ..., n - 1.
	 */
	int* hessColIdx; 
	
	/**
	 * hessValues is a double array of the Hessian values.
	 */
	double* hessValues;

	/**
	 *
	 * Default constructor. 
	 */
	SparseHessianMatrix();
	
	/**
	 * An Alternative Constructor.
	 * 
	 * @param startSize holds the size of the arrays.
	 * @param valueSize holds the size of the value and index arrays.
	 */
	SparseHessianMatrix(int startSize, int valueSize);

	/**
	 *
	 * Default destructor. 
	 */	
	~SparseHessianMatrix();

}; //SparseHessianMatrix

/*! \class QuadraticTerms
 * \brief a data structure for holding quadratic terms
 */
class QuadraticTerms {

	public:
	
	/**
	 * rowIndexes holds an integer array of row indexes of all the quadratic terms. 
	 * A negative integer corresponds to an objective row, e.g. -1 for 1st objective and -2 for 2nd.
	 */
	int* rowIndexes; 

	/**
	 * varOneIndexes holds an integer array of the first varialbe indexes of all the quadratic terms. 
	 */
	int* varOneIndexes; 

	/**
	 * varTwoIndexes holds an integer array of the second varialbe indexes of all the quadratic terms. 
	 */
	int* varTwoIndexes; 

	/**
	 * coefficients holds a double array all the quadratic term coefficients. 
	 */
	double* coefficients; 

	/**
	 *
	 * Default constructor. 
	 */
	QuadraticTerms();
	~QuadraticTerms();
}; //QuadraticTerms


/*! \class IntVector
 * \brief an integer Vector data structure
 */	
class IntVector{
public:
	IntVector();
	~IntVector();
	/**
	 * bDeleteArrays is true if we delete the arrays in garbage collection
	 * set to true by default
	 */
	bool bDeleteArrays;
	int *el;
};//class IntVector

/*! \class DoubleVector
 * \brief a double vector data structure
 */
class DoubleVector{
public:
	DoubleVector();
	~DoubleVector();
	/**
	 * bDeleteArrays is true if we delete the arrays in garbage collection
	 * set to true by default
	 */
	bool bDeleteArrays;
	double *el;			
};//class DoubleVector


/*! \struct IndexValuePair
 *  \brief A commonly used structure holding an index-value pair
 */
struct IndexValuePair{
	/** idx holds the index of an entity (such as a variable, constraint, objective)
	 *  that is part of a sparse vector
	 */
	int idx;

	/** value is a double that holds the value of the entity
	 */ 
	double value;
		
};

class OSGeneral{

};

enum ENUM_CPUSPEEDUNIT 
{
	ENUM_CPUSPEEDUNIT_hertz = 1,
	ENUM_CPUSPEEDUNIT_kilohertz,
	ENUM_CPUSPEEDUNIT_megahertz,
	ENUM_CPUSPEEDUNIT_gigahertz,
	ENUM_CPUSPEEDUNIT_terahertz,
	ENUM_CPUSPEEDUNIT_flops,
	ENUM_CPUSPEEDUNIT_kiloflops,
	ENUM_CPUSPEEDUNIT_megaflops,
	ENUM_CPUSPEEDUNIT_gigaflops,
	ENUM_CPUSPEEDUNIT_teraflops,
	ENUM_CPUSPEEDUNIT_petaflops
};

inline int verifyCPUSpeedUnit(std::string unit)
{
			if (unit == "hertz"    ) return ENUM_CPUSPEEDUNIT_hertz;
			if (unit == "kilohertz") return ENUM_CPUSPEEDUNIT_kilohertz;
			if (unit == "megahertz") return ENUM_CPUSPEEDUNIT_megahertz;
			if (unit == "gigahertz") return ENUM_CPUSPEEDUNIT_gigahertz;
			if (unit == "terahertz") return ENUM_CPUSPEEDUNIT_terahertz;
			if (unit == "flops"    ) return ENUM_CPUSPEEDUNIT_flops;
			if (unit == "kiloflops") return ENUM_CPUSPEEDUNIT_kiloflops;
			if (unit == "megaflops") return ENUM_CPUSPEEDUNIT_megaflops;
			if (unit == "gigaflops") return ENUM_CPUSPEEDUNIT_gigaflops;
			if (unit == "teraflops") return ENUM_CPUSPEEDUNIT_teraflops;
			if (unit == "petaflops") return ENUM_CPUSPEEDUNIT_petaflops;
			return 0;
}//verifyCPUSpeedUnit

enum ENUM_STORAGEUNIT 
{
	ENUM_STORAGEUNIT_byte = 1,
	ENUM_STORAGEUNIT_kilobyte,
	ENUM_STORAGEUNIT_megabyte,
	ENUM_STORAGEUNIT_gigabyte,
	ENUM_STORAGEUNIT_terabyte,
	ENUM_STORAGEUNIT_petabyte,
	ENUM_STORAGEUNIT_exabyte,
	ENUM_STORAGEUNIT_zettabyte,
	ENUM_STORAGEUNIT_yottabyte
};

inline int verifyStorageUnit(std::string unit)
{
			if (unit == "byte"     ) return ENUM_STORAGEUNIT_byte;
			if (unit == "kilobyte" ) return ENUM_STORAGEUNIT_kilobyte;
			if (unit == "megabyte" ) return ENUM_STORAGEUNIT_megabyte;
			if (unit == "gigabyte" ) return ENUM_STORAGEUNIT_gigabyte;
			if (unit == "terabyte" ) return ENUM_STORAGEUNIT_terabyte;
			if (unit == "petabyte" ) return ENUM_STORAGEUNIT_petabyte;
			if (unit == "exabyte"  ) return ENUM_STORAGEUNIT_exabyte;
			if (unit == "zettabyte") return ENUM_STORAGEUNIT_zettabyte;
			if (unit == "yottabyte") return ENUM_STORAGEUNIT_yottabyte;
			return 0;
}//verifyStorageUnit

enum ENUM_TIMEUNIT 
{
	ENUM_TIMEUNIT_millisecond = 1,
	ENUM_TIMEUNIT_second,
	ENUM_TIMEUNIT_minute,
	ENUM_TIMEUNIT_hour,
	ENUM_TIMEUNIT_day,
	ENUM_TIMEUNIT_week,
	ENUM_TIMEUNIT_month,
	ENUM_TIMEUNIT_year
};

inline int verifyTimeUnit(std::string unit)
{
			if (unit == "millisecond") return ENUM_TIMEUNIT_millisecond;
			if (unit == "second"     ) return ENUM_TIMEUNIT_second;
			if (unit == "minute"     ) return ENUM_TIMEUNIT_minute;
			if (unit == "hour"       ) return ENUM_TIMEUNIT_hour;
			if (unit == "day"        ) return ENUM_TIMEUNIT_day;
			if (unit == "week"       ) return ENUM_TIMEUNIT_week;
			if (unit == "month"      ) return ENUM_TIMEUNIT_month;
			if (unit == "year"       ) return ENUM_TIMEUNIT_year;
			return 0;
}//verifyTimeUnit

enum ENUM_VARTYPE 
{
	ENUM_VARTYPE_CONTINUOUS = 1,
	ENUM_VARTYPE_INTEGER,
	ENUM_VARTYPE_BINARY,
	ENUM_VARTYPE_SEMICONTINUOUS,
	ENUM_VARTYPE_SEMIINTEGER,
	ENUM_VARTYPE_STRING
};

inline int verifyVarType(char vt)
{
			if (vt == 'C') return ENUM_VARTYPE_CONTINUOUS;
			if (vt == 'B') return ENUM_VARTYPE_BINARY;
			if (vt == 'I') return ENUM_VARTYPE_INTEGER;
			if (vt == 'S') return ENUM_VARTYPE_STRING;
			if (vt == 'D') return ENUM_VARTYPE_SEMICONTINUOUS;
			if (vt == 'J') return ENUM_VARTYPE_SEMIINTEGER;
			return 0;
}//verifyVarType


#endif
