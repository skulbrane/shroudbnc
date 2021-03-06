/*******************************************************************************
 * shroudBNC - an object-oriented framework for IRC                            *
 * Copyright (C) 2005-2014 Gunnar Beutner                                      *
 *                                                                             *
 * This program is free software; you can redistribute it and/or               *
 * modify it under the terms of the GNU General Public License                 *
 * as published by the Free Software Foundation; either version 2              *
 * of the License, or (at your option) any later version.                      *
 *                                                                             *
 * This program is distributed in the hope that it will be useful,             *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of              *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the               *
 * GNU General Public License for more details.                                *
 *                                                                             *
 * You should have received a copy of the GNU General Public License           *
 * along with this program; if not, write to the Free Software                 *
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA. *
 *******************************************************************************/

#ifndef TIMER_H
#define TIMER_H

typedef bool (*TimerProc)(time_t CurrentTime, void *Cookie);

/**
 * CTimer
 *
 * A timer.
 */
class SBNCAPI CTimer {
private:
	TimerProc m_Proc; /**< the function which should be called for the timer */
	void *m_Cookie; /**< a user-specific pointer which is passed to the timer's function */
	unsigned int m_Interval; /**< the timer's interval */
	bool m_Repeat; /**< determines whether the timer is executed repeatedly */
	time_t m_Next; /**< the next scheduled time of execution */
	link_t<CTimer *> *m_Link; /**< link in the timer list */

	bool Call(time_t Now);
	static void RescheduleTimers(void);

public:
#ifndef SWIG
	CTimer(unsigned int Interval, bool Repeat, TimerProc Function, void *Cookie);
	virtual ~CTimer(void);
#endif /* SWIG */

	static time_t GetNextCall(void);
	static void DestroyAllTimers(void);
	static void CallTimers(void);

	int GetInterval(void) const;
	bool GetRepeat(void) const;

	void Reschedule(time_t Next);

	void Destroy(void);
};

#endif /* TIMER_H */
