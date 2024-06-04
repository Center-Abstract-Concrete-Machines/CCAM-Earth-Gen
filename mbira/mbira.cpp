#include "mbira.h"

namespace mbira {

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
	Change __m_change_34;
	Change __m_change_35;
	Change __m_change_33;
	Change __m_change_32;
	Change __m_change_37;
	Change __m_change_36;
	Change __m_change_39;
	Change __m_change_38;
	Change __m_change_19;
	Data m_velocities_10;
	Data m_notes_18;
	Delay m_delay_5;
	Delay m_delay_3;
	Phasor __m_phasor_20;
	int __exception;
	int vectorsize;
	t_sample __m_slide_29;
	t_sample samples_to_seconds;
	t_sample m_sw_17;
	t_sample m_sw_15;
	t_sample __m_latch_40;
	t_sample m_avg_4;
	t_sample m_sw_6;
	t_sample m_avg_2;
	t_sample samplerate;
	t_sample m_history_1;
	t_sample m_sw_16;
	t_sample m_gate_7;
	t_sample m_sw_9;
	t_sample m_sw_14;
	t_sample m_bpm_8;
	t_sample m_sw_13;
	t_sample m_feedback_11;
	t_sample m_sw_12;
	t_sample __m_slide_42;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_history_1 = ((int)0);
		m_avg_2 = ((int)0);
		m_delay_3.reset("m_delay_3", samplerate);
		m_avg_4 = ((int)0);
		m_delay_5.reset("m_delay_5", samplerate);
		m_sw_6 = ((int)0);
		m_gate_7 = ((int)0);
		m_bpm_8 = ((int)0);
		m_sw_9 = ((int)0);
		m_velocities_10.reset("velocities", ((int)529200), ((int)1));
		m_feedback_11 = ((int)0);
		m_sw_12 = ((int)0);
		m_sw_13 = ((int)0);
		m_sw_14 = ((int)0);
		m_sw_15 = ((int)0);
		m_sw_16 = ((int)0);
		m_sw_17 = ((int)0);
		m_notes_18.reset("notes", ((int)529200), ((int)1));
		__m_change_19.reset(0);
		samples_to_seconds = (1 / samplerate);
		__m_phasor_20.reset(0);
		__m_slide_29 = 0;
		__m_change_32.reset(0);
		__m_change_33.reset(0);
		__m_change_34.reset(0);
		__m_change_35.reset(0);
		__m_change_36.reset(0);
		__m_change_37.reset(0);
		__m_change_38.reset(0);
		__m_change_39.reset(0);
		__m_latch_40 = 0;
		__m_slide_42 = 0;
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
		t_sample * __out11 = __outs[10];
		t_sample * __out12 = __outs[11];
		t_sample * __out13 = __outs[12];
		if (__exception) {
			return __exception;
			
		} else if (( (__in1 == 0) || (__out1 == 0) || (__out2 == 0) || (__out3 == 0) || (__out4 == 0) || (__out5 == 0) || (__out6 == 0) || (__out7 == 0) || (__out8 == 0) || (__out9 == 0) || (__out10 == 0) || (__out11 == 0) || (__out12 == 0) || (__out13 == 0) )) {
			__exception = GENLIB_ERR_NULL_BUFFER;
			return __exception;
			
		};
		t_sample sub_9999 = (m_bpm_8 - ((int)0));
		t_sample scale_9996 = ((safepow((sub_9999 * ((t_sample)1)), ((int)1)) * ((int)160)) + ((int)40));
		t_sample scale_527 = scale_9996;
		t_sample rdiv_5351 = safediv(((int)60), scale_527);
		t_sample mul_5352 = (rdiv_5351 * samplerate);
		t_sample mul_5350 = (mul_5352 * ((int)8));
		t_sample gen_5353 = mul_5350;
		t_sample div_593 = (scale_527 * ((t_sample)0.016666666666667));
		t_sample mul_595 = (div_593 * ((int)1));
		t_sample div_590 = (mul_595 * ((t_sample)0.25));
		samples_to_seconds = (1 / samplerate);
		int notes_dim = m_notes_18.dim;
		int notes_channels = m_notes_18.channels;
		int velocities_dim = m_velocities_10.dim;
		int velocities_channels = m_velocities_10.channels;
		t_sample iup_30 = (1 / maximum(1, abs(((int)0))));
		t_sample idown_31 = (1 / maximum(1, abs(((int)10))));
		int int_107 = int(m_sw_17);
		int int_9935 = int(m_sw_12);
		int int_9938 = int(m_sw_14);
		int int_9941 = int(m_sw_6);
		int int_9944 = int(m_sw_16);
		int int_9947 = int(m_sw_13);
		int int_9950 = int(m_sw_15);
		int int_9953 = int(m_sw_9);
		t_sample iup_43 = (1 / maximum(1, abs(((int)0))));
		t_sample idown_44 = (1 / maximum(1, abs(((int)10))));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample out11 = ((int)0);
			t_sample out12 = ((int)0);
			t_sample out13 = gen_5353;
			int change_6450 = __m_change_19(m_history_1);
			int neq_6784 = (change_6450 != ((int)0));
			t_sample switch_6551 = (neq_6784 ? ((int)0) : m_history_1);
			int switch_7583 = (neq_6784 ? ((int)1) : ((int)0));
			t_sample phasor_591 = __m_phasor_20(div_590, samples_to_seconds);
			t_sample gen_597 = phasor_591;
			t_sample mul_5385 = (gen_597 * gen_5353);
			t_sample floor_5892 = floor(mul_5385);
			int index_trunc_21 = fixnan(floor(floor_5892));
			bool index_ignore_22 = ((index_trunc_21 >= notes_dim) || (index_trunc_21 < 0));
			if ((!index_ignore_22)) {
				m_notes_18.write(switch_6551, index_trunc_21, 0);
				
			};
			int index_trunc_23 = fixnan(floor(floor_5892));
			bool index_ignore_24 = ((index_trunc_23 >= velocities_dim) || (index_trunc_23 < 0));
			if ((!index_ignore_24)) {
				m_velocities_10.write((switch_7583 + (m_velocities_10.read(index_trunc_23, 0) * m_feedback_11)), index_trunc_23, 0);
				
			};
			int index_trunc_25 = fixnan(floor(floor_5892));
			bool index_ignore_26 = ((index_trunc_25 >= notes_dim) || (index_trunc_25 < 0));
			// samples notes channel 1;
			t_sample sample_notes_7732 = (index_ignore_26 ? 0 : m_notes_18.read(index_trunc_25, 0));
			t_sample index_notes_7733 = floor_5892;
			t_sample mul_4136 = (gen_597 * ((int)8));
			t_sample floor_4135 = floor(mul_4136);
			int eq_3796 = (floor_4135 == ((int)1));
			t_sample out4 = eq_3796;
			int eq_3868 = (floor_4135 == ((int)2));
			t_sample out5 = eq_3868;
			int eq_3989 = (floor_4135 == ((int)4));
			t_sample out7 = eq_3989;
			int eq_4084 = (floor_4135 == ((int)7));
			t_sample out10 = eq_4084;
			int eq_4013 = (floor_4135 == ((int)5));
			t_sample out8 = eq_4013;
			int eq_3702 = (floor_4135 == ((int)0));
			t_sample out3 = eq_3702;
			int eq_4037 = (floor_4135 == ((int)6));
			t_sample out9 = eq_4037;
			int eq_3892 = (floor_4135 == ((int)3));
			t_sample out6 = eq_3892;
			t_sample noise_9031 = noise();
			t_sample noise_2915 = noise();
			int index_trunc_27 = fixnan(floor(floor_5892));
			bool index_ignore_28 = ((index_trunc_27 >= velocities_dim) || (index_trunc_27 < 0));
			// samples velocities channel 1;
			t_sample sample_velocities_7365 = (index_ignore_28 ? 0 : m_velocities_10.read(index_trunc_27, 0));
			t_sample index_velocities_7366 = floor_5892;
			__m_slide_29 = fixdenorm((__m_slide_29 + (((sample_velocities_7365 > __m_slide_29) ? iup_30 : idown_31) * (sample_velocities_7365 - __m_slide_29))));
			t_sample slide_9032 = __m_slide_29;
			t_sample mul_9030 = (slide_9032 * noise_9031);
			t_sample mtof_703 = mtof(mul_9030, ((int)440));
			t_sample rdiv_702 = safediv(samplerate, mtof_703);
			t_sample tap_707 = m_delay_5.read_linear(rdiv_702);
			t_sample gen_8362 = tap_707;
			t_sample mul_700 = (((t_sample)0.97) * mtof_703);
			t_sample t_701 = exp(safediv(-6.9077552789821, mul_700));
			t_sample mul_704 = (tap_707 * t_701);
			t_sample mix_10000 = (mul_704 + (((t_sample)0.25) * (m_avg_4 - mul_704)));
			t_sample mix_705 = mix_10000;
			t_sample avg_next_708 = fixdenorm(mix_705);
			int change_108 = __m_change_32(int_107);
			int eqp_109 = ((int_107 == change_108) ? int_107 : 0);
			int gen_230 = eqp_109;
			int mul_1013 = (gen_230 * ((int)1));
			int change_9934 = __m_change_33(int_9935);
			int eqp_9933 = ((int_9935 == change_9934) ? int_9935 : 0);
			int gen_229 = eqp_9933;
			int mul_1722 = (gen_229 * ((int)2));
			int change_9937 = __m_change_34(int_9938);
			int eqp_9936 = ((int_9938 == change_9937) ? int_9938 : 0);
			int gen_228 = eqp_9936;
			int mul_1794 = (gen_228 * ((int)3));
			int change_9940 = __m_change_35(int_9941);
			int eqp_9939 = ((int_9941 == change_9940) ? int_9941 : 0);
			int gen_227 = eqp_9939;
			int mul_1864 = (gen_227 * ((int)4));
			int change_9943 = __m_change_36(int_9944);
			int eqp_9942 = ((int_9944 == change_9943) ? int_9944 : 0);
			int gen_112 = eqp_9942;
			int mul_2220 = (gen_112 * ((int)6));
			int change_9946 = __m_change_37(int_9947);
			int eqp_9945 = ((int_9947 == change_9946) ? int_9947 : 0);
			int gen_111 = eqp_9945;
			int mul_2244 = (gen_111 * ((int)7));
			int change_9949 = __m_change_38(int_9950);
			int eqp_9948 = ((int_9950 == change_9949) ? int_9950 : 0);
			int gen_845 = eqp_9948;
			int mul_2314 = (gen_845 * ((int)8));
			int change_9952 = __m_change_39(int_9953);
			int eqp_9951 = ((int_9953 == change_9952) ? int_9953 : 0);
			int gen_113 = eqp_9951;
			int mul_2104 = (gen_113 * ((int)5));
			int add_1605 = ((((((((mul_2104 + mul_2314) + mul_2244) + mul_2220) + mul_1864) + mul_1794) + mul_1722) + mul_1013) + ((int)0));
			int gt_2430 = (add_1605 > ((int)0));
			__m_latch_40 = ((gt_2430 != 0) ? add_1605 : __m_latch_40);
			int latch_2454 = __m_latch_40;
			int choice_41 = latch_2454;
			int selector_966 = ((choice_41 >= 8) ? ((int)72) : ((choice_41 >= 7) ? ((int)70) : ((choice_41 >= 6) ? ((int)69) : ((choice_41 >= 5) ? ((int)67) : ((choice_41 >= 4) ? ((int)65) : ((choice_41 >= 3) ? ((int)63) : ((choice_41 >= 2) ? ((int)62) : ((choice_41 >= 1) ? ((int)60) : 0))))))));
			int note_6383 = selector_966;
			int add_712 = ((((((((gen_111 + gen_112) + gen_113) + gen_845) + gen_227) + gen_228) + gen_229) + gen_230) + ((int)0));
			__m_slide_42 = fixdenorm((__m_slide_42 + (((add_712 > __m_slide_42) ? iup_43 : idown_44) * (add_712 - __m_slide_42))));
			t_sample slide_3101 = __m_slide_42;
			t_sample mul_2939 = (slide_3101 * noise_2915);
			t_sample mtof_9960 = mtof(selector_966, ((int)440));
			t_sample rdiv_9955 = safediv(samplerate, mtof_9960);
			t_sample tap_9963 = m_delay_3.read_linear(rdiv_9955);
			t_sample gen_709 = tap_9963;
			t_sample mul_9956 = (((t_sample)0.97) * mtof_9960);
			t_sample t_9958 = exp(safediv(-6.9077552789821, mul_9956));
			t_sample mul_9961 = (tap_9963 * t_9958);
			t_sample mix_10001 = (mul_9961 + (((t_sample)0.25) * (m_avg_2 - mul_9961)));
			t_sample mix_9965 = mix_10001;
			t_sample avg_next_9957 = fixdenorm(mix_9965);
			t_sample right_9813 = (gen_709 + gen_8362);
			t_sample out2 = right_9813;
			t_sample left_9846 = (gen_709 + gen_8362);
			t_sample out1 = left_9846;
			t_sample history_7183_next_9968 = fixdenorm(note_6383);
			m_delay_5.write((sample_notes_7732 + m_avg_4));
			m_avg_4 = avg_next_708;
			m_delay_3.write((mul_2939 + m_avg_2));
			m_avg_2 = avg_next_9957;
			m_history_1 = history_7183_next_9968;
			m_delay_3.step();
			m_delay_5.step();
			// assign results to output buffer;
			(*(__out1++)) = out1;
			(*(__out2++)) = out2;
			(*(__out3++)) = out3;
			(*(__out4++)) = out4;
			(*(__out5++)) = out5;
			(*(__out6++)) = out6;
			(*(__out7++)) = out7;
			(*(__out8++)) = out8;
			(*(__out9++)) = out9;
			(*(__out10++)) = out10;
			(*(__out11++)) = out11;
			(*(__out12++)) = out12;
			(*(__out13++)) = out13;
			
		};
		return __exception;
		
	};
	inline void set_sw4(t_param _value) {
		m_sw_6 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_gate1(t_param _value) {
		m_gate_7 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_bpm(t_param _value) {
		m_bpm_8 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw5(t_param _value) {
		m_sw_9 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_velocities(void * _value) {
		m_velocities_10.setbuffer(_value);
	};
	inline void set_feedback(t_param _value) {
		m_feedback_11 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw2(t_param _value) {
		m_sw_12 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw7(t_param _value) {
		m_sw_13 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw3(t_param _value) {
		m_sw_14 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw8(t_param _value) {
		m_sw_15 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw6(t_param _value) {
		m_sw_16 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_17 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_notes(void * _value) {
		m_notes_18.setbuffer(_value);
	};
	
} State;


///
///	Configuration for the genlib API
///

/// Number of signal inputs and outputs

int gen_kernel_numins = 1;
int gen_kernel_numouts = 13;

int num_inputs() { return gen_kernel_numins; }
int num_outputs() { return gen_kernel_numouts; }
int num_params() { return 13; }

/// Assistive lables for the signal inputs and outputs

const char *gen_kernel_innames[] = { "in1" };
const char *gen_kernel_outnames[] = { "out1", "out2", "led1", "led2", "led3", "led4", "led5", "led6", "led7", "led8", "cvout1", "cvout2", "out13" };

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
		case 0: self->set_bpm(value); break;
		case 1: self->set_feedback(value); break;
		case 2: self->set_gate1(value); break;
		case 3: self->set_notes(ref); break;
		case 4: self->set_sw1(value); break;
		case 5: self->set_sw2(value); break;
		case 6: self->set_sw3(value); break;
		case 7: self->set_sw4(value); break;
		case 8: self->set_sw5(value); break;
		case 9: self->set_sw6(value); break;
		case 10: self->set_sw7(value); break;
		case 11: self->set_sw8(value); break;
		case 12: self->set_velocities(ref); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_bpm_8; break;
		case 1: *value = self->m_feedback_11; break;
		case 2: *value = self->m_gate_7; break;
		
		case 4: *value = self->m_sw_17; break;
		case 5: *value = self->m_sw_12; break;
		case 6: *value = self->m_sw_14; break;
		case 7: *value = self->m_sw_6; break;
		case 8: *value = self->m_sw_9; break;
		case 9: *value = self->m_sw_16; break;
		case 10: *value = self->m_sw_13; break;
		case 11: *value = self->m_sw_15; break;
		
		
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
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(13 * sizeof(ParamInfo));
	self->__commonstate.numparams = 13;
	// initialize parameter 0 ("m_bpm_8")
	pi = self->__commonstate.params + 0;
	pi->name = "bpm";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_bpm_8;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_feedback_11")
	pi = self->__commonstate.params + 1;
	pi->name = "feedback";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_feedback_11;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_gate_7")
	pi = self->__commonstate.params + 2;
	pi->name = "gate1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_gate_7;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_notes_18")
	pi = self->__commonstate.params + 3;
	pi->name = "notes";
	pi->paramtype = GENLIB_PARAMTYPE_SYM;
	pi->defaultvalue = 0.;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_sw_17")
	pi = self->__commonstate.params + 4;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_17;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_sw_12")
	pi = self->__commonstate.params + 5;
	pi->name = "sw2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_12;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_sw_14")
	pi = self->__commonstate.params + 6;
	pi->name = "sw3";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_14;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 7 ("m_sw_6")
	pi = self->__commonstate.params + 7;
	pi->name = "sw4";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_6;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 8 ("m_sw_9")
	pi = self->__commonstate.params + 8;
	pi->name = "sw5";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_9;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 9 ("m_sw_16")
	pi = self->__commonstate.params + 9;
	pi->name = "sw6";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_16;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 10 ("m_sw_13")
	pi = self->__commonstate.params + 10;
	pi->name = "sw7";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_13;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 11 ("m_sw_15")
	pi = self->__commonstate.params + 11;
	pi->name = "sw8";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_15;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 12 ("m_velocities_10")
	pi = self->__commonstate.params + 12;
	pi->name = "velocities";
	pi->paramtype = GENLIB_PARAMTYPE_SYM;
	pi->defaultvalue = 0.;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
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


} // mbira::
