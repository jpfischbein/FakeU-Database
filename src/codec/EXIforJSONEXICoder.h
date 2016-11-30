/*
 * Copyright (C) 2007-2016 Siemens AG
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
 * associated documentation files (the "Software"), to deal in the Software without restriction, 
 * including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, 
 * and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do
 * so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all copies or 
 * substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, 
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
 * PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR 
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN
 * AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION 
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

/*******************************************************************
 *
 * @author Daniel.Peintner.EXT@siemens.com
 * @version 2016-02-03 
 * @contact Joerg.Heuer@siemens.com
 *
 * <p>Code generated by EXIdizer</p>
 * <p>Schema: schema-for-json.xsd</p>
 *
 *
 ********************************************************************/



#ifndef EXI_EXIforJSON_CODER_H
#define EXI_EXIforJSON_CODER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "EXITypes.h"

#define DOCUMENT 0
#define DOC_CONTENT 1
#define DOC_END 43



/* ==================================== */
/* Name Table Population */
extern exi_name_table_prepopulated_t exiEXIforJSONNameTablePrepopulated;



/* increments global and local string count */
/* in case of dynamic memory string is collected */
/*
int exi_EXIforJSON_AddStringValue(exi_state_t* state, exi_string_ucs_t* sv, uint16_t qnameID);
*/

int exi_EXIforJSON_PushStack(exi_state_t* state, int16_t newState, uint16_t qnameID);

int exi_EXIforJSON_PopStack(exi_state_t* state);

int exi_EXIforJSON_HandleXsiNilTrue(exi_state_t* state);

int exi_EXIforJSON_HandleXsiType(exi_state_t* state, exi_eqname_t* xsiType);

int exi_EXIforJSON_RetrieveAndPushGlobalGrammar(exi_state_t* state, uint16_t qnameID);

int exi_EXIforJSON_LearnAttribute(exi_state_t* state, uint16_t uriID, uint16_t localID);

int exi_EXIforJSON_LearnEndElement(exi_state_t* state);

int exi_EXIforJSON_IsStartContent(int16_t ruleID);

int exi_EXIforJSON_MoveToElementContentRule(exi_state_t* state);

#ifdef __cplusplus
}
#endif

#endif
