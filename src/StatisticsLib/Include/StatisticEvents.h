/*
 *
 * Copyright (C) 2013 Kirill Yudenok, Ph.D. student <kirill.yudenok@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; see the file COPYING.  If not, write to
 * the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 */

#ifndef ___StatisticEvents_H___
#define ___StatisticEvents_H___

#include <iostream>
#include <queue>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cerrno>

//
namespace NStatisticEvents
{
//!@ingroup amgStatistic
//! @brief  ласс статических событий, очереди статических событий
//!
//! Ўаблонный класс, предназначенный дл€ формаровани€ очереди событий, получени€ 
//! доступа и подсчета времени и скорости поступлени€ событий.
//! 
//! ѕример:
//! @code
//!    statistic<int> ex1;  
//!    int data[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//!
//!    for (int i = 0; i < 5; ++i)
//!        ex1.GetStatEvents()->StatisticEvent(data[i]);
//!
//!    ex1.GetStatEvaluations()->VectorStdDeviation(ex1.GetStatEvents()->GetParamsQueue());
//!    
//!    cout << "StdDeviation: " << ex1.GetStatEvaluations()->GetStdDeveation() << endl;
//! @endcode
template <class T> class statisticEvents
{
public:
	statisticEvents() { m_eventsCounter = 0; }

   /*!@brief ‘ормирование очереди событий
   * @param[in] parameter —обытий (число произвольного типа)
   */
	void StatisticEvent(T parameter);
   //! @brief ƒоступ к очереди событий
	std::vector<T> GetParamsQueue();
   //! @brief ѕолучение к текущему значению очереди событий
	T GetCurrStatParameter();
   //! @brief ѕолучение количества событий в очереди
	int EventsCount();
   
   //! @brief ѕолучение времени наступлени€ событи€ TODO
	void EventTime();	                  // get event time
   //! @brief ѕолучение скорости наступлени€ событи€ TODO
	double EventsSpeed();	              // number of events in time

	void ResetAllEventsData();

private:
	std::vector<T> m_paramsQueue;       // statistic parameters vector
	T m_currentStatParameter;	         // current statistic parameter
	int m_eventsCounter;

	time_t m_time;                      // event time
};

// statistic event
template <class T>
void statisticEvents<T>::StatisticEvent(T parameter)
{
	m_currentStatParameter = parameter;
	m_paramsQueue.push_back(parameter);

	// check time
	m_time = time(NULL);
	m_eventsCounter++;
}

template <class T>
std::vector<T> statisticEvents<T>::GetParamsQueue()
{
	return m_paramsQueue;
}

// get current stat parameter
template <class T>
T statisticEvents<T>::GetCurrStatParameter()
{
	return m_currentStatParameter;
}

// events counter
template <class T>
int statisticEvents<T>::EventsCount()
{
	return m_eventsCounter;
}

// event time
template <class T>
void statisticEvents<T>::EventTime()
{
	struct tm *eventTime;
	//errno_t err;
	double msTime;

	//err = localtime_s(&eventTime, &m_time);
	eventTime = localtime(&m_time);
	//if (err) {
	//	std::cout << "Invalid argument to localtime_s" << std::endl;
	//	exit(1);
	//}

	msTime = eventTime->tm_sec / 1000;
	std::cout << msTime << " ms" << std::endl;
}

// number of events
template <class T>
double statisticEvents<T>::EventsSpeed()
{
	double speed = 0;
	struct tm *curTimeInfo;
	struct tm *eventTimeInfo;
	//errno_t curTimeErr, eventTimeErr;

	time_t currentTime = time(NULL);
	curTimeInfo = localtime(&currentTime);
	//if (curTimeErr) {
	//	std::cout << "Invalid argument to localtime_s" << std::endl;
	//	exit(1);
	//}
	std::cout << "curTimeInfo: " << curTimeInfo->tm_sec << std::endl;

	eventTimeInfo = localtime(&m_time);
	//if (eventTimeErr) {
	//	std::cout << "Invalid argument to localtime_s" << std::endl;
	//	exit(1);
	//}
	std::cout << "eventTimeInfo: " << eventTimeInfo->tm_sec << std::endl;

	speed = (curTimeInfo->tm_sec - eventTimeInfo->tm_sec) / 60;	// TEST TEST TEST

	return speed;
}

// clean all events queue data
template <class T>
void statisticEvents<T>::ResetAllEventsData()
{
	m_eventsCounter = 0;
}
//
}
//
#endif /* ___StatisticEvents_H___ */
