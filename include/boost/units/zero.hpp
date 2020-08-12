// Boost.Units - A C++ library for zero-overhead dimensional analysis and 
// unit/quantity manipulation and conversion
//
// Copyright (C) 2020 code::lab Mateusz Janiak
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_UNITS_ZERO_HPP
#define BOOST_UNITS_ZERO_HPP

///
/// \file
/// \brief Concept of zero type for easier quantities comparison against zero.
/// \details zero type is designed to simplify quantities values comparison against zero value
///

#ifndef BOOST_UNITS_DOXYGEN

namespace boost {

namespace units {

	namespace impl
	{
		//! Structure for simpler comparison and initialization against zero for any quantity
		struct zero
		{
			//! \tparam Value unit
			//! \tparam Y Value storage type
			template<class Unit, class Y>
			//! Conversion operator to any quantity with value 0
			inline operator quantity<Unit, Y>() const { return quantity<Unit, Y>::from_value(Y()); }

			//! Comparison operators
			inline bool operator==(const zero & other) const { return true; }
			inline bool operator!=(const zero & other) const { return false; }

			inline bool operator<(const zero & other) const { return false; }
			inline bool operator<=(const zero & other) const { return true; }
			inline bool operator>(const zero & other) const { return false; }
			inline bool operator>=(const zero & other) const { return true; }
		};

		//! Dedicated overloaded operators for quantities and zero type quantity		

		/// runtime operator==
		template<class Unit, class Y>
		inline bool	operator==(const quantity<Unit, Y>& lhs, const zero& rhs)
		{
			return lhs.value() == Y();
		}

		template<class Unit, class Y>
		inline bool	operator==(const zero& lhs, const quantity<Unit, Y>& rhs)
		{
			return rhs.value() == Y();
		}

		/// runtime operator!=
		template<class Unit, class Y>
		inline bool	operator!=(const quantity<Unit, Y>& lhs, const zero& rhs)
		{
			return lhs.value() != Y();
		}

		template<class Unit, class Y>
		inline bool	operator!=(const zero& lhs, const quantity<Unit, Y>& rhs)
		{
			return rhs.value() != Y();
		}

		/// runtime operator<
		template<class Unit, class Y>
		inline bool	operator<(const zero& lhs, const quantity<Unit, Y>& rhs)
		{
			return Y() < rhs.value();
		}

		template<class Unit, class Y>
		inline bool	operator<(const quantity<Unit, Y>& lhs, const zero& rhs)
		{
			return lhs.value() < Y();
		}

		/// runtime operator<=
		template<class Unit, class Y>
		inline bool	operator<=(const zero& lhs, const quantity<Unit, Y>& rhs)
		{
			return Y() <= rhs.value();
		}

		template<class Unit, class Y>
		inline bool	operator<=(const quantity<Unit, Y>& lhs, const zero& rhs)
		{
			return lhs.value() <= Y();
		}

		/// runtime operator>
		template<class Unit, class Y>
		inline bool	operator>(const zero& lhs, const quantity<Unit, Y>& rhs)
		{
			return Y() > rhs.value();
		}

		template<class Unit, class Y>
		inline bool	operator>(const quantity<Unit, Y>& lhs, const zero& rhs)
		{
			return lhs.value() > Y();
		}

		/// runtime operator>=
		template<class Unit, class Y>
		inline bool	operator>=(const zero& lhs, const quantity<Unit, Y>& rhs)
		{
			return Y() >= rhs.value();
		}

		template<class Unit, class Y>
		inline bool	operator>=(const quantity<Unit, Y>& lhs, const zero& rhs)
		{
			return lhs.value() >= Y();
		}
	} // namespace impl

	//static object	
	static const impl::zero zero = impl::zero();

} // namespace units

} // namespace boost

#endif

#endif // BOOST_UNITS_ZERO_HPP
