﻿/**
 * File:   wstr.h
 * Author: AWTK Develop Team
 * Brief:  width char
 *
 * Copyright (c) 2018 - 2018  Guangzhou ZHIYUAN Electronics Co.,Ltd.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * License file for more details.
 *
 */

/**
 * History:
 * ================================================================
 * 2018-01-28 Li XianJing <xianjimli@hotmail.com> adapt from uclib
 *
 */

#ifndef WSTR_H
#define WSTR_H

#include "base/value.h"
#include "base/types_def.h"

BEGIN_C_DECLS

/**
 * @class wstr_t
 * 可变长度的宽字符字符串。
 */
typedef struct _wstr_t {
  /**
   * @property {uint16_t} size
   * @readonly
   * 长度。
   */
  uint16_t size;
  /**
   * @property {uint16_t} capacity
   * @readonly
   * 容量。
   */
  uint16_t capacity;
  /**
   * @property {wchar_t*} str
   * @readonly
   * 字符串。
   */
  wchar_t* str;
} wstr_t;

/**
 * @method wstr_init
 * 初始化字符串对象。
 * @constructor
 * @param {wstr_t*} str str对象。
 * @param {uint16_t} capacity 初始容量。
 *
 * @return {wstr_t*} str对象本身。
 */
wstr_t* wstr_init(wstr_t* str, uint16_t capacity);

/**
 * @method wstr_set
 * 设置字符串。
 * @param {wstr_t*} str str对象。
 * @param {wchar_t*} text 要设置的字符串。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t wstr_set(wstr_t* str, const wchar_t* text);

/**
 * @method wstr_set_utf8
 * 设置UTF8字符串。
 * @param {wstr_t*} str str对象。
 * @param {char*} text 要设置的字符串。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t wstr_set_utf8(wstr_t* str, const char* text);

/**
 * @method wstr_get_utf8
 * 获取UTF8字符串。
 * @param {wstr_t*} str str对象。
 * @param {char*} text 返回的字符串。
 * @param {uint16_t} size text最大长度。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t wstr_get_utf8(wstr_t* str, char* text, uint16_t size);

/**
 * @method wstr_remove
 * 删除指定范围的字符。
 * @param {wstr_t*} str str对象。
 * @param {uint16_t} offset 指定的位置。
 * @param {uint16_t} nr 要删除的字符数。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t wstr_remove(wstr_t* str, uint16_t offset, uint16_t nr);

/**
 * @method wstr_insert
 * 在指定位置插入字符串。
 * @param {wstr_t*} str str对象。
 * @param {uint16_t} offset 指定的位置。
 * @param {wchar_t*} text 待插入的文本。
 * @param {uint16_t} nr 要插入的字符数。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t wstr_insert(wstr_t* str, uint16_t offset, const wchar_t* text, uint16_t nr);

/**
 * @method wstr_push
 * 追加一个字符。
 * @param {wstr_t*} str str对象。
 * @param {wchar_t} c 字符。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t wstr_push(wstr_t* str, const wchar_t c);

/**
 * @method wstr_pop
 * 删除尾部字符。
 * @param {wstr_t*} str str对象。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t wstr_pop(wstr_t* str);

/**
 * @method wstr_equal
 * 判断两个字符是否相同。
 * @param {wstr_t*} str str对象。
 * @param {wstr_t*} other str对象。
 *
 * @return {bool_t} 返回TRUE表示相同，否则表示不同。
 */
bool_t wstr_equal(wstr_t* str, wstr_t* other);

/**
 * @method wstr_from_int
 * 用整数初始化字符串。
 * @param {wstr_t*} str str对象。
 * @param {int32_t} v 整数。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t wstr_from_int(wstr_t* str, int32_t v);

/**
 * @method wstr_from_float
 * 用浮点数初始化字符串。
 * @param {wstr_t*} str str对象。
 * @param {double} v 浮点数。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t wstr_from_float(wstr_t* str, double v);

/**
 * @method wstr_from_value
 * 用value初始化字符串。
 * @param {wstr_t*} str str对象。
 * @param {value_t} v value。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t wstr_from_value(wstr_t* str, const value_t* v);

/**
 * @method wstr_to_int
 * 将字符串转成整数。
 * @param {wstr_t*} str str对象。
 * @param {int32_t*} v 用于返回整数。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t wstr_to_int(wstr_t* str, int32_t* v);

/**
 * @method wstr_to_float
 * 将字符串转成浮点数。
 * @param {wstr_t*} str str对象。
 * @param {double*} v 用于返回浮点数。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t wstr_to_float(wstr_t* str, double* v);

/**
 * @method wstr_add_float
 * 将字符串转成浮点数，加上delta，再转换回来。
 * @param {wstr_t*} str str对象。
 * @param {double} delta 要加上的值。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t wstr_add_float(wstr_t* str, double delta);

/**
 * @method wstr_trim_float_zero
 * 去掉浮点数小数点尾部的零。
 * @param {wstr_t*} str str对象。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t wstr_trim_float_zero(wstr_t* str);

/**
 * @method wstr_reset
 * 重置字符串为空。
 * @param {wstr_t*} str str对象。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t wstr_reset(wstr_t* str);

const wchar_t* wcs_chr(const wchar_t* s, wchar_t c);
wchar_t* wcs_cpy(wchar_t* s1, const wchar_t* s2);
int wcs_cmp(wchar_t* s1, const wchar_t* s2);
size_t wcs_len(const wchar_t* s);
wchar_t* wcs_dup(const wchar_t* s);

END_C_DECLS

#endif /*WSTR_H*/
