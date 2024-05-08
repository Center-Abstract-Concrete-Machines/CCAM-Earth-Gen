#include "backbeat.h"

namespace backbeat {

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
	Change __m_change_22;
	Change __m_change_19;
	Change __m_change_20;
	Change __m_change_17;
	Delta __m_delta_21;
	SineCycle __m_cycle_18;
	SineData __sinedata;
	int __exception;
	int vectorsize;
	t_sample m_history_6;
	t_sample m_history_3;
	t_sample m_history_16;
	t_sample m_history_15;
	t_sample m_history_2;
	t_sample samplerate;
	t_sample m_history_1;
	t_sample m_history_5;
	t_sample m_history_14;
	t_sample m_history_12;
	t_sample m_history_8;
	t_sample m_history_7;
	t_sample m_history_13;
	t_sample m_history_9;
	t_sample m_history_11;
	t_sample m_history_4;
	t_sample m_history_10;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_history_1 = ((int)0);
		m_history_2 = ((int)0);
		m_history_3 = ((int)0);
		m_history_4 = ((int)0);
		m_history_5 = ((int)0);
		m_history_6 = ((int)0);
		m_history_7 = ((int)0);
		m_history_8 = ((int)0);
		m_history_9 = ((int)0);
		m_history_10 = ((int)0);
		m_history_11 = ((int)0);
		m_history_12 = ((int)0);
		m_history_13 = ((int)0);
		m_history_14 = ((int)0);
		m_history_15 = ((int)0);
		m_history_16 = ((int)0);
		__m_change_17.reset(0);
		__m_cycle_18.reset(samplerate, 0);
		__m_change_19.reset(0);
		__m_change_20.reset(0);
		__m_delta_21.reset(0);
		__m_change_22.reset(0);
		genlib_reset_complete(this);
		
	};
	// the signal processing routine;
	inline int perform(t_sample ** __ins, t_sample ** __outs, int __n) {
		vectorsize = __n;
		const t_sample * __in1 = __ins[0];
		const t_sample * __in2 = __ins[1];
		t_sample * __out1 = __outs[0];
		if (__exception) {
			return __exception;
			
		} else if (( (__in1 == 0) || (__in2 == 0) || (__out1 == 0) )) {
			__exception = GENLIB_ERR_NULL_BUFFER;
			return __exception;
			
		};
		t_sample history_48481_next_48517 = fixdenorm(((t_sample)0.25));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample sub_48502 = (in1 - m_history_16);
			t_sample add_48503 = (in1 + m_history_16);
			t_sample div_48501 = safediv(sub_48502, add_48503);
			t_sample abs_48500 = fabs(div_48501);
			int gt_48498 = (abs_48500 > ((t_sample)0.5));
			int change_48497 = __m_change_17(gt_48498);
			int gt_48496 = (change_48497 > ((int)0));
			int gen_48558 = gt_48496;
			t_sample history_48499_next_48504 = fixdenorm(in1);
			int gt_48561 = (gen_48558 > ((int)0));
			t_sample switch_48562 = (gt_48561 ? ((int)1) : ((t_sample)0.003));
			t_sample mix_50815 = (m_history_15 + (switch_48562 * (gen_48558 - m_history_15)));
			t_sample mix_48563 = mix_50815;
			t_sample mix_50816 = (mix_48563 + (((t_sample)0.98) * (m_history_14 - mix_48563)));
			t_sample mix_48559 = mix_50816;
			t_sample mul_48565 = (mix_48559 * ((int)330));
			__m_cycle_18.freq(mul_48565);
			t_sample cycle_48566 = __m_cycle_18(__sinedata);
			t_sample cycleindex_48567 = __m_cycle_18.phase();
			t_sample mul_48568 = (mix_48559 * cycle_48566);
			t_sample history_48564_next_48569 = fixdenorm(mix_48563);
			t_sample history_48560_next_48570 = fixdenorm(mix_48559);
			t_sample sub_48578 = (in2 - m_history_13);
			t_sample add_48574 = (in2 + m_history_13);
			t_sample div_48573 = safediv(sub_48578, add_48574);
			t_sample abs_48575 = fabs(div_48573);
			int gt_48572 = (abs_48575 > ((t_sample)0.5));
			int change_48580 = __m_change_19(gt_48572);
			int gt_48579 = (change_48580 > ((int)0));
			int gen_48552 = gt_48579;
			t_sample history_48499_next_48577 = fixdenorm(in2);
			int gt_48548 = (gen_48552 > ((int)0));
			t_sample switch_48549 = (gt_48548 ? ((int)1) : ((t_sample)2e-05));
			t_sample mix_50817 = (m_history_12 + (switch_48549 * (gen_48552 - m_history_12)));
			t_sample mix_48550 = mix_50817;
			t_sample mix_50818 = (mix_48550 + (((t_sample)0.95) * (m_history_11 - mix_48550)));
			t_sample mix_48546 = mix_50818;
			t_sample noise_48544 = noise();
			t_sample mul_48542 = (mix_48546 * noise_48544);
			t_sample mix_50819 = (mul_48542 + (((t_sample)0.99) * (m_history_10 - mul_48542)));
			t_sample mix_48545 = mix_50819;
			t_sample sub_48538 = (mul_48542 - mix_48545);
			t_sample mix_50820 = (sub_48538 + (((t_sample)0.99) * (m_history_9 - sub_48538)));
			t_sample mix_48540 = mix_50820;
			t_sample sub_48541 = (sub_48538 - mix_48540);
			t_sample mul_48537 = (sub_48541 * ((t_sample)0.04));
			t_sample history_48551_next_48553 = fixdenorm(mix_48550);
			t_sample history_48547_next_48554 = fixdenorm(mix_48546);
			t_sample history_48543_next_48555 = fixdenorm(mix_48545);
			t_sample history_48539_next_48556 = fixdenorm(mix_48540);
			t_sample mul_48486 = (in1 * ((int)4));
			t_sample sub_48586 = (in1 - m_history_8);
			t_sample add_48583 = (in1 + m_history_8);
			t_sample div_48582 = safediv(sub_48586, add_48583);
			t_sample abs_48584 = fabs(div_48582);
			int gt_48588 = (abs_48584 > ((t_sample)0.5));
			int change_48590 = __m_change_20(gt_48588);
			int gt_48587 = (change_48590 > ((int)0));
			int gen_48505 = gt_48587;
			t_sample history_48499_next_48589 = fixdenorm(in1);
			t_sample delta_48511 = __m_delta_21(in1);
			t_sample wrap_48512 = wrap(delta_48511, (-0.5), ((t_sample)0.5));
			t_sample gen_48513 = wrap_48512;
			t_sample mul_48508 = (gen_48513 * ((int)4));
			t_sample add_48506 = (mul_48508 + m_history_5);
			t_sample sub_48484 = (add_48506 - mul_48486);
			t_sample round_48495 = (trunc((sub_48484 * ((t_sample)0.25))) * ((int)4));
			t_sample add_48485 = (round_48495 + mul_48486);
			t_sample sub_48515 = (m_history_6 - ((t_sample)0.25));
			t_sample add_48516 = (m_history_6 + ((t_sample)0.25));
			t_sample div_48514 = safediv(sub_48515, add_48516);
			t_sample abs_48479 = fabs(div_48514);
			int gt_48480 = (abs_48479 > ((t_sample)0.015625));
			int and_48483 = (gt_48480 && ((int)1));
			t_sample switch_48487 = (and_48483 ? and_48483 : m_history_7);
			t_sample switch_48490 = (gen_48505 ? switch_48487 : ((int)0));
			t_sample gen_48493 = switch_48490;
			t_sample switch_48489 = (switch_48490 ? ((int)0) : switch_48487);
			t_sample history_48491_next_48492 = fixdenorm(switch_48489);
			int or_48482 = (gen_48493 || ((int)0));
			t_sample switch_48510 = (or_48482 ? add_48485 : add_48506);
			t_sample wrap_48507 = wrap(switch_48510, ((int)0), ((int)1));
			t_sample gen_48519 = wrap_48507;
			t_sample history_48509_next_48518 = fixdenorm(wrap_48507);
			t_sample sub_48597 = (gen_48519 - m_history_4);
			t_sample add_48592 = (gen_48519 + m_history_4);
			t_sample div_48596 = safediv(sub_48597, add_48592);
			t_sample abs_48595 = fabs(div_48596);
			int gt_48594 = (abs_48595 > ((t_sample)0.5));
			int change_48600 = __m_change_22(gt_48594);
			int gt_48598 = (change_48600 > ((int)0));
			int gen_48532 = gt_48598;
			t_sample history_48499_next_48599 = fixdenorm(gen_48519);
			int gt_48528 = (gen_48532 > ((int)0));
			t_sample switch_48529 = (gt_48528 ? ((int)1) : ((t_sample)0.001));
			t_sample mix_50821 = (m_history_3 + (switch_48529 * (gen_48532 - m_history_3)));
			t_sample mix_48530 = mix_50821;
			t_sample mix_50822 = (mix_48530 + (((t_sample)0.95) * (m_history_2 - mix_48530)));
			t_sample mix_48526 = mix_50822;
			t_sample noise_48524 = noise();
			t_sample mul_48522 = (mix_48526 * noise_48524);
			t_sample mix_50823 = (mul_48522 + (((t_sample)0.99) * (m_history_1 - mul_48522)));
			t_sample mix_48525 = mix_50823;
			t_sample sub_48520 = (mul_48522 - mix_48525);
			t_sample mul_48521 = (sub_48520 * ((t_sample)0.1));
			t_sample history_48531_next_48533 = fixdenorm(mix_48530);
			t_sample history_48527_next_48534 = fixdenorm(mix_48526);
			t_sample history_48523_next_48535 = fixdenorm(mix_48525);
			t_sample out1 = ((mul_48521 + mul_48537) + mul_48568);
			m_history_16 = history_48499_next_48504;
			m_history_14 = history_48560_next_48570;
			m_history_15 = history_48564_next_48569;
			m_history_13 = history_48499_next_48577;
			m_history_9 = history_48539_next_48556;
			m_history_10 = history_48543_next_48555;
			m_history_11 = history_48547_next_48554;
			m_history_12 = history_48551_next_48553;
			m_history_8 = history_48499_next_48589;
			m_history_5 = history_48509_next_48518;
			m_history_6 = history_48481_next_48517;
			m_history_7 = history_48491_next_48492;
			m_history_4 = history_48499_next_48599;
			m_history_1 = history_48523_next_48535;
			m_history_2 = history_48527_next_48534;
			m_history_3 = history_48531_next_48533;
			// assign results to output buffer;
			(*(__out1++)) = out1;
			
		};
		return __exception;
		
	};
	
} State;


///
///	Configuration for the genlib API
///

/// Number of signal inputs and outputs

int gen_kernel_numins = 2;
int gen_kernel_numouts = 1;

int num_inputs() { return gen_kernel_numins; }
int num_outputs() { return gen_kernel_numouts; }
int num_params() { return 0; }

/// Assistive lables for the signal inputs and outputs

const char *gen_kernel_innames[] = { "beat", "measure" };
const char *gen_kernel_outnames[] = { "out1" };

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
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		
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
	self->__commonstate.params = 0;
	self->__commonstate.numparams = 0;
	
	return self;
}

/// Release all resources and memory used by a State object:

void destroy(CommonState *cself) {
	State *self = (State *)cself;
	
	delete self;
}


} // backbeat::
