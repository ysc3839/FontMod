// Tencent is pleased to support the open source community by making RapidJSON available.
// 
// Copyright (C) 2015 THL A29 Limited, a Tencent company, and Milo Yip. All rights reserved.
//
// Licensed under the MIT License (the "License"); you may not use this file except
// in compliance with the License. You may obtain a copy of the License at
//
// http://opensource.org/licenses/MIT
//
// Unless required by applicable law or agreed to in writing, software distributed 
// under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR 
// CONDITIONS OF ANY KIND, either express or implied. See the License for the 
// specific language governing permissions and limitations under the License.

#ifndef RAPIDJSON_ERROR_ZH_CN_H_
#define RAPIDJSON_ERROR_ZH_CN_H_

#include "rapidjson/error/error.h"

#ifdef __clang__
RAPIDJSON_DIAG_PUSH
RAPIDJSON_DIAG_OFF(switch-enum)
RAPIDJSON_DIAG_OFF(covered-switch-default)
#endif

RAPIDJSON_NAMESPACE_BEGIN

//! Maps error code of parsing into error message.
/*!
    \ingroup RAPIDJSON_ERRORS
    \param parseErrorCode Error code obtained in parsing.
    \return the error message.
    \note User can make a copy of this function for localization.
        Using switch-case is safer for future modification of error codes.
*/
inline const RAPIDJSON_ERROR_CHARTYPE* GetParseError_Zh_Cn(ParseErrorCode parseErrorCode) {
    switch (parseErrorCode) {
        case kParseErrorNone:                           return RAPIDJSON_ERROR_STRING("无错误");

        case kParseErrorDocumentEmpty:                  return RAPIDJSON_ERROR_STRING("文档是空的");
        case kParseErrorDocumentRootNotSingular:        return RAPIDJSON_ERROR_STRING("文档的根后面不能有其它值");
    
        case kParseErrorValueInvalid:                   return RAPIDJSON_ERROR_STRING("不合法的值");
    
        case kParseErrorObjectMissName:                 return RAPIDJSON_ERROR_STRING("Object 成员缺少名字");
        case kParseErrorObjectMissColon:                return RAPIDJSON_ERROR_STRING("Object 成员名字后缺少冒号");
        case kParseErrorObjectMissCommaOrCurlyBracket:  return RAPIDJSON_ERROR_STRING("Object 成员后缺少逗号或 '}'");
    
        case kParseErrorArrayMissCommaOrSquareBracket:  return RAPIDJSON_ERROR_STRING("Array 元素后缺少逗号或 ']'");

        case kParseErrorStringUnicodeEscapeInvalidHex:  return RAPIDJSON_ERROR_STRING("String 中的 \\u 转义符后含非十六进制数字");
        case kParseErrorStringUnicodeSurrogateInvalid:  return RAPIDJSON_ERROR_STRING("String 中的代理对 (surrogate pair) 不合法");
        case kParseErrorStringEscapeInvalid:            return RAPIDJSON_ERROR_STRING("String 含非法转义字符");
        case kParseErrorStringMissQuotationMark:        return RAPIDJSON_ERROR_STRING("String 缺少关闭引号");
        case kParseErrorStringInvalidEncoding:          return RAPIDJSON_ERROR_STRING("String 含非法编码");

        case kParseErrorNumberTooBig:                   return RAPIDJSON_ERROR_STRING("Number 的值太大，不能存储于 double");
        case kParseErrorNumberMissFraction:             return RAPIDJSON_ERROR_STRING("Number 缺少了小数部分");
        case kParseErrorNumberMissExponent:             return RAPIDJSON_ERROR_STRING("Number 缺少了指数");

        case kParseErrorTermination:                    return RAPIDJSON_ERROR_STRING("因为 Handler 错误停止解析");
        case kParseErrorUnspecificSyntaxError:          return RAPIDJSON_ERROR_STRING("未知的语法错误");

        default:                                        return RAPIDJSON_ERROR_STRING("未知错误");
    }
}

RAPIDJSON_NAMESPACE_END

#ifdef __clang__
RAPIDJSON_DIAG_POP
#endif

#endif // RAPIDJSON_ERROR_EN_H_
