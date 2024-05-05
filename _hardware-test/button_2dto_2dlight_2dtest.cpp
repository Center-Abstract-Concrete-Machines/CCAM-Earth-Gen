#include "button_2dto_2dlight_2dtest.h"

namespace button_2dto_2dlight_2dtest {

/****************************************************************************************
Copyright (c) 2023 Cycling '74

The code that Max generates automatically and that end users are capable of
exporting and using, and any associated documentation files (the “Software”)
is a work of authorship for which Cycling '74 is the author and owner for
copyright purposes.

This Software is dual-licensed either under the terms of the Cycling '74
License for Max-Generated Code for Export, or alternatively under the terms
of the General Public License (GPL) Version 3. You may use the Software
according to either of these licenses as it is most appropriate for your
project on a case-by-case basis (proprietary or not).

A) Cycling '74 License for Max-Generated Code for Export

A license is hereby granted, free of charge, to any person obtaining a copy
of the Software (“Licensee”) to use, copy, modify, merge, publish, and
distribute copies of the Software, and to permit persons to whom the Software
is furnished to do so, subject to the following conditions:

The Software is licensed to Licensee for all uses that do not include the sale,
sublicensing, or commercial distribution of software that incorporates this
source code. This means that the Licensee is free to use this software for
educational, research, and prototyping purposes, to create musical or other
creative works with software that incorporates this source code, or any other
use that does not constitute selling software that makes use of this source
code. Commercial distribution also includes the packaging of free software with
other paid software, hardware, or software-provided commercial services.

For entities with UNDER 200k USD in annual revenue or funding, a license is hereby
granted, free of charge, for the sale, sublicensing, or commercial distribution
of software that incorporates this source code, for as long as the entity's
annual revenue remains below 200k USD annual revenue or funding.

For entities with OVER 200k USD in annual revenue or funding interested in the
sale, sublicensing, or commercial distribution of software that incorporates
this source code, please send inquiries to licensing (at) cycling74.com.

The above copyright notice and this license shall be included in all copies or
substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

Please see
https://support.cycling74.com/hc/en-us/articles/360050779193-Gen-Code-Export-Licensing-FAQ
for additional information

B) General Public License Version 3 (GPLv3)
Details of the GPLv3 license can be found at: https://www.gnu.org/licenses/gpl-3.0.html
****************************************************************************************/

// global noise generator
Noise noise;
static const int GENLIB_LOOPCOUNT_BAIL = 100000;


// The State struct contains all the state and procedures for the gendsp kernel
typedef struct State {
	CommonState __commonstate;
	Change __m_change_31;
	Change __m_change_17;
	Change __m_change_16;
	Change __m_change_44;
	Change __m_change_9;
	Change __m_change_38;
	Change __m_change_23;
	Change __m_change_37;
	Change __m_change_24;
	Change __m_change_45;
	Change __m_change_10;
	Change __m_change_51;
	Change __m_change_58;
	Change __m_change_64;
	Change __m_change_65;
	Change __m_change_57;
	Change __m_change_30;
	Delta __m_delta_52;
	Delta __m_delta_66;
	Delta __m_delta_25;
	Delta __m_delta_39;
	Delta __m_delta_32;
	Delta __m_delta_59;
	Delta __m_delta_11;
	Delta __m_delta_46;
	Delta __m_delta_18;
	int __exception;
	int vectorsize;
	t_sample __m_carry_55;
	t_sample __m_count_67;
	t_sample m_button_4;
	t_sample __m_count_53;
	t_sample m_button_5;
	t_sample m_button_3;
	t_sample m_button_2;
	t_sample __m_count_60;
	t_sample samplerate;
	t_sample m_button_6;
	t_sample m_button_1;
	t_sample __m_carry_62;
	t_sample __m_carry_28;
	t_sample __m_carry_49;
	t_sample m_button_7;
	t_sample __m_carry_35;
	t_sample __m_carry_21;
	t_sample __m_count_33;
	t_sample __m_count_26;
	t_sample __m_count_47;
	t_sample __m_count_19;
	t_sample __m_count_40;
	t_sample m_button_8;
	t_sample __m_carry_14;
	t_sample __m_count_12;
	t_sample __m_carry_42;
	t_sample __m_carry_69;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_button_1 = ((int)0);
		m_button_2 = ((int)0);
		m_button_3 = ((int)0);
		m_button_4 = ((int)0);
		m_button_5 = ((int)0);
		m_button_6 = ((int)0);
		m_button_7 = ((int)0);
		m_button_8 = ((int)0);
		__m_change_9.reset(0);
		__m_change_10.reset(0);
		__m_delta_11.reset(0);
		__m_count_12 = 0;
		__m_carry_14 = 0;
		__m_change_16.reset(0);
		__m_change_17.reset(0);
		__m_delta_18.reset(0);
		__m_count_19 = 0;
		__m_carry_21 = 0;
		__m_change_23.reset(0);
		__m_change_24.reset(0);
		__m_delta_25.reset(0);
		__m_count_26 = 0;
		__m_carry_28 = 0;
		__m_change_30.reset(0);
		__m_change_31.reset(0);
		__m_delta_32.reset(0);
		__m_count_33 = 0;
		__m_carry_35 = 0;
		__m_change_37.reset(0);
		__m_change_38.reset(0);
		__m_delta_39.reset(0);
		__m_count_40 = 0;
		__m_carry_42 = 0;
		__m_change_44.reset(0);
		__m_change_45.reset(0);
		__m_delta_46.reset(0);
		__m_count_47 = 0;
		__m_carry_49 = 0;
		__m_change_51.reset(0);
		__m_delta_52.reset(0);
		__m_count_53 = 0;
		__m_carry_55 = 0;
		__m_change_57.reset(0);
		__m_change_58.reset(0);
		__m_delta_59.reset(0);
		__m_count_60 = 0;
		__m_carry_62 = 0;
		__m_change_64.reset(0);
		__m_change_65.reset(0);
		__m_delta_66.reset(0);
		__m_count_67 = 0;
		__m_carry_69 = 0;
		genlib_reset_complete(this);
		
	};
	// the signal processing routine;
	inline int perform(t_sample ** __ins, t_sample ** __outs, int __n) {
		vectorsize = __n;
		const t_sample * __in1 = __ins[0];
		t_sample * __out1 = __outs[0];
		t_sample * __out2 = __outs[1];
		t_sample * __out3 = __outs[2];
		t_sample * __out4 = __outs[3];
		t_sample * __out5 = __outs[4];
		t_sample * __out6 = __outs[5];
		t_sample * __out7 = __outs[6];
		t_sample * __out8 = __outs[7];
		t_sample * __out9 = __outs[8];
		t_sample * __out10 = __outs[9];
		if (__exception) {
			return __exception;
			
		} else if (( (__in1 == 0) || (__out1 == 0) || (__out2 == 0) || (__out3 == 0) || (__out4 == 0) || (__out5 == 0) || (__out6 == 0) || (__out7 == 0) || (__out8 == 0) || (__out9 == 0) || (__out10 == 0) )) {
			__exception = GENLIB_ERR_NULL_BUFFER;
			return __exception;
			
		};
		int int_87 = int(m_button_6);
		int int_4532 = int(m_button_1);
		int int_4536 = int(m_button_8);
		int int_4537 = int(m_button_4);
		int int_4540 = int(m_button_5);
		int int_4543 = int(m_button_7);
		int int_4548 = int(m_button_2);
		int int_4551 = int(m_button_3);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			int change_88 = __m_change_9(int_87);
			int eqp_89 = ((int_87 == change_88) ? int_87 : 0);
			int change_3226 = __m_change_10(eqp_89);
			int gt_4251 = (change_3226 > ((int)0));
			int delta_3225 = __m_delta_11(gt_4251);
			int gt_3224 = (delta_3225 > ((t_sample)0.5));
			__m_count_12 = (((int)0) ? 0 : (fixdenorm(__m_count_12 + gt_3224)));
			int carry_13 = 0;
			if ((((int)0) != 0)) {
				__m_count_12 = 0;
				__m_carry_14 = 0;
				
			} else if (((((int)2) > 0) && (__m_count_12 >= ((int)2)))) {
				int wraps_15 = (__m_count_12 / ((int)2));
				__m_carry_14 = (__m_carry_14 + wraps_15);
				__m_count_12 = (__m_count_12 - (wraps_15 * ((int)2)));
				carry_13 = 1;
				
			};
			int counter_3221 = __m_count_12;
			int counter_3222 = carry_13;
			int counter_3223 = __m_carry_14;
			t_sample out4 = counter_3221;
			int change_4531 = __m_change_16(int_4532);
			int eqp_4533 = ((int_4532 == change_4531) ? int_4532 : 0);
			int change_3194 = __m_change_17(eqp_4533);
			int gt_4466 = (change_3194 > ((int)0));
			int delta_3193 = __m_delta_18(gt_4466);
			int gt_3192 = (delta_3193 > ((t_sample)0.5));
			__m_count_19 = (((int)0) ? 0 : (fixdenorm(__m_count_19 + gt_3192)));
			int carry_20 = 0;
			if ((((int)0) != 0)) {
				__m_count_19 = 0;
				__m_carry_21 = 0;
				
			} else if (((((int)2) > 0) && (__m_count_19 >= ((int)2)))) {
				int wraps_22 = (__m_count_19 / ((int)2));
				__m_carry_21 = (__m_carry_21 + wraps_22);
				__m_count_19 = (__m_count_19 - (wraps_22 * ((int)2)));
				carry_20 = 1;
				
			};
			int counter_3189 = __m_count_19;
			int counter_3190 = carry_20;
			int counter_3191 = __m_carry_21;
			t_sample out8 = counter_3189;
			int change_4535 = __m_change_23(int_4536);
			int eqp_4534 = ((int_4536 == change_4535) ? int_4536 : 0);
			int change_3210 = __m_change_24(eqp_4534);
			int gt_4337 = (change_3210 > ((int)0));
			int delta_3209 = __m_delta_25(gt_4337);
			int gt_3208 = (delta_3209 > ((t_sample)0.5));
			__m_count_26 = (((int)0) ? 0 : (fixdenorm(__m_count_26 + gt_3208)));
			int carry_27 = 0;
			if ((((int)0) != 0)) {
				__m_count_26 = 0;
				__m_carry_28 = 0;
				
			} else if (((((int)2) > 0) && (__m_count_26 >= ((int)2)))) {
				int wraps_29 = (__m_count_26 / ((int)2));
				__m_carry_28 = (__m_carry_28 + wraps_29);
				__m_count_26 = (__m_count_26 - (wraps_29 * ((int)2)));
				carry_27 = 1;
				
			};
			int counter_3205 = __m_count_26;
			int counter_3206 = carry_27;
			int counter_3207 = __m_carry_28;
			t_sample out6 = counter_3205;
			int change_4539 = __m_change_30(int_4537);
			int eqp_4538 = ((int_4537 == change_4539) ? int_4537 : 0);
			int change_3202 = __m_change_31(eqp_4538);
			int gt_4509 = (change_3202 > ((int)0));
			int delta_3201 = __m_delta_32(gt_4509);
			int gt_3200 = (delta_3201 > ((t_sample)0.5));
			__m_count_33 = (((int)0) ? 0 : (fixdenorm(__m_count_33 + gt_3200)));
			int carry_34 = 0;
			if ((((int)0) != 0)) {
				__m_count_33 = 0;
				__m_carry_35 = 0;
				
			} else if (((((int)2) > 0) && (__m_count_33 >= ((int)2)))) {
				int wraps_36 = (__m_count_33 / ((int)2));
				__m_carry_35 = (__m_carry_35 + wraps_36);
				__m_count_33 = (__m_count_33 - (wraps_36 * ((int)2)));
				carry_34 = 1;
				
			};
			int counter_3197 = __m_count_33;
			int counter_3198 = carry_34;
			int counter_3199 = __m_carry_35;
			t_sample out7 = counter_3197;
			int change_4542 = __m_change_37(int_4540);
			int eqp_4541 = ((int_4540 == change_4542) ? int_4540 : 0);
			int change_3186 = __m_change_38(eqp_4541);
			int gt_4423 = (change_3186 > ((int)0));
			int delta_3185 = __m_delta_39(gt_4423);
			int gt_3184 = (delta_3185 > ((t_sample)0.5));
			__m_count_40 = (((int)0) ? 0 : (fixdenorm(__m_count_40 + gt_3184)));
			int carry_41 = 0;
			if ((((int)0) != 0)) {
				__m_count_40 = 0;
				__m_carry_42 = 0;
				
			} else if (((((int)2) > 0) && (__m_count_40 >= ((int)2)))) {
				int wraps_43 = (__m_count_40 / ((int)2));
				__m_carry_42 = (__m_carry_42 + wraps_43);
				__m_count_40 = (__m_count_40 - (wraps_43 * ((int)2)));
				carry_41 = 1;
				
			};
			int counter_3181 = __m_count_40;
			int counter_3182 = carry_41;
			int counter_3183 = __m_carry_42;
			t_sample out9 = counter_3181;
			int change_4545 = __m_change_44(int_4543);
			int eqp_4544 = ((int_4543 == change_4545) ? int_4543 : 0);
			int change_3218 = __m_change_45(eqp_4544);
			int gt_4294 = (change_3218 > ((int)0));
			int delta_3217 = __m_delta_46(gt_4294);
			int gt_3216 = (delta_3217 > ((t_sample)0.5));
			__m_count_47 = (((int)0) ? 0 : (fixdenorm(__m_count_47 + gt_3216)));
			int carry_48 = 0;
			if ((((int)0) != 0)) {
				__m_count_47 = 0;
				__m_carry_49 = 0;
				
			} else if (((((int)2) > 0) && (__m_count_47 >= ((int)2)))) {
				int wraps_50 = (__m_count_47 / ((int)2));
				__m_carry_49 = (__m_carry_49 + wraps_50);
				__m_count_47 = (__m_count_47 - (wraps_50 * ((int)2)));
				carry_48 = 1;
				
			};
			int counter_3213 = __m_count_47;
			int counter_3214 = carry_48;
			int counter_3215 = __m_carry_49;
			t_sample out5 = counter_3213;
			int change_3713 = __m_change_51(in1);
			int gt_4034 = (change_3713 > ((int)0));
			int delta_3712 = __m_delta_52(gt_4034);
			int gt_3711 = (delta_3712 > ((t_sample)0.5));
			__m_count_53 = (((int)0) ? 0 : (fixdenorm(__m_count_53 + gt_3711)));
			int carry_54 = 0;
			if ((((int)0) != 0)) {
				__m_count_53 = 0;
				__m_carry_55 = 0;
				
			} else if (((((int)2) > 0) && (__m_count_53 >= ((int)2)))) {
				int wraps_56 = (__m_count_53 / ((int)2));
				__m_carry_55 = (__m_carry_55 + wraps_56);
				__m_count_53 = (__m_count_53 - (wraps_56 * ((int)2)));
				carry_54 = 1;
				
			};
			int counter_4184 = __m_count_53;
			int counter_4185 = carry_54;
			int counter_4186 = __m_carry_55;
			t_sample out1 = counter_4184;
			int change_4547 = __m_change_57(int_4548);
			int eqp_4546 = ((int_4548 == change_4547) ? int_4548 : 0);
			int change_3178 = __m_change_58(eqp_4546);
			int gt_4380 = (change_3178 > ((int)0));
			int delta_3177 = __m_delta_59(gt_4380);
			int gt_3176 = (delta_3177 > ((t_sample)0.5));
			__m_count_60 = (((int)0) ? 0 : (fixdenorm(__m_count_60 + gt_3176)));
			int carry_61 = 0;
			if ((((int)0) != 0)) {
				__m_count_60 = 0;
				__m_carry_62 = 0;
				
			} else if (((((int)2) > 0) && (__m_count_60 >= ((int)2)))) {
				int wraps_63 = (__m_count_60 / ((int)2));
				__m_carry_62 = (__m_carry_62 + wraps_63);
				__m_count_60 = (__m_count_60 - (wraps_63 * ((int)2)));
				carry_61 = 1;
				
			};
			int counter_3173 = __m_count_60;
			int counter_3174 = carry_61;
			int counter_3175 = __m_carry_62;
			t_sample out10 = counter_3173;
			int change_4550 = __m_change_64(int_4551);
			int eqp_4549 = ((int_4551 == change_4550) ? int_4551 : 0);
			int change_3236 = __m_change_65(eqp_4549);
			int gt_4208 = (change_3236 > ((int)0));
			int delta_3235 = __m_delta_66(gt_4208);
			int gt_3234 = (delta_3235 > ((t_sample)0.5));
			__m_count_67 = (((int)0) ? 0 : (fixdenorm(__m_count_67 + gt_3234)));
			int carry_68 = 0;
			if ((((int)0) != 0)) {
				__m_count_67 = 0;
				__m_carry_69 = 0;
				
			} else if (((((int)2) > 0) && (__m_count_67 >= ((int)2)))) {
				int wraps_70 = (__m_count_67 / ((int)2));
				__m_carry_69 = (__m_carry_69 + wraps_70);
				__m_count_67 = (__m_count_67 - (wraps_70 * ((int)2)));
				carry_68 = 1;
				
			};
			int counter_3231 = __m_count_67;
			int counter_3232 = carry_68;
			int counter_3233 = __m_carry_69;
			t_sample out3 = counter_3231;
			// assign results to output buffer;
			(*(__out1++)) = out1;
			(*(__out2++)) = 0;
			(*(__out3++)) = out3;
			(*(__out4++)) = out4;
			(*(__out5++)) = out5;
			(*(__out6++)) = out6;
			(*(__out7++)) = out7;
			(*(__out8++)) = out8;
			(*(__out9++)) = out9;
			(*(__out10++)) = out10;
			
		};
		return __exception;
		
	};
	inline void set_button6(t_param _value) {
		m_button_1 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_button8(t_param _value) {
		m_button_2 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_button1(t_param _value) {
		m_button_3 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_button5(t_param _value) {
		m_button_4 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_button7(t_param _value) {
		m_button_5 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_button2(t_param _value) {
		m_button_6 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_button3(t_param _value) {
		m_button_7 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_button4(t_param _value) {
		m_button_8 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	
} State;


///
///	Configuration for the genlib API
///

/// Number of signal inputs and outputs

int gen_kernel_numins = 1;
int gen_kernel_numouts = 10;

int num_inputs() { return gen_kernel_numins; }
int num_outputs() { return gen_kernel_numouts; }
int num_params() { return 8; }

/// Assistive lables for the signal inputs and outputs

const char *gen_kernel_innames[] = { "in1" };
const char *gen_kernel_outnames[] = { "out1", "out2", "led1", "led2", "led3", "led4", "led5", "led6", "led7", "led8" };

/// Invoke the signal process of a State object

int perform(CommonState *cself, t_sample **ins, long numins, t_sample **outs, long numouts, long n) {
	State* self = (State *)cself;
	return self->perform(ins, outs, n);
}

/// Reset all parameters and stateful operators of a State object

void reset(CommonState *cself) {
	State* self = (State *)cself;
	self->reset(cself->sr, cself->vs);
}

/// Set a parameter of a State object

void setparameter(CommonState *cself, long index, t_param value, void *ref) {
	State *self = (State *)cself;
	switch (index) {
		case 0: self->set_button1(value); break;
		case 1: self->set_button2(value); break;
		case 2: self->set_button3(value); break;
		case 3: self->set_button4(value); break;
		case 4: self->set_button5(value); break;
		case 5: self->set_button6(value); break;
		case 6: self->set_button7(value); break;
		case 7: self->set_button8(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_button_3; break;
		case 1: *value = self->m_button_6; break;
		case 2: *value = self->m_button_7; break;
		case 3: *value = self->m_button_8; break;
		case 4: *value = self->m_button_4; break;
		case 5: *value = self->m_button_1; break;
		case 6: *value = self->m_button_5; break;
		case 7: *value = self->m_button_2; break;
		
		default: break;
	}
}

/// Get the name of a parameter of a State object

const char *getparametername(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].name;
	}
	return 0;
}

/// Get the minimum value of a parameter of a State object

t_param getparametermin(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].outputmin;
	}
	return 0;
}

/// Get the maximum value of a parameter of a State object

t_param getparametermax(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].outputmax;
	}
	return 0;
}

/// Get parameter of a State object has a minimum and maximum value

char getparameterhasminmax(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].hasminmax;
	}
	return 0;
}

/// Get the units of a parameter of a State object

const char *getparameterunits(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].units;
	}
	return 0;
}

/// Get the size of the state of all parameters of a State object

size_t getstatesize(CommonState *cself) {
	return genlib_getstatesize(cself, &getparameter);
}

/// Get the state of all parameters of a State object

short getstate(CommonState *cself, char *state) {
	return genlib_getstate(cself, state, &getparameter);
}

/// set the state of all parameters of a State object

short setstate(CommonState *cself, const char *state) {
	return genlib_setstate(cself, state, &setparameter);
}

/// Allocate and configure a new State object and it's internal CommonState:

void *create(t_param sr, long vs) {
	State *self = new State;
	self->reset(sr, vs);
	ParamInfo *pi;
	self->__commonstate.inputnames = gen_kernel_innames;
	self->__commonstate.outputnames = gen_kernel_outnames;
	self->__commonstate.numins = gen_kernel_numins;
	self->__commonstate.numouts = gen_kernel_numouts;
	self->__commonstate.sr = sr;
	self->__commonstate.vs = vs;
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(8 * sizeof(ParamInfo));
	self->__commonstate.numparams = 8;
	// initialize parameter 0 ("m_button_3")
	pi = self->__commonstate.params + 0;
	pi->name = "button1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_button_3;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_button_6")
	pi = self->__commonstate.params + 1;
	pi->name = "button2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_button_6;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_button_7")
	pi = self->__commonstate.params + 2;
	pi->name = "button3";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_button_7;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_button_8")
	pi = self->__commonstate.params + 3;
	pi->name = "button4";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_button_8;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_button_4")
	pi = self->__commonstate.params + 4;
	pi->name = "button5";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_button_4;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_button_1")
	pi = self->__commonstate.params + 5;
	pi->name = "button6";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_button_1;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_button_5")
	pi = self->__commonstate.params + 6;
	pi->name = "button7";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_button_5;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 7 ("m_button_2")
	pi = self->__commonstate.params + 7;
	pi->name = "button8";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_button_2;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	
	return self;
}

/// Release all resources and memory used by a State object:

void destroy(CommonState *cself) {
	State *self = (State *)cself;
	genlib_sysmem_freeptr(cself->params);
		
	delete self;
}


} // button_2dto_2dlight_2dtest::
