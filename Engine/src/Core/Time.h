#pragma once

#include <chrono>

// Just here to make our code look cleaner.

namespace FC
{
	typedef std::chrono::steady_clock::time_point TimePoint;

	class Time
	{
	private:
		TimePoint m_Time;

	public:
		Time() {}
		Time(TimePoint t)
			: m_Time(t) {}

		static inline TimePoint GetTime()
		{
			return std::chrono::high_resolution_clock::now();
		}

		const TimePoint& GetTimePoint() const { return m_Time; }

		double operator-(const Time& t)
		{
			return std::chrono::duration<double>(m_Time - t.GetTimePoint()).count();
		}

	};
}