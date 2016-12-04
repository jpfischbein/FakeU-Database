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



/**
* \file 	EXIDecoder.h
* \brief 	EXI Decoder
*
*/

#ifndef EXI_EXIforJSON_DECODER_H
#define EXI_EXIforJSON_DECODER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "EXITypes.h"

/**
 * \brief 		Initialize EXI decoder
 *
 *         		Resets & initializes the EXI decoder.
 *
 * \param       stream   		Input Stream
 * \param       state   		Codec state
 * \param       runtimeTable   	Runtime name-tables
 * \param       stringTable   	String table
 * \return                  	Error-Code <> 0
 *
 */
int exiEXIforJSONInitDecoder(bitstream_t* stream, exi_state_t* state,
		exi_name_table_runtime_t* runtimeTable, exi_value_table_t* stringTable);


/**
 * \brief 		Reports last decoded qualified name
 *
 *         		Note: Qualified name only available for previously unknown qname. Otherwise make use of name table entries.
 *
 * \param       qname   		Qualified name
 * \return                  	Error-Code <> 0
 *
 */
int exiEXIforJSONGetLastQName(exi_qname_t** qname);


/**
 * \brief 		Decodes next event
 *
 * 				Inspects EXI stream and decodes next EXI event.
 *
 * \param       stream   		Input Stream
 * \param       state   		Codec state
 * \param       nextEvent   	Next event
 * \return                  	Error-Code <> 0
 *
 */
int exiEXIforJSONDecodeNextEvent(bitstream_t* stream,
		exi_state_t* state, exi_event_t* nextEvent);


/**
 * \brief 		Decodes StartDocument (SD) event
 *
 * \param       stream   		Input Stream
 * \param       state   		Codec state
 * \return                  	Error-Code <> 0
 *
 */
int exiEXIforJSONDecodeStartDocument(bitstream_t* stream,
		exi_state_t* state);

/**
 * \brief 		Decodes EndDocument (ED) event
 *
 * \param       stream   		Input Stream
 * \param       state   		Codec state
 * \return                  	Error-Code <> 0
 *
 */
int exiEXIforJSONDecodeEndDocument(bitstream_t* stream,
		exi_state_t* state);

/**
 * \brief 		Decodes StartElement (SE) event
 *
 * 				Note: The first time a qnameID is larger than schema-informed NUMBER_OF_QNAMES it is possible to retrieve the qname by calling GetLastQName(...).
 * 				It is up to the caller to track qnames.
 *
 * \param       stream   		Input Stream
 * \param       state   		Codec state
 * \param       qnameID   		Qualified Name ID
 * \return                  	Error-Code <> 0
 *
 */
int
exiEXIforJSONDecodeStartElement(bitstream_t* stream,
		exi_state_t* state, uint16_t* qnameID);


/**
 * \brief 		Decodes EndElement (EE) event
 *
 * \param       stream   		Input Stream
 * \param       state   		Codec state
 * \param       qnameID   		Qualified Name ID
 * \return                  	Error-Code <> 0
 *
 */
int exiEXIforJSONDecodeEndElement(bitstream_t* stream,
		exi_state_t* state, uint16_t* qnameID);


/**
 * \brief 		Decodes Characters (CH) event.
 *
 * 				Reports characters value.
 *
 * \param       stream   		Input Stream
 * \param       state   		Codec state
 * \param       val		   		Characters value
 * \return                  	Error-Code <> 0
 *
 */
int exiEXIforJSONDecodeCharacters(bitstream_t* stream,
		exi_state_t* state, exi_value_t* val);


/**
 * \brief 		Decodes Attribute (AT) event.
 *
 * 				Reports attribute qname and value.
 *
 * \param       stream   		Input Stream
 * \param       state   		Codec state
 * \param       qnameID   		Qualified Name ID
 * \param       val		   		Characters value
 * \return                  	Error-Code <> 0
 *
 */
int exiEXIforJSONDecodeAttribute(bitstream_t* stream,
		exi_state_t* state, uint16_t* qnameID, exi_value_t* val);


/**
 * \brief 		Decodes attribute xsi:nil
 *
 * 				Reports value.
 *
 * \param       stream   		Input Stream
 * \param       state   		Codec state
 * \param       val		   		Characters value
 * \return                  	Error-Code <> 0
 *
 */
int exiEXIforJSONDecodeAttributeXsiNil(bitstream_t* stream,
		exi_state_t* state, exi_value_t* val);


/**
 * \brief 		Decodes attribute xsi:type
 *
 * 				Reports value.
 *
 * \param       stream   		Input Stream
 * \param       state   		Codec state
 * \param       val		   		Characters value
 * \return                  	Error-Code <> 0
 *
 */
int exiEXIforJSONDecodeAttributeXsiType(bitstream_t* stream,
		exi_state_t* state, exi_value_t* val);


/**
 * \brief 		Decodes attribute/characters list value
 *
 * 				List values are special and are processed one by one.
 *
 * \param       stream   		Input Stream
 * \param       state   		Codec state
 * \param       qnameID   		Qualified Name ID
 * \param       val		   		List value
 * \param       lt		   		List type
 * \return                  	Error-Code <> 0
 *
 */
int exiEXIforJSONDecodeListValue(bitstream_t* stream, exi_state_t* state, uint16_t qnameID,
		exi_value_t* val, exi_list_t lt);

#ifdef __cplusplus
}
#endif

#endif