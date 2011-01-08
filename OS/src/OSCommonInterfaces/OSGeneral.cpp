/* $Id: OSGeneral.cpp 3186 2010-02-06 23:38:35Z Gassmann $ */
/** @file OSGeneral.cpp
 * 
 * @author Horand Gassmann, Jun Ma, Kipp Martin
 *
 * \remarks
 * Copyright (C) 2005-2011, Horand Gassmann, Jun Ma, Kipp Martin,
 * Dalhousie University, Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */

#include "OSGeneral.h"
#include "OSParameters.h"
#include "OSErrorClass.h"
#include "OSMathUtil.h"
#include "OSBase64.h"

#include <iostream>
#include <sstream>

//#define DEBUG_OSGENERAL
//#define DEBUG_ISEQUAL_ROUTINES

using namespace std;
using std::cout;
using std::endl;


SparseVector::SparseVector( int number_):
number( number_)
{
	indexes = new int[ number];
	values = new double[ number];
	bDeleteArrays = true;
}// end SparseVector constructor


SparseVector::SparseVector( ):
	bDeleteArrays(true),
	indexes( NULL),
	values( NULL)
{
}// end SparseVector constructor

SparseVector::~SparseVector(){
	#ifdef DEBUG
	cout << "inside sparseVector destructor" << endl;
	#endif
	if(	bDeleteArrays == true){
#ifdef DEBUG
cout << "delete[] indexes and arrays" << endl;
#endif
		delete[] indexes;
		delete[] values;
	}
	values = NULL;
	indexes = NULL;
}// end SparseVector constructor

SparseMatrix::SparseMatrix():
	bDeleteArrays( true),
	isColumnMajor(true),
	startSize(0),
	valueSize(0),
	starts(NULL),
	indexes(NULL),
	values(NULL)
{
}// end SparseMatrix Constructor



SparseMatrix::SparseMatrix(bool isColumnMajor_, int startSize_, int valueSize_):
	isColumnMajor(isColumnMajor_), 
	startSize(startSize_),
	valueSize(valueSize_)
{
	bDeleteArrays = true;
	starts = new int[startSize];
	indexes = new int[valueSize];
	values = new double[valueSize];
		
}//end SparseMatrix constructor


SparseMatrix::~SparseMatrix(){
	#ifdef DEBUG
	cout << "inside SparseMatrix destructor" << endl;
	#endif
	if( bDeleteArrays == true){
		delete[] starts;
		delete[] indexes;
		delete[] values;

	}
	starts = NULL;
	indexes = NULL;
	values = NULL;
}// end SparseMatrix Destructor


bool SparseMatrix::display(int secondaryDim){
		int i, j, k;
		for ( i = 0; i < startSize - 1; i++){			
			
			if (starts[i] == starts[i + 1]){
				
				for ( k = 0; k < secondaryDim; k++){
					//System.out.print("0,");					
				}				
			}
			else {
				for ( j = 0; j < indexes[starts[i]]; j ++){				
					//System.out.print("0,");					
				}
				
				for ( j = starts[ i ]; j < starts[i + 1]; j++){
					
					//System.out.print (values[j] + ",");
					
					if ( j < starts[i + 1] - 1){
						for ( k = indexes [j] + 1; k < indexes[j + 1]; k++){
							//System.out.print("0,");					
						}
					}
					else {
						
						for ( k = indexes [j] + 1; k < secondaryDim; k++){
							//System.out.print("0,");					
						}
					}
				}
			}
			//System.out.println();
		}

		return true;
		
	}//display
	
SparseJacobianMatrix::SparseJacobianMatrix():
	bDeleteArrays( true),
	startSize(0),
	valueSize(0),
	starts(NULL),
	conVals(NULL),
	indexes(NULL),
	values(NULL)
{
}// end SparseJaccobianMatrix Constructor


SparseJacobianMatrix::SparseJacobianMatrix(int startSize_, int valueSize_):
	bDeleteArrays( true),
	startSize(startSize_),
	valueSize(valueSize_)
{
	starts = new int[startSize];
	conVals = new int[startSize];
	indexes = new int[valueSize];
	values = new double[valueSize];		
}//end SparseJacobianMatrix constructor


SparseJacobianMatrix::~SparseJacobianMatrix(){
	#ifdef DEBUG
	cout << "inside SparseJacobianMatrix destructor" << endl;
	#endif
	if(bDeleteArrays == true){
		#ifdef DEBUG
		cout << "delete SparseJacobianArrays" << endl;
		#endif
		delete[] starts;
		delete[] conVals;
		delete[] indexes;
		delete[] values;
	}
		starts = NULL;
		conVals = NULL;
		indexes = NULL;
		values = NULL;
}// end SparseJacobianMatrix Destructor


SparseHessianMatrix::SparseHessianMatrix():
	bDeleteArrays( true),
	hessDimension(0),
	hessRowIdx( NULL),
	hessColIdx( NULL),
	hessValues( NULL)
{
}// end SparseHessianMatrix Constructor



SparseHessianMatrix::~SparseHessianMatrix(){
	#ifdef DEBUG
	cout << "inside SparseHessianMatrix destructor" << endl;
	#endif
	if(bDeleteArrays == true){
		delete[] hessRowIdx;
		delete[] hessColIdx;
		delete[] hessValues;
	}
	hessRowIdx = NULL;
	hessColIdx = NULL;
	hessValues = NULL;
}// end SparseHessianMatrix Destructor


	
QuadraticTerms::QuadraticTerms():
	rowIndexes(NULL),
	varOneIndexes(NULL),
	varTwoIndexes(NULL),
	coefficients(NULL)
{
}

QuadraticTerms::~QuadraticTerms(){
	#ifdef DEBUG
	cout << "inside Quadratic Terms destructor" << endl;
	#endif
	delete[] rowIndexes;
	rowIndexes = NULL;
	delete[] varOneIndexes;
	varOneIndexes = NULL;
	delete[] varTwoIndexes;
	varTwoIndexes = NULL;
	delete[] coefficients;
	coefficients = NULL;
}


IntVector::IntVector():
	bDeleteArrays(true),
	numberOfEl(0),
	el(NULL)
{  
	#ifdef DEBUG
	cout << "Inside the IntVector Constructor" << endl;
	#endif
} 


IntVector::IntVector(int n):
	bDeleteArrays(true)
{  
	#ifdef DEBUG
	cout << "Inside the IntVector Constructor" << endl;
	#endif

	numberOfEl = n;
	el = new int[n];
} 

IntVector::~IntVector(){  
	#ifdef DEBUG
	cout << "Inside the IntVector Destructor" << endl;
	#endif
	if(	bDeleteArrays == true){
		delete[] el;
		el = NULL;
	}
} 

bool IntVector::setIntVector(int *i, int ni)
{
	if (this->numberOfEl != 0)
		delete[] this->el;

	this->numberOfEl = ni;
	this->el = new int[ni];

	for (int j=0; j<ni; j++)
		this->el[j] = i[j];
	return true;
}//setIntVector

bool IntVector::extendIntVector(int i)
{
	std::cout << "extending an intvector" << std::endl;
	std::cout << "is object NULL " << (this == NULL) << std::endl;
	std::cout << "is el NULL " << (this->el == NULL) << std::endl;
	std::cout << "continue" << std::endl;

	int ni;
//	if (this == NULL)
//		this = new IntVector();

	if (this->el == NULL)
		ni = 0;
	else
		ni = this->numberOfEl;

	std::cout << "ni = " << ni << std::endl;

	int* temp = new int[ni+1];
	for (int j = 0; j < ni; ++j)
			temp[j] = this->el[j]; 

	std::cout << "made a temporary copy" << std::endl;

	delete[] this->el;

	std::cout << "deleted old location" << std::endl;

	temp[ni] = i;

	std::cout << "store new" << std::endl;

	this->el = temp;
	this->numberOfEl = ++ni;
	std::cout << "successfully extended an intvector" << std::endl;

	return true;
}//setIntVector

int IntVector::getNumberOfEl()
{
	return this->numberOfEl;
}

int IntVector::getEl(int j)
{
	if (j < 0 || j >= this->numberOfEl)
		throw ErrorClass("Attempting to access undefined memory in IntVector::getEl(j)");  
	return this->el[j];
}

bool IntVector::getEl(int* i)
{
	for (int j=0; j < this->numberOfEl; ++j)
		i[j] = this->el[j];  
	return true;
}

bool IntVector::IsEqual(IntVector *that)
{
	#ifdef DEBUG_ISEQUAL_ROUTINES
		cout << "Start comparing in IntVector" << endl;
	#endif
	if (this == NULL)
	{	if (that == NULL)
			return true;
		else
		{
			#ifdef DEBUG_ISEQUAL_ROUTINES
				cout << "First object is NULL, second is not" << endl;
			#endif
			return false;
		}
	}
	else 
	{	if (that == NULL)
		{
			#ifdef DEBUG_ISEQUAL_ROUTINES
				cout << "Second object is NULL, first is not" << endl;
			#endif
			return false;
		}
		else	
		{
			if (this->numberOfEl != that->numberOfEl)
			{
#ifdef DEBUG_ISEQUAL_ROUTINES
				cout << "numberOfEl: " << this->numberOfEl << " vs. " << that->numberOfEl << endl;
#endif	
				return false;
			}
			for (int i=0; i<this->numberOfEl; i++)
			{
				if (this->el[i] != that->el[i])
				{

#ifdef DEBUG_ISEQUAL_ROUTINES
					cout << "El[" << i << "]: " << this->el[i] << " vs. " << that->el[i] << endl;
#endif	
					return false;
				}
			}
			return true;
		}
	}
}//IntVector::IsEqual


OtherOptionEnumeration::OtherOptionEnumeration():
	IntVector(),
	value(""),
	description("")
{  
	#ifdef DEBUG
	cout << "Inside the OtherOptionEnumeration Constructor" << endl;
	#endif
} 

OtherOptionEnumeration::OtherOptionEnumeration(int n):
	IntVector(n),
	value(""),
	description("")
{  
	#ifdef DEBUG
	cout << "Inside the OtherOptionEnumeration Constructor" << endl;
	#endif
} 

OtherOptionEnumeration::~OtherOptionEnumeration()
{  
	#ifdef DEBUG
	cout << "Inside the OtherOptionEnumeration Destructor" << endl;
	#endif
} 

bool OtherOptionEnumeration::setOtherOptionEnumeration(std::string value, std::string description, int *i, int ni)
{
	this->value = value;
	this->description = description;
	return this->IntVector::setIntVector(i, ni);
}

std::string OtherOptionEnumeration::getValue()
{
	return this->value;
}

std::string OtherOptionEnumeration::getDescription()
{
	return this->description;
}



bool OtherOptionEnumeration::IsEqual(OtherOptionEnumeration *that)
{
	#ifdef DEBUG_ISEQUAL_ROUTINES
		cout << "Start comparing in OtherOptionEnumeration" << endl;
	#endif
	if (this == NULL)
	{	if (that == NULL)
			return true;
		else
		{
			#ifdef DEBUG_ISEQUAL_ROUTINES
				cout << "First object is NULL, second is not" << endl;
			#endif
			return false;
		}
	}
	else 
	{	if (that == NULL)
		{
			#ifdef DEBUG_ISEQUAL_ROUTINES
				cout << "Second object is NULL, first is not" << endl;
			#endif
			return false;
		}
		else	
		{
			if (this->value != that->value || this->description != that->description)
			{
#ifdef DEBUG_ISEQUAL_ROUTINES
				cout << "value:       " << this->value       << " vs. " << that->value       << endl;
				cout << "description: " << this->description << " vs. " << that->description << endl;
#endif	
				return false;
			}

			return this->IntVector::IsEqual(that);
		}
	}
}//OtherOptionEnumeration::IsEqual



DoubleVector::DoubleVector():
	bDeleteArrays(true),
	el(NULL)
{
	#ifdef DEBUG
	cout << "Inside the DoubleVector Constructor" << endl;
	#endif

}


DoubleVector::~DoubleVector(){  
	#ifdef DEBUG
	cout << "Inside the DoubleVector Destructor" << endl;
	#endif
	if(	bDeleteArrays == true){
		delete[] el;
		el = NULL;
	}
}


bool DoubleVector::IsEqual(DoubleVector *that)
{
	#ifdef DEBUG_ISEQUAL_ROUTINES
		cout << "Start comparing in DoubleVector" << endl;
	#endif
	if (this == NULL)
	{	if (that == NULL)
			return true;
		else
		{
			#ifdef DEBUG_ISEQUAL_ROUTINES
				cout << "First object is NULL, second is not" << endl;
			#endif
			return false;
		}
	}
	else 
	{	if (that == NULL)
		{
			#ifdef DEBUG_ISEQUAL_ROUTINES
				cout << "Second object is NULL, first is not" << endl;
			#endif
			return false;
		}
		else	
		{
			if (this->numberOfEl != that->numberOfEl)
			{
#ifdef DEBUG_ISEQUAL_ROUTINES
				cout << "numberOfEl: " << this->numberOfEl << " vs. " << that->numberOfEl << endl;
#endif	
				return false;
			}
			for (int i=0; i<this->numberOfEl; i++)
			{
				if (this->el[i] != that->el[i])
				{

#ifdef DEBUG_ISEQUAL_ROUTINES
					cout << "El[" << i << "]: " << this->el[i] << " vs. " << that->el[i] << endl;
#endif	
					return false;
				}
			}
			return true;
		}
	}
}//DoubleVector::IsEqual


BasisStatus::BasisStatus():
	basic(NULL),
	atLower(NULL),
	atUpper(NULL),
	isFree(NULL),
	superbasic(NULL),
	unknown(NULL)
{ 
	#ifdef DEBUG_OSRESULT
	cout << "Inside the BasisStatus Constructor" << endl;
	#endif
}//end BasisStatus constructor


BasisStatus::~BasisStatus()
{
	#ifdef DEBUG_OSRESULT  
	cout << "Inside the BasisStatus Destructor" << endl;
	#endif
	if (basic != NULL)
	{
		delete basic;
		basic = NULL;
	}
	if (atLower != NULL)
	{
		delete atLower;
		atLower = NULL;
	}
	if (atUpper != NULL)
	{
		delete atUpper;
		atUpper = NULL;
	}
	if (isFree != NULL)
	{
		delete isFree;
		isFree = NULL;
	}
	if (superbasic != NULL)
	{
		delete superbasic;
		superbasic = NULL;
	}
	if (unknown != NULL)
	{
		delete unknown;
		unknown = NULL;
	}
}// end BasisStatus destructor 


bool BasisStatus::setIntVector(int status, int *i, int ni)
{
	switch (status)
	{
		case ENUM_BASIS_STATUS_basic:
		{
			if (this->basic == NULL) this->basic = new IntVector();
//			else delete[] this->basic;
			return this->basic->setIntVector(i, ni);
		}
		case ENUM_BASIS_STATUS_atLower:
		{
			if (this->atLower == NULL) this->atLower = new IntVector(ni);
//			else delete[] this->atLower;
			return this->atLower->setIntVector(i, ni);
		}
		case ENUM_BASIS_STATUS_atUpper:
		{
			if (this->atUpper == NULL) this->atUpper = new IntVector(ni);
//			else delete[] this->atUpper;
			return this->atUpper->setIntVector(i, ni);
		}
		case ENUM_BASIS_STATUS_isFree:
		{
			if (this->isFree == NULL) this->isFree = new IntVector(ni);
//			else delete[] this->isFree;
			return this->isFree->setIntVector(i, ni);
		}
		case ENUM_BASIS_STATUS_superbasic:
		{
			if (this->superbasic == NULL) this->superbasic = new IntVector(ni);
//			else delete[] this->superbasic;
			return this->superbasic->setIntVector(i, ni);
		}
		case ENUM_BASIS_STATUS_unknown:
		{
			if (this->unknown == NULL) this->unknown = new IntVector(ni);
//			else delete[] this->unknown;
			return this->unknown->setIntVector(i, ni);
		}
	default:
		throw ErrorClass("Unknown basis status encountered in BasisStatus::setIntVector");  
	 }
}//BasisStatus::setIntVector

bool BasisStatus::addIdx(int status, int idx)
{
	switch (status)
	{
		case ENUM_BASIS_STATUS_basic:
		{
			if (this->basic == NULL) this->basic = new IntVector();
			return this->basic->extendIntVector(idx);
		}
		case ENUM_BASIS_STATUS_atLower:
		{
			if (this->atLower == NULL) this->atLower = new IntVector();
			return this->atLower->extendIntVector(idx);
		}
		case ENUM_BASIS_STATUS_atUpper:
		{
			if (this->atUpper == NULL) this->atUpper = new IntVector();
			return this->atUpper->extendIntVector(idx);
		}
		case ENUM_BASIS_STATUS_isFree:
		{
			if (this->isFree == NULL) this->isFree = new IntVector();
			return this->isFree->extendIntVector(idx);
		}
		case ENUM_BASIS_STATUS_superbasic:
		{
			if (this->superbasic == NULL) this->superbasic = new IntVector();
			return this->superbasic->extendIntVector(idx);
		}
		case ENUM_BASIS_STATUS_unknown:
		{
			if (this->unknown == NULL) this->unknown = new IntVector();
			return this->unknown->extendIntVector(idx);
		}
	default:
		throw ErrorClass("Unknown basis status encountered in BasisStatus::addIdx");  
	 }
}//BasisStatus::addIdx


bool BasisStatus::getIntVector(int status, int *i)
{
	switch (status)
	{
		case ENUM_BASIS_STATUS_basic:
		{
			if (this->basic == NULL) return false;
			return this->basic->getEl(i);
		}
		case ENUM_BASIS_STATUS_atLower:
		{
			if (this->atLower == NULL) return false;
			return this->atLower->getEl(i);
		}
		case ENUM_BASIS_STATUS_atUpper:
		{
			if (this->atUpper == NULL) return false;
			return this->atUpper->getEl(i);
		}
		case ENUM_BASIS_STATUS_isFree:
		{
			if (this->isFree == NULL) return false;
			return this->isFree->getEl(i);
		}
		case ENUM_BASIS_STATUS_superbasic:
		{
			if (this->superbasic == NULL) return false;
			return this->superbasic->getEl(i);
		}
		case ENUM_BASIS_STATUS_unknown:
		{
			if (this->unknown == NULL) return false;
			return this->unknown->getEl(i);
		}
	default:
		throw ErrorClass("Unknown basis status encountered in setIntVector");  
	 }
}//BasisStatus::getIntVector


int BasisStatus::getNumberOfEl(int status)
{
	switch (status)
	{
		case ENUM_BASIS_STATUS_basic:
		{
			if (this->basic == NULL) return -1;
			else return	this->basic->numberOfEl;
		}
		case ENUM_BASIS_STATUS_atLower:
		{
			if (this->atLower == NULL) return -1;
			else return	this->atLower->numberOfEl;
		}
		case ENUM_BASIS_STATUS_atUpper:
		{
			if (this->atUpper == NULL) return -1;
			else return	this->atUpper->numberOfEl;
		}
		case ENUM_BASIS_STATUS_isFree:
		{
			if (this->isFree == NULL) return -1;
			else return	this->isFree->numberOfEl;
		}
		case ENUM_BASIS_STATUS_superbasic:
		{
			if (this->superbasic == NULL) return -1;
			else return	this->superbasic->numberOfEl;
		}
		case ENUM_BASIS_STATUS_unknown:
		{
			if (this->unknown == NULL) return -1;
			else return	this->unknown->numberOfEl;
		}
	default:
		throw ErrorClass("Unknown basis status encountered in getBasisStatusNumberOfEl");  
	 }
}//getNumberOfEl


int BasisStatus::getEl(int status, int j)
{
	switch (status)
	{
		case ENUM_BASIS_STATUS_basic:
		{
			if (this->basic == NULL) 
				throw ErrorClass("\"basic\" index array never defined in routine BasisStatus::getEl()");
			else return	this->basic->el[j];
		}
		case ENUM_BASIS_STATUS_atLower:
		{
			if (this->atLower == NULL)
				throw ErrorClass("\"atLower\" index array never defined in routine BasisStatus::getEl()");
			else return	this->atLower->el[j];
		}
		case ENUM_BASIS_STATUS_atUpper:
		{
			if (this->atUpper == NULL)
				throw ErrorClass("\"atUpper\" index array never defined in routine BasisStatus::getEl()");
			else return	this->atUpper->el[j];
		}
		case ENUM_BASIS_STATUS_isFree:
		{
			if (this->isFree == NULL)
				throw ErrorClass("\"isFree\" index array never defined in routine BasisStatus::getEl()");
			else return	this->isFree->el[j];
		}
		case ENUM_BASIS_STATUS_superbasic:
		{
			if (this->superbasic == NULL)
				throw ErrorClass("\"superbasic\" index array never defined in routine BasisStatus::getEl()");
			else return	this->superbasic->el[j];
		}
		case ENUM_BASIS_STATUS_unknown:
		{
			if (this->unknown == NULL)
				throw ErrorClass("\"unknown\" index array never defined in routine BasisStatus::getEl()");
			else return	this->unknown->el[j];
		}
	default:
		throw ErrorClass("Unknown basis status encountered in getBasisStatusNumberOfEl");  
	 }
}//getEl

bool BasisStatus::IsEqual(BasisStatus *that)
{
	#ifdef DEBUG_ISEQUAL_ROUTINES
		cout << "Start comparing in BasisStatus" << endl;
	#endif
	if (this == NULL)
	{	if (that == NULL)
			return true;
		else
		{
			#ifdef DEBUG_ISEQUAL_ROUTINES
				cout << "First object is NULL, second is not" << endl;
			#endif
			return false;
		}
	}
	else 
	{	if (that == NULL)
		{
			#ifdef DEBUG_ISEQUAL_ROUTINES
				cout << "Second object is NULL, first is not" << endl;
			#endif
			return false;
		}
		else	
		{
			if (      !this->basic->IsEqual(that->basic)      ) return false;
			if (    !this->atLower->IsEqual(that->atLower)    ) return false;
			if (    !this->atUpper->IsEqual(that->atUpper)    ) return false;
			if (     !this->isFree->IsEqual(that->isFree)     ) return false;
			if ( !this->superbasic->IsEqual(that->superbasic) ) return false;
			if (    !this->unknown->IsEqual(that->unknown)    ) return false;

			return true;
		}
	}
}//BasisStatus::IsEqual

