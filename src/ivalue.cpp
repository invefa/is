#include "ivalue.h"
#include "iassert.h"

ISL_BEGIN


//bool cmp::value::as_i64_fn(Value a, Value b) {
//	return a.i64 == b.i64;
//}
//
//bool cmp::value::as_str_fn(Value a, Value b) {
//	isl_assert(a.sp != nullptr && b.sp != nullptr);
//	return a.sp->operator==(*b.sp);
//}

//unsigned long be typedef as is::ui64, and compiler not detected it.
#pragma warning(disable: 6328)
#pragma warning(disable: 4477)

//comp implement
__ISL_GEN_VALUE_CMP_CLASS_IMPL(i8);
__ISL_GEN_VALUE_CMP_CLASS_IMPL(i16);
__ISL_GEN_VALUE_CMP_CLASS_IMPL(i32);
__ISL_GEN_VALUE_CMP_CLASS_IMPL(i64);

__ISL_GEN_VALUE_CMP_CLASS_IMPL(ui8);
__ISL_GEN_VALUE_CMP_CLASS_IMPL(ui16);
__ISL_GEN_VALUE_CMP_CLASS_IMPL(ui32);
__ISL_GEN_VALUE_CMP_CLASS_IMPL(ui64);

__ISL_GEN_VALUE_CMP_CLASS_IMPL(ptr);

bool cmp::value::as_str::operator()(Value a, Value b) {
	isl_assert(a.sp != nullptr && b.sp != nullptr);
	return a.sp->operator==(*b.sp);
}

//dump implement
__ISL_GEN_VALUE_DMP_AS_INTEGER_CLASS_IMPL(i8, "%d");
__ISL_GEN_VALUE_DMP_AS_INTEGER_CLASS_IMPL(i16, "%d");
__ISL_GEN_VALUE_DMP_AS_INTEGER_CLASS_IMPL(i32, "%d");
__ISL_GEN_VALUE_DMP_AS_INTEGER_CLASS_IMPL(i64, "%ld");

__ISL_GEN_VALUE_DMP_AS_INTEGER_CLASS_IMPL(ui8, "%u");
__ISL_GEN_VALUE_DMP_AS_INTEGER_CLASS_IMPL(ui16, "%u");
__ISL_GEN_VALUE_DMP_AS_INTEGER_CLASS_IMPL(ui32, "%u");
__ISL_GEN_VALUE_DMP_AS_INTEGER_CLASS_IMPL(ui64, "%lu");

__ISL_GEN_VALUE_DMP_AS_INTEGER_CLASS_IMPL(ptr, "%p");

__ISL_GEN_VALUE_DMP_AS_TYPE_CLASS_IMPL(str, { return String(*val.sp); });


Value::Value()						: i64 (0)						{}
//Value::Value(is::cptr _ptr)		: ptr (_ptr)					{}
//Value::Value(is::i64 _int)		: i64 (_int)					{}
//Value::Value(is::ui64 _uint)		: ui64(_uint)					{}
//Value::Value(is::f64 _real)		: f64 (_real)					{}
//Value::Value(String& _str)		: sp  (new String(_str))		{}
//Value::Value(RefString& _refstr)	: rsp (new RefString(_refstr))	{}

bool Value::is_equal(is::ui64 another) {
	return ui64 == another;
}

bool Value::is_equal(is::StringMeta another) {
	isl_assert(sp != nullptr);
	return sp->operator==(another);
}

//bool Value::is_equal(is::Value another, bool (*cmp_fn)(Value, Value)) {
//	isl_assert(cmp_fn != nullptr);
//	return cmp_fn(*this, another);
//}

bool Value::operator==(Value another) {
	return is_equal(another);
}



ISL_END