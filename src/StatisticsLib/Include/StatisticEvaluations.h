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

#ifndef ___StatisticEvaluations_H___
#define ___StatisticEvaluations_H___

#include <iostream>
#include <queue>
#include <vector>

//
namespace NStatisticEvaluations
{
//!@ingroup amgStatistic
//! @brief Класс статической оценки
//!
//! Шаблонный класс, предназначенный для расчета основных 
//! функций оценки статических данных: сумма, среднее, дисперсия и т.д. 
//! Также позволяет получить значения расчитынных оценок. Работает с очередью событий.
//! 
//! Пример:
//! @code
//!    statistic<int> ex1;
//!    int i_data[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//!    ex1.GetStatEvaluations()->Sum(i_data, 10); 
//!    ex1.GetStatEvaluations()->Min(i_data, 10);
//!    ex1.GetStatEvaluations()->StdDeviation(i_data, 10);
//!    cout << "Sum: " << ex1.GetStatEvaluations()->GetSum() << ", " 
//!         << "Min: " << ex1.GetStatEvaluations()->GetMin() << ", "
//!         << "StdDeviation: " << ex1.GetStatEvaluations()->GetStdDeveation() << endl;
//! @endcode
template <class T> class statisticEvaluations
{
public:
	statisticEvaluations() 
		: m_sum(0), m_min(0), m_max(0), m_mean(0), 
		  m_dispersion(0), m_math_expectation(0), m_std_deviation(0) {}

	// statistic parameters evaluation
    // delete after all ;)
    T Sum(T* data, const int n);
    T MeanValue(T* data, const int n);
	T Min(T* data, const int n);
	T Max(T* data, const int n);
	T Dispersion(T* data, const int n);
	double StdDeviation(T* data, const int n);
	T MathExpectation(T* data, const int n);

	// statistic parameters event evaluation
   //! @brief Подсчет суммы набора событий (очередь событий)
	T VectorSum(std::vector<T> data);
   //! @brief Подсчет среднего значения набора событий (очередь событий)
	T VectorMeanValue(std::vector<T> data);
   //! @brief Подсчет минимального значения набора событий (очередь событий)
	T VectorMinValue(std::vector<T> data);
   //! @brief Подсчет среднего значения набора событий (очередь событий)
	T VectorMaxValue(std::vector<T> data);
   //! @brief Подсчет математического ожидания набора событий (очередь событий)
	T VectorDispersion(std::vector<T> data);
   //! @brief Подсчет дисперсии набора событий (очередь событий)
	double VectorStdDeviation(std::vector<T> data);
   //! @brief Подсчет среднего отклонения набора событий (очередь событий)
	T VectorMathExpectation(std::vector<T> data);

   //! @brief Сброс всех значений
	void ResetAllStatData();

   //!@name Методы получения/установки значений статических оценок
   //@{
	// get/set statistic parameters functions
	T GetSum();
	void SetSum(T _sum);
	T GetMin();
	void SetMin(T _min);
	T GetMax();
	void SetMax(T _max);
	T GetMean();
	void SetMean(T _mean);
	T GetDispersion();
	void SetDispersion(T _dispersion);
	double GetStdDeviation();
	void SetStdDeviation(double _stdDeviation);
	T GetMathExpectation();
	void SetMathExpectation(T _mathExpectation);
   //@}

private:

	T m_sum, m_min, m_max, m_mean, m_dispersion, m_math_expectation;
	double m_std_deviation;
};

// sum value
template <class T>
T statisticEvaluations<T>::Sum(T *data, const int n)
{
	for (int i = 0; i < n; ++i)
		m_sum += data[i];

	return m_sum;
}
template <class T>
T  statisticEvaluations<T>::VectorSum(std::vector<T> data)
{
	for (int i = 0; i < static_cast<int>(data.size()); ++i)
		m_sum += data.at(i);

	return m_sum;
}
// mean value
template <class T>
T  statisticEvaluations<T>::MeanValue(T *data, const int n)
{
	T sum = 0;
	for (int i = 0; i < n; ++i)
		sum += data[i];

	m_mean = sum / n; // float

	return m_mean;
}
template <class T>
T statisticEvaluations<T>::VectorMeanValue(std::vector<T> data)
{
	T sum = 0;
	int size = data.size();

	for (int i = 0; i < size; ++i)
		sum += data.at(i);

	m_mean = sum / size;	// округление int

	return m_mean;
}
// min value
template <class T>
T statisticEvaluations<T>::Min(T* data, const int n)
{
	int imin;
	for (int i = imin = 0; i < n; ++i)
		if (data[i] < data[imin])
			imin = i; // int forever

	m_min = data[imin];

	return m_min;
}
template <class T>
T statisticEvaluations<T>::VectorMinValue(std::vector<T> data)
{
	int imin;
	for (int i = imin = 0; i < static_cast<int>(data.size()); ++i)
		if (data.at(i) < data.at(imin))
			imin = i; // int forever

	m_min = data.at(imin);

	return m_min;
}

// max value
template <class T>
T statisticEvaluations<T>::Max(T* data, const int n)
{
	int imax;
	for (int i = imax = 0; i < n; ++i)
		if (data[i] > data[imax])
			imax = i;

	m_max = data[imax];

	return m_max;
}
template <class T>
T statisticEvaluations<T>::VectorMaxValue(std::vector<T> data)
{
	int imax;   // = 0
	for (int i = imax = 0; i < static_cast<int>(data.size()); ++i)
		if (data.at(i) > data.at(imax))
			imax = i;

	m_max = data.at(imax);

	return m_max;
}

// math expectation
template <class T>
T statisticEvaluations<T>::MathExpectation(T *data, const int n)
{
	T sum = 0;
    for(int i = 0; i < n; ++i)
		sum += data[i];

	m_math_expectation = sum / n;

    return m_math_expectation;
}
template <class T>
T statisticEvaluations<T>::VectorMathExpectation(std::vector<T> data)
{
	T sum = 0;
	int size = data.size();

    for(int i = 0; i < size; ++i)
		sum += data.at(i);

	m_math_expectation = sum / size;

    return m_math_expectation;
}

// dispersion
template <class T>
T statisticEvaluations<T>::Dispersion(T *data, const int n)
{
	T k;

	for (int i = 0; i < n; ++i)
	{
		k = (data[i] - GetMean()) * (data[i] - GetMean());
		m_dispersion += k;
	}
	m_dispersion /= n;

	return m_dispersion;
}
template <class T>
T statisticEvaluations<T>::VectorDispersion(std::vector<T> data)
{
	T k;
	int size = data.size();

	for (int i = 0; i < size; ++i)
	{
		k = (data.at(i) - GetMean()) * (data.at(i) - GetMean());
		m_dispersion += k;
	}
	m_dispersion /= size;

	return m_dispersion;
}

// standart deviation
template <class T>
double statisticEvaluations<T>::StdDeviation(T *data, const int n)
{
	m_std_deviation = sqrt((double)(Dispersion(data, n)));
	return m_std_deviation;
}
template <class T>
double statisticEvaluations<T>::VectorStdDeviation(std::vector<T> data)
{
	m_std_deviation = sqrt((double)(VectorDispersion(data)));
	return m_std_deviation;
}

// clean all stat evaluations data
template <class T>
void statisticEvaluations<T>::ResetAllStatData()
{
	m_sum = m_min = m_max = m_mean = m_dispersion = m_math_expectation = 0;
	m_std_deviation = 0.0;
}

// get statistic parameterst function
template <class T>
T statisticEvaluations<T>::GetSum()
{
	return m_sum;
}
template <class T>
void statisticEvaluations<T>::SetSum(T _sum)
{
	m_sum = _sum;
}
template <class T>
T statisticEvaluations<T>::GetMin()
{
	return m_min;
}
template <class T>
void statisticEvaluations<T>::SetMin(T _min)
{
	m_min = _min;
}
template <class T>
T statisticEvaluations<T>::GetMax()
{
	return m_max;
}
template <class T>
void statisticEvaluations<T>::SetMax(T _max)
{
	m_max = _max;
}
template <class T>
T statisticEvaluations<T>::GetMean()
{
	return m_mean;
}
template <class T>
void statisticEvaluations<T>::SetMean(T _mean)
{
	m_mean = _mean;
}

template <class T>
T statisticEvaluations<T>::GetDispersion()
{
	return m_dispersion;
}
template <class T>
void statisticEvaluations<T>::SetDispersion(T _dispersion)
{
	m_dispersion = _dispersion;
}
template <class T>
double statisticEvaluations<T>::GetStdDeviation()
{
	return m_std_deviation;
}
template <class T>
void statisticEvaluations<T>::SetStdDeviation(double _stdDeviation)
{
	m_std_deviation = _stdDeviation;
}
template <class T>
T statisticEvaluations<T>::GetMathExpectation()
{
	return m_math_expectation;
}
template <class T>
void statisticEvaluations<T>::SetMathExpectation(T _mathExpectation)
{
	m_math_expectation = _mathExpectation;
}
//
}
//
#endif /* ___StatisticEvaluations_H___ */
