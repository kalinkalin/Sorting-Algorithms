/*
 * RandomSelect.h
 *
 *  Created on: Mar 24, 2018
 *      Author: kalinek
 */

#ifndef RANDOMSELECT_H_
#define RANDOMSELECT_H_

#include "Select.h"

class RandomSelect : public Select{

public:
	RandomSelect();
	int select(int* new_array, int p,int q, int k);
	int randomPartition(int A[], int p,int q);
	virtual ~RandomSelect();
};

#endif /* RANDOMSELECT_H_ */
