/*
 * test_assertion.c
 *
 *  Created on: Jan 13, 2013
 *      Author: hathach
 */

/*
 * Software License Agreement (BSD License)
 * Copyright (c) 2012, hathach (tinyusb.net)
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
 * SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 *
 * This file is part of the tiny usb stack.
 */

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include "unity.h"
#include "common/assertion.h"

void setUp(void)
{
}

void tearDown(void)
{
}

//--------------------------------------------------------------------+
// Logical
//--------------------------------------------------------------------+
void test_assert_logical_true(void)
{
  ASSERT      (true  , (void)0 );
  ASSERT_TRUE (true  , (void)0 );

  ASSERT_TRUE (false , (void)0 );
  TEST_FAIL();
}

void test_assert_logical_false(void)
{
  ASSERT_FALSE(false , (void)0 );
  ASSERT_FALSE(true  , (void)0 );

  TEST_FAIL();
}

//--------------------------------------------------------------------+
// Integer
//--------------------------------------------------------------------+
void test_assert_int_eqal(void)
{
  ASSERT_INT       (1, 1, (void) 0);
  ASSERT_INT_EQUAL (1, 1, (void) 0);

  uint32_t x = 0;
  uint32_t y = 0;
  ASSERT_INT (x++, y++, (void) 0); // test side effect
  TEST_ASSERT_EQUAL(1, x);
  TEST_ASSERT_EQUAL(1, y);

  ASSERT_INT(0, 1, (void) 0);

  TEST_FAIL();
}