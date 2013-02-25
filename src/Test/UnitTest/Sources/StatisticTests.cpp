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

/**
*
*   StatisticTests.cpp
*
*/
#include <UnitTest/UnitTest++.h>
#include "Statistic.h"

using namespace NStatistic;

using namespace std;

static const int n = 10;

SUITE(UAmgStatistics)
{
   // SUM TESTS
   TEST(StatisticSumIntUnit)
   {
      statistic<int> pack_int;
      int i_data[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
      const int i_sum = 55;

      int sum_value = pack_int.GetStatEvaluations()->Sum(i_data, n);

      CHECK(sum_value == i_sum);
   }

   TEST(StatisticVectorSumIntTest)
   {
      statistic<int> pack_int;
      int i_data[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
      const int i_sum = 15;

      for (int i = 0; i < 5; ++i)
         pack_int.GetStatEvents()->StatisticEvent(i_data[i]);

      int sum_value = pack_int.GetStatEvaluations()->VectorSum(pack_int.GetStatEvents()->GetParamsQueue());

      CHECK(sum_value == i_sum);
   }
   TEST(StatisticSumIntTest2)
   {
      statistic<int> pack_int1;
      statistic<int> pack_int2;
      int i_data[n] = {10, 3, 6, 1, 0, 5, 9, 1, 2, 7};

      int sum_value1 = pack_int1.GetStatEvaluations()->Sum(i_data, n);
      int sum_value2 = pack_int2.GetStatEvaluations()->Sum(i_data, n);

      CHECK(sum_value1 == sum_value2);
   }
   TEST(StatisticSumFloatTest)
   {
      statistic<float> pack_float;
      float f_data[n] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f, 6.6f, 7.7f, 8.8f, 9.9f, 10.10f};
      float f_sum = 59.6f;

      float sum_value = pack_float.GetStatEvaluations()->Sum(f_data, n);

      CHECK_CLOSE(sum_value, f_sum, 0.01f);
   }

   TEST(StatisticVectorSumFloatTest)
   {
      statistic<float> pack_float;
      float f_data[n] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f, 6.6f, 7.7f, 8.8f, 9.9f, 10.10f};
      float f_sum = 16.5f;

      for (int i = 0; i < 5; ++i)
         pack_float.GetStatEvents()->StatisticEvent(f_data[i]);

      float sum_value = pack_float.GetStatEvaluations()->VectorSum(pack_float.GetStatEvents()->GetParamsQueue());
      CHECK(sum_value == f_sum);
   }

   // MEAN TESTS
   TEST(StatisticMeanIntTest)
   {
      statistic<int> pack_int;
      int i_data[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
      const int i_mean = 5;	// округление int'a = 5.5

      int mean_value = pack_int.GetStatEvaluations()->MeanValue(i_data, n);
      CHECK(mean_value == i_mean);
   }
   TEST(StatisticVectorMeanIntTest)
   {
      statistic<int> pack_int;
      int i_data[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
      const int i_mean = 3;	// size of params queue

      for (int i = 0; i < 5; ++i)
         pack_int.GetStatEvents()->StatisticEvent(i_data[i]);

      int mean_value = pack_int.GetStatEvaluations()->VectorMeanValue(pack_int.GetStatEvents()->GetParamsQueue());

      CHECK(mean_value == i_mean);
   }
   TEST(StatisticMeanFloatTest)
   {
      statistic<float> pack_float;
      float data[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
      const float f_mean = 5.5f;

      float mean_value = pack_float.GetStatEvaluations()->MeanValue(data, n);

      CHECK(mean_value == f_mean);
   }
   TEST(StatisticMeanFloatTest2)
   {
      statistic<float> pack_float;
      float f_data[n] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f, 6.6f, 7.7f, 8.8f, 9.9f, 10.10f};
      float f_mean = 5.96f;

      float mean_value = pack_float.GetStatEvaluations()->MeanValue(f_data, n);

      CHECK(mean_value == f_mean);
   }
   TEST(StatisticVectorMeanFloatTest)
   {
      statistic<float> pack_float;
      float f_data[n] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f, 6.6f, 7.7f, 8.8f, 9.9f, 10.10f};
      float f_mean = 3.3f;

      for (int i = 0; i < 5; ++i)
         pack_float.GetStatEvents()->StatisticEvent(f_data[i]);

      float mean_value = pack_float.GetStatEvaluations()->VectorMeanValue(pack_float.GetStatEvents()->GetParamsQueue());

      CHECK(mean_value == f_mean);
   }

   // MIN TESTS
   TEST(StatisticMinIntTest)
   {
      statistic<int> pack_int;
      int i_data[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
      const int i_min = 1;

      int min_value = pack_int.GetStatEvaluations()->Min(i_data, n);

      CHECK(min_value == i_min);
   }
   TEST(StatisticVectorMinIntTest)
   {
      statistic<int> pack_int;
      int i_data[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
      const int i_min = 1;

      for (int i = 0; i < 5; ++i)
         pack_int.GetStatEvents()->StatisticEvent(i_data[i]);

      int min_value = pack_int.GetStatEvaluations()->VectorMinValue(pack_int.GetStatEvents()->GetParamsQueue());

      CHECK(min_value == i_min);
   }
   TEST(StatisticMinFloatTest)
   {
      statistic<float> pack_float;
      float f_data[n] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f, 6.6f, 7.7f, 8.8f, 9.9f, 10.10f};
      double f_min = 1.1f;

      float min_value = pack_float.GetStatEvaluations()->Min(f_data, n);

      CHECK_CLOSE(f_min, min_value, 0.01f );
   }
   TEST(StatisticVectorMinFloatTest)
   {
      statistic<float> pack_float;
      float f_data[n] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f, 6.6f, 7.7f, 8.8f, 9.9f, 10.10f};
      float f_min = 1.1f;

      for (int i = 0; i < 5; ++i)
         pack_float.GetStatEvents()->StatisticEvent(f_data[i]);

      float min_value = pack_float.GetStatEvaluations()->VectorMinValue(pack_float.GetStatEvents()->GetParamsQueue());

      CHECK_CLOSE(f_min, min_value, 0.01f );
   }

   // MAX TESTS
   TEST(StatisticMaxIntTest)
   {
      statistic<int> pack_int;
      int i_data[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
      const int i_max = 10;

      int max_value = pack_int.GetStatEvaluations()->Max(i_data, n);

      CHECK(max_value == i_max);
   }
   TEST(StatisticVectorMaxIntTest)
   {
      statistic<int> pack_int;
      int i_data[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
      const int i_max = 5;

      for (int i = 0; i < 5; ++i)
         pack_int.GetStatEvents()->StatisticEvent(i_data[i]);

      int max_value = pack_int.GetStatEvaluations()->VectorMaxValue(pack_int.GetStatEvents()->GetParamsQueue());

      CHECK(max_value == i_max);
   }
   TEST(StatisticMaxFloatTest)
   {
      statistic<float> pack_float;
      float f_data[n] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f, 6.6f, 7.7f, 8.8f, 9.9f, 10.10f};
      float f_max = 10.10f;

      float max_value = pack_float.GetStatEvaluations()->Max(f_data, n);

      CHECK_CLOSE(f_max, max_value, 0.01f );
   }
   TEST(StatisticVectorMaxFloatTest)
   {
      statistic<float> pack_float;
      float f_data[n] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f, 6.6f, 7.7f, 8.8f, 9.9f, 10.10f};
      float f_max = 5.5f;

      for (int i = 0; i < 5; ++i)
         pack_float.GetStatEvents()->StatisticEvent(f_data[i]);

      float max_value = pack_float.GetStatEvaluations()->VectorMaxValue(pack_float.GetStatEvents()->GetParamsQueue());

      CHECK(max_value == f_max);
   }

   // DISPERSION TESTS
   TEST(StatisticDispersionIntTest)
   {
      statistic<int> pack_int;
      pack_int.GetStatEvaluations()->SetMean(5);
      int i_data[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
      const int i_dispersion = 8;

      int dispersion_value = pack_int.GetStatEvaluations()->Dispersion(i_data, n);

      CHECK(dispersion_value == i_dispersion);
   }
   TEST(StatisticVectorDispersionIntTest)
   {
      statistic<int> pack_int;
      int i_data[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
      const int i_dispersion = 11;

      for (int i = 0; i < 5; ++i)
         pack_int.GetStatEvents()->StatisticEvent(i_data[i]);

      int dispersion_value = pack_int.GetStatEvaluations()->VectorDispersion(pack_int.GetStatEvents()->GetParamsQueue());

      CHECK(dispersion_value == i_dispersion);
   }
   TEST(StatisticDispersionFloatTest)
   {
      statistic<float> pack_float;
      pack_float.GetStatEvaluations()->SetMean(5.96f);
      float f_data[n] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f, 6.6f, 7.7f, 8.8f, 9.9f, 10.10f};
      float f_dispersion = 9.1644f;

      float dispersion_value = pack_float.GetStatEvaluations()->Dispersion(f_data, n);

      CHECK_CLOSE(f_dispersion, dispersion_value , 0.01f);
   }
   TEST(StatisticVectorDispersionFloatTest)
   {
      statistic<float> pack_float;
      float f_data[n] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f, 6.6f, 7.7f, 8.8f, 9.9f, 10.10f};
      float f_dispersion = 5.5f;

      for (int i = 0; i < 5; ++i)
         pack_float.GetStatEvents()->StatisticEvent(f_data[i]);

      float dispersion_value = pack_float.GetStatEvaluations()->VectorMaxValue(pack_float.GetStatEvents()->GetParamsQueue());

      CHECK(dispersion_value == f_dispersion);
   }

   // MathExpectation TESTS
   TEST(StatisticMathExpectationIntTest)
   {
      statistic<int> pack_int;
      int i_data[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
      const int i_mathExpectation = 5;	// округление int'a = 5.5

      int mathExpectation = pack_int.GetStatEvaluations()->MeanValue(i_data, n);

      CHECK(mathExpectation == i_mathExpectation);
   }
   TEST(StatisticVectorMathExpectationIntTest)
   {
      statistic<int> pack_int;
      int i_data[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
      const int i_mathExpectation = 3;

      for (int i = 0; i < 5; ++i)
         pack_int.GetStatEvents()->StatisticEvent(i_data[i]);

      int mathExpectation_value = pack_int.GetStatEvaluations()->VectorMathExpectation(pack_int.GetStatEvents()->GetParamsQueue());

      CHECK(mathExpectation_value == i_mathExpectation);
   }
   TEST(StatisticMathExpectationFloatTest)
   {
      statistic<float> pack_float;
      float data[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	  const float f_mathExpectation = 5.5f;

      float mathExpectation = pack_float.GetStatEvaluations()->MeanValue(data, n);

      CHECK(mathExpectation == f_mathExpectation);
   }
   TEST(StatisticMathExpectationFloatTest2)
   {
      statistic<float> pack_float;
      float f_data[n] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f, 6.6f, 7.7f, 8.8f, 9.9f, 10.10f};
      float f_mathExpectation = 5.96f;

      float mathExpectation = pack_float.GetStatEvaluations()->MeanValue(f_data, n);

      CHECK_CLOSE(f_mathExpectation, mathExpectation, 0.01f);
   }
   TEST(StatisticVectorMathExpectationFloatTest)
   {
      statistic<float> pack_float;
      float f_data[n] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f, 6.6f, 7.7f, 8.8f, 9.9f, 10.10f};
      float f_mathExpectation = 3.3f;

      for (int i = 0; i < 5; ++i)
         pack_float.GetStatEvents()->StatisticEvent(f_data[i]);

      float mathExpectation_value = pack_float.GetStatEvaluations()->VectorMathExpectation(pack_float.GetStatEvents()->GetParamsQueue());

      CHECK_CLOSE(f_mathExpectation, mathExpectation_value, 0.01f);
   }

   // StdDeviation TESTS
   TEST(StatisticStdDeviationIntTest)
   {
      statistic<int> pack_int;
      pack_int.GetStatEvaluations()->SetMean(5);
      pack_int.GetStatEvaluations()->SetDispersion(8);
      int i_data[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
      const int i_stdDeviation = 3;

      double stdDeviation_value = pack_int.GetStatEvaluations()->StdDeviation(i_data, n);

      CHECK(stdDeviation_value == i_stdDeviation);
   }
   TEST(StatisticVectorStdDeviationIntTest)
   {
      statistic<int> pack_int;
      int i_data[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
      const int i_stdDeviation = 3;

      for (int i = 0; i < 5; ++i)
         pack_int.GetStatEvents()->StatisticEvent(i_data[i]);

      double stdDeviation_value = pack_int.GetStatEvaluations()->VectorMathExpectation(pack_int.GetStatEvents()->GetParamsQueue());

      CHECK(stdDeviation_value == i_stdDeviation);
   }
   TEST(StatisticStdDeviationFloatTest)
   {
      statistic<float> pack_float;
      pack_float.GetStatEvaluations()->SetMean(5.96f);
      pack_float.GetStatEvaluations()->SetDispersion(9.1644f);
      float f_data[n] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f, 6.6f, 7.7f, 8.8f, 9.9f, 10.10f};
      float f_stdDeviation = 3.17503f;

      double stdDeviation_value = pack_float.GetStatEvaluations()->StdDeviation(f_data, n);

      CHECK_CLOSE(f_stdDeviation, stdDeviation_value, 0.01f);
   }
   TEST(StatisticVectorStdDeviationFloatTest)
   {
      statistic<float> pack_float;
      float f_data[n] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f, 6.6f, 7.7f, 8.8f, 9.9f, 10.10f};
      float f_stdDeviation = 3.64829f;

      for (int i = 0; i < 5; ++i)
         pack_float.GetStatEvents()->StatisticEvent(f_data[i]);

      double stdDeviation_value = pack_float.GetStatEvaluations()->VectorStdDeviation(pack_float.GetStatEvents()->GetParamsQueue());

      CHECK_CLOSE(f_stdDeviation, stdDeviation_value, 0.01f);
   }
} // Statistics
