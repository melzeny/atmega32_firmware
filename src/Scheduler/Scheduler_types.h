/*
 * Scheduler_types.h
 *
 *  Created on: Jul 19, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef F15_REPO_SRC_SCHEDULER_SCHEDULER_TYPES_H_
#define F15_REPO_SRC_SCHEDULER_SCHEDULER_TYPES_H_

typedef struct
{
	uint8 TaskId;
	Ptr2FuncType Ptr2task;
	uint32 Periodicity;
	STD_StatusType Status;

}Scheduler_TaskType;


#endif /* F15_REPO_SRC_SCHEDULER_SCHEDULER_TYPES_H_ */
