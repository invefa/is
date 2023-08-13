#pragma once

//seem unused ~
#define ISL_BEGIN namespace is {
#define ISL_END	  }

namespace is {
	//base class to remove_reference.
	template<typename T>
	class remove_reference {
	public: typedef T type;
	};

	//This template class can remove reference modifiers of the specified type,
	//and the result type is defined as remove_reference<...>::type.
	template<typename T>
	class remove_reference<T&> {
	public: typedef T type;
	};
}

//Convert the pointer conversion to the down level base type.
#define _ISL_CAST_PTR_TO_BASE_TYPE(_ptr)	is::remove_reference<decltype(*(_ptr))>::type

//Remove the default move and copy functions that C++ considers self righteous.
#define _ISL_DELETE_DEFAULT_MOVE_AND_COPY_FN(_type)	\
_type(const _type&)				= delete;		\
_type(_type&&)					= delete;		\
_type& operator=(const _type&)	= delete;		\
_type& operator=(_type&&)		= delete;

//Print a line, overload of printf(...).
//arg fmt must be literal string.
#define println(_fmt, ...) printf(_fmt"\n",##__VA_ARGS__)

//Disable warnings for unused macro parameters.
#pragma warning(disable: 4003)

//Call the specified macro overload based on the number of variable parameters,
//it supports at least one parameter and up to nine parameters.

#define __ISL_MACRO_CONCAT_IMPL(_x, _y)	_x##_y
#define __ISL_MACRO_CONCAT_WRAP(_x, _y)	__ISL_MACRO_CONCAT_IMPL	(_x, _y)
#define __ISL_MACRO_CONCAT(_x, _y)		__ISL_MACRO_CONCAT_WRAP	(_x, _y)

#define __ISL_MACRO_GET_TENTH_ARG_IMPL(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, ...) _10
#define __ISL_MACRO_GET_TENTH_ARG_UNPACK(_args)	__ISL_MACRO_GET_TENTH_ARG_IMPL _args
#define __ISL_MACRO_GET_TENTH_ARG(...)			__ISL_MACRO_GET_TENTH_ARG_UNPACK((__VA_ARGS__))
#define __ISL_MACRO_GET_VARG_COUNT(...)			__ISL_MACRO_GET_TENTH_ARG(__VA_ARGS__,9,8,7,6,5,4,3,2,1,0)

#define __ISL_MACRO_INVOKE_UNPACK(_fn, _args_pack)	_fn _args_pack
#define __ISL_MACRO_INVOKE(_fn, ...) __ISL_MACRO_INVOKE_UNPACK(_fn,(__VA_ARGS__))

#define  _ISL_MACRO_FORWARD_CALL(_fn,...)	__ISL_MACRO_INVOKE(\
						__ISL_MACRO_CONCAT(__ISL_MACRO_CONCAT(_fn,_),__ISL_MACRO_GET_VARG_COUNT(__VA_ARGS__)),__VA_ARGS__)

#define  _ISL_MACRO_OVERLOAD(_fn,...) _ISL_MACRO_FORWARD_CALL(_fn,__VA_ARGS__)

