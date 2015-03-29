#pragma once

#include"../../common/CommonDef.hpp"
#include"../../common/CommonTemplates.hpp"

namespace aMazing
{
	namespace reserve
	{
		//This struct is reserved for disabling non numeric type as the template argument.
		template<typename T, typename Enable = void>
		struct baseMatrix_t{};

		template<typename T>
		struct baseMatrix_t<T, typename std::enable_if<aIsNumeric<T>::value >::value >{};
	}

	template<typename type>
	struct aMatrix2x2_t : public reserve::baseMatrix_t<type>
	{
		type m11, m12, m21, m22;
		//To transpose the matrix
		void transpose() aNOEXCEPT
		{
			aSwap(m12, m21);
		}

		//To make the matrix zero.
		void beZero() aNOEXCEPT
		{
			m11 = 0; m12 = 0;
			m21 = 0; m22 = 0;
		}
		//To make the matrix identity matrix.
		void beIdentity() aNOEXCEPT
		{
			m11 = 1; m12 = 0;
			m21 = 0; m22 = 1;
		}
		//return whether the matrix is identity matrix.
		const bool isIdentity() const aNOEXCEPT
		{
			if (m11 == 1 && m22 == m11)
			{
				if (m12 && m21)
				{
					return false;
				}
				else
				{
					return true;
				}
			}
			return false;
		}
		//return whether the matrix is zero.
		const bool isZero() const aNOEXCEPT
		{
			if (m11 && m12 &&
			m21 && m22)
				return false;
			return true;
		}
		//return whether two matrices are same.
		bool operator == (const aMatrix4x4_t& other) const aNOEXCEPT
		{
			return m11 == other.m11 && m12 == other.m12 &&
			m21 == other.m21 && m22 == other.m22;
		}
		aMatrix2x2_t<type> operator + (const aMatrix2x2<type>& other)const aNOEXCEPT
		{
			aMatrix2x2_t<type> result;
			reuslt.m11 = m11 + other.m11;
			result.m12 = m12 + other.m12;

			result.m21 = m21 + other.m21;
			result.m22 = m22 + other.m22;
			return result;
		}
		aMatrix2x2_t<type> operator - (const aMatrix2x2<type>& other)const aNOEXCEPT
		{
			aMatrix2x2_t<type> result;
			reuslt.m11 = m11 - other.m11;
			result.m12 = m12 - other.m12;

			result.m21 = m21 - other.m21;
			result.m22 = m22 - other.m22;
			return result;
		}
	};

	template<typename type>
	struct aMatrix3x3_t : public reserve::baseMatrix_t<type>
	{
		type m11, m12, m13,
		m21, m22, m23,
		m31, m32, m33;
		//To transpose the matrix
		void transpose() aNOEXCEPT
		{
			aSwap(m12, m21);
			aSwap(m13, m31);
			aSwap(m23, m32);
		}

		//To make the matrix zero.
		void beZero() aNOEXCEPT
		{
			m11 = 0; m12 = 0; m13 = 0;
			m21 = 0; m22 = 0; m23 = 0;
			m31 = 0; m32 = 0; m33 = 0;
		}
		//To make the matrix identity matrix.
		void beIdentity() aNOEXCEPT
		{
			m11 = 1; m12 = 0; m13 = 0;
			m21 = 0; m22 = 1; m23 = 0;
			m31 = 0; m32 = 0; m33 = 1;
		}
		//return whether the matrix is identity matrix.
		const bool isIdentity() const aNOEXCEPT
		{
			if (m11 == 1 && m22 == m11 && m33 == m22)
			{
				if (m12 && m13 &&
					m21 && m23 &&
					m31 && m32)
				{
					return false;
				}
				else
				{
					return true;
				}
			}
			return false;
		}
		//return whether the matrix is zero.
		const bool isZero() const aNOEXCEPT
		{
			if (m11 && m12 && m13 &&
			m21 && m22 && m23 &&
			m31 && m32 && m33)
				return false;
			return true;
		}
		//return whether two matrices are same.
		bool operator == (const aMatrix4x4_t& other) const aNOEXCEPT
		{
			return m11 == other.m11 && m12 == other.m12 && m13 == other.m13 &&
			m21 == other.m21 && m22 == other.m22 && m23 == other.m23 &&
			m31 == other.m31 && m32 == other.m32 && m33 == other.m33;
		}
		aMatrix3x3_t<type> operator + (const aMatrix3x3_t<type>& other)const aNOEXCEPT
		{
			aMatrix3x3_t<type> result;
			reuslt.m11 = m11 + other.m11;
			result.m12 = m12 + other.m12;
			result.m13 = m13 + other.m13;

			result.m21 = m21 + other.m21;
			result.m22 = m22 + other.m22;
			result.m23 = m23 + other.m23;

			result.m31 = m31 + other.m31;
			result.m32 = m32 + other.m32;
			result.m33 = m33 + other.m33;
			return result;
		}
		aMatrix3x3_t<type> operator - (const aMatrix3x3_t<type>& other)const aNOEXCEPT
		{
			aMatrix3x3_t<type> result;
			reuslt.m11 = m11 - other.m11;
			result.m12 = m12 - other.m12;
			result.m13 = m13 - other.m13;

			result.m21 = m21 - other.m21;
			result.m22 = m22 - other.m22;
			result.m23 = m23 - other.m23;

			result.m31 = m31 - other.m31;
			result.m32 = m32 - other.m32;
			result.m33 = m33 - other.m33;
			return result;
		}
	};

	template<typename type>
	struct aMatrix4x4_t : public reserve::baseMatrix_t<type>
	{
		type m11, m12, m13, m14,
		m21, m22, m23, m24,
		m31, m32, m33, m34,
		m41, m42, m43, m44;
		//To transpose the matrix
		void transpose() aNOEXCEPT
		{ 
			aSwap(m12, m21);
			aSwap(m13, m31);
			aSwap(m14, m41);
			aSwap(m23, m32);
			aSwap(m24, m42);
			aSwap(m34, m43);
		}
		//To make the matrix zero.
		void beZero() aNOEXCEPT
		{
			m11 = 0; m12 = 0; m13 = 0; m14 = 0;
			m21 = 0; m22 = 0; m23 = 0; m24 = 0;
			m31 = 0; m32 = 0; m33 = 0; m34 = 0;
			m41 = 0; m42 = 0; m43 = 0; m44 = 0;
		}
		//To make the matrix identity matrix.
		void beIdentity() aNOEXCEPT
		{
			m11 = 1; m12 = 0; m13 = 0; m14 = 0;
			m21 = 0; m22 = 1; m23 = 0; m24 = 0;
			m31 = 0; m32 = 0; m33 = 1; m34 = 0;
			m41 = 0; m42 = 0; m43 = 0; m44 = 1;
		}
		//return whether the matrix is identity matrix.
		const bool isIdentity() const aNOEXCEPT
		{
			if (m11 == 1 && m22 == m11 && m33 == m22 && m44 == m33)
			{
				if (m12 && m13 && m14 && 
					m21 && m23 && m24 && 
					m31 && m32 && m34 && 
					m41 && m42 && m43)
				{
					return false;
				}
				else
				{
					return true;
				}
			}
			return false;
		}
		//return whether the matrix is zero.
		const bool isZero() const aNOEXCEPT
		{
			if (m11 && m12 && m13 && m14 &&
			m21 && m22 && m23 && m24 &&
			m31 && m32 && m33 && m34 &&
			m41 && m42 && m43 && m44)
				return false;
			return true;
		}
		//return whether two matrices are same.
		bool operator == (const aMatrix4x4_t& other) const aNOEXCEPT
		{
			return m11 == other.m11 && m12 == other.m12 && m13 == other.m13 && m14 == other.m14 &&
			m21 == other.m21 && m22 == other.m22 && m23 == other.m23 && m24 == other.m24 &&
			m31 == other.m31 && m32 == other.m32 && m33 == other.m33 && m34 == other.m34 && 
			m41 == other.m41 && m42 == other.m42 && m43 == other.m43 && m44 == other.m44;
		}

		aMatrix3x3_t<type> operator + (const aMatrix3x3_t<type>& other)const aNOEXCEPT
		{
			aMatrix3x3_t<type> result;
			reuslt.m11 = m11 + other.m11;
			result.m12 = m12 + other.m12;
			result.m13 = m13 + other.m13;
			result.m14 = m14 + other.m14;

			result.m21 = m21 + other.m21;
			result.m22 = m22 + other.m22;
			result.m23 = m23 + other.m23;
			result.m24 = m24 + other.m24;

			result.m31 = m31 + other.m31;
			result.m32 = m32 + other.m32;
			result.m33 = m33 + other.m33;
			result.m34 = m34 + other.m34;

			result.m41 = m41 + other.m41;
			result.m42 = m42 + other.m42;
			result.m43 = m43 + other.m43;
			result.m44 = m44 + other.m44;
			return result;
		}
		aMatrix3x3_t<type> operator - (const aMatrix3x3_t<type>& other)const aNOEXCEPT
		{
			aMatrix3x3_t<type> result;
			reuslt.m11 = m11 - other.m11;
			result.m12 = m12 - other.m12;
			result.m13 = m13 - other.m13;
			result.m21 = m21 - other.m21;
			result.m22 = m22 - other.m22;
			result.m24 = m23 - other.m23;
			result.m31 = m31 - other.m31;
			result.m32 = m32 - other.m32;
			result.m33 = m33 - other.m33;
			return result;
		}
	};

	typedef aMatrix4x4_t<int> aIntMatrix4x4;
	typedef aMatrix4x4_t<float> aFloatMatrix4x4;
	typedef aMatrix4x4_t<double> aDoubleMatrix4x4;
}
