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

#ifndef ___MovingEvarage_H___
#define ___MovingEvarage_H___

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <iterator>

//
namespace NStatisticAlg
{
//!@ingroup amgStatistic
//! @brief Реализиция алгоритма скользящего среднего (Simple Moving Average) для
//! сглаживания набора значений.
//! 
//! Пример:
//! @code
//!    double d_data[10] = {1.234, 2.298, 4.355, 8.41, 10.54, 6.645, 11.36, 15.898, 12.999, 10.111};
//!    vector<double> smoothed_vector;
//!    smoothed_vector.reserve(10);
//!
//!    // применение функтора MovingAverage к исходному массиву, сглаживание набора значений
//!    for_each(d_data, d_data + 10, СMovingAverage(smoothed_vector, 5));  // C++11
//!	 // вывод результирующего массива
//!    copy(smoothed_vector.begin(), smoothed_vector.end(), ostream_iterator<double>(cout, "\n"));
//! @endcode
class CMovingAverage
{
    std::queue<double> m_window;	// окно
	 size_t m_period;				// максимальный размер окна (показатель сглаживания)
	 double m_sum;					// сумма элементов в окне
    std::vector<double> &m_out;		// выходной вектор

public:
    CMovingAverage(std::vector<double> &out, size_t period) : m_period(period), m_out(out) {}

    //! @brief Алгоритм сглаживания набора значений
    void operator()(double num)
    {
       m_sum += num;
       m_window.push(num);
       if (m_window.size() > m_period)
		 {
           m_sum -= m_window.front();
           m_window.pop();
       }
       m_out.push_back(m_sum / m_window.size());
    }
};
//
}
//
}
//

#endif /* ___MovingEvarage_H___ */
