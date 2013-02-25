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

#ifndef ___Statistic_H___
#define ___Statistic_H___

#include <iostream>
#include <vector>
#include <time.h>
#include <ctime>
#include <math.h>

#include "StatisticEvaluations.h"
#include "StatisticEvents.h"

using namespace NStatisticEvaluations;
using namespace NStatisticEvents;

//
namespace NStatistic
{
//!@defgroup amgStatistic Статистика
//! @brief Общий класс статистики
//!
//! Шаблонный класс статистики, предназначенный для доступа
//! к основным функциям статистики. Все классы реализованы в виде шаблонов,
//! позволяющие использовать различные типы данных.
//!
//! Пример:
//! @code
//!    const int n = 10;
//!    statistic<double> ex_d;        // расчет статистики дробных
//!    double d_data[n] = {1.234, 2.298, 4.355, 8.41, 10.54, 6.645, 11.36, 15.898, 12.999, 10.111};
//!
//!    // заполнение очереди событиями (значениями)
//!    for (int i = 0; i < n; ++i)
//!       ex_d.GetStatEvents()->StatisticEvent(d_data[i]);
//!
//!    // статическая оценка сумма, минимальное значение, среднеквадратическое отклонение
//!    ex_d.GetStatEvaluations()->VectorSum(ex_d.GetStatEvents()->GetParamsQueue());
//!    ex_d.GetStatEvaluations()->VectorMinValue(ex_d.GetStatEvents()->GetParamsQueue());
//!    ex_d.GetStatEvaluations()->VectorStdDeviation(ex_d.GetStatEvents()->GetParamsQueue());
//!
//!    // вывод статической оценки
//!    cout << "Sum: " << ex_d.GetStatEvaluations()->GetSum() << ", "
//!         << "Min: " << ex_d.GetStatEvaluations()->GetMin() << ", "
//!         << "StdDeviation: " << ex_d.GetStatEvaluations()->GetStdDeviation() << endl;
//! @endcode
//!
//! Вывод:
//! Sum: 83.85, Min: 1.234, StdDeviation: 9.51182
//!
template <class T> class statistic
{
public:
	statistic()
	{
      m_statEvaluations = new statisticEvaluations<T>();
      m_statEvents = new statisticEvents<T>();
	}

   ~statistic()
   {
      delete m_statEvaluations;
      delete m_statEvents;
   }

   //! @brief Доступ к функциям расчета статической оценки
   statisticEvaluations<T>* GetStatEvaluations()
   {
      return m_statEvaluations;
   }
   //! @brief Доступ к функциям обработки очереди событий
   statisticEvents<T>* GetStatEvents()
   {
      return m_statEvents;
   }
private:
   // copy and assignment not allowed
   statistic(const statistic<T>&);
   statistic<T>& operator=(const statistic<T>&);

   statisticEvaluations<T>* m_statEvaluations;
   statisticEvents<T>* m_statEvents;
};
//
}
//
#endif /* ___Statistic_H___ */
