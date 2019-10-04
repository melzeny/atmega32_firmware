/*
 * Scheduler.h
 *
 *  Created on: Jul 19, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef F15_REPO_SRC_SCHEDULER_SCHEDULER_H_
#define F15_REPO_SRC_SCHEDULER_SCHEDULER_H_

#include "../utils/Std_Types.h"

void Scheduler_init(void);
void Scheduler_createTask(uint8 Id,
		Ptr2FuncType TaskPtr,
		uint32 TaskPeriodicity,
		STD_StatusType Status
);
void Scheduler_setPeriodicity(uint8 Id, uint32 Periodicity);
void Scheduler_setSatus(uint8 Id, STD_StatusType Status);

#endif /* F15_REPO_SRC_SCHEDULER_SCHEDULER_H_ */
