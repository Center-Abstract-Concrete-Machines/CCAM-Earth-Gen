#include "cv_out.h"

namespace cv_out {

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
	Phasor __m_phasor_21;
	Phasor __m_phasor_17;
	Phasor __m_phasor_18;
	Phasor __m_phasor_20;
	int __exception;
	int vectorsize;
	t_sample m_sw_3;
	t_sample m_sw_15;
	t_sample m_gatein_14;
	t_sample m_sw_13;
	t_sample m_sw_16;
	t_sample samplerate;
	t_sample samples_to_seconds;
	t_sample m_gatein_2;
	t_sample m_sw_12;
	t_sample m_knob_10;
	t_sample m_knob_5;
	t_sample m_knob_4;
	t_sample m_knob_11;
	t_sample m_sw_6;
	t_sample m_knob_8;
	t_sample m_sw_7;
	t_sample m_sw_1;
	t_sample m_knob_9;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_sw_1 = ((int)0);
		m_gatein_2 = ((int)0);
		m_sw_3 = ((int)0);
		m_knob_4 = ((int)0);
		m_knob_5 = ((int)0);
		m_sw_6 = ((int)0);
		m_sw_7 = ((int)0);
		m_knob_8 = ((int)1);
		m_knob_9 = ((int)0);
		m_knob_10 = ((int)0);
		m_knob_11 = ((int)1);
		m_sw_12 = ((int)0);
		m_sw_13 = ((int)0);
		m_gatein_14 = ((int)0);
		m_sw_15 = ((int)0);
		m_sw_16 = ((int)0);
		samples_to_seconds = (1 / samplerate);
		__m_phasor_17.reset(0);
		__m_phasor_18.reset(0);
		__m_phasor_20.reset(0);
		__m_phasor_21.reset(0);
		genlib_reset_complete(this);
		
	};
	// the signal processing routine;
	inline int perform(t_sample ** __ins, t_sample ** __outs, int __n) {
		vectorsize = __n;
		const t_sample * __in1 = __ins[0];
		const t_sample * __in2 = __ins[1];
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
		if (__exception) {
			return __exception;
			
		} else if (( (__in1 == 0) || (__in2 == 0) || (__out1 == 0) || (__out2 == 0) || (__out3 == 0) || (__out4 == 0) || (__out5 == 0) || (__out6 == 0) || (__out7 == 0) || (__out8 == 0) || (__out9 == 0) || (__out10 == 0) || (__out11 == 0) || (__out12 == 0) )) {
			__exception = GENLIB_ERR_NULL_BUFFER;
			return __exception;
			
		};
		samples_to_seconds = (1 / samplerate);
		t_sample choice_19 = int(m_gatein_2);
		t_sample choice_22 = int(m_gatein_14);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample out3 = ((int)0);
			t_sample out8 = ((int)0);
			t_sample out5 = ((int)0);
			t_sample out4 = ((int)0);
			t_sample out9 = ((int)0);
			t_sample out10 = ((int)0);
			t_sample out6 = ((int)0);
			t_sample out7 = ((int)0);
			t_sample phasor_6073 = __m_phasor_17(((t_sample)0.5), samples_to_seconds);
			int lt_6016 = (phasor_6073 < ((t_sample)0.5));
			t_sample out12 = lt_6016;
			t_sample phasor_6020 = __m_phasor_18(((int)440), samples_to_seconds);
			t_sample gate_6023 = ((choice_19 >= 1) ? phasor_6020 : 0);
			t_sample out2 = gate_6023;
			t_sample phasor_6012 = __m_phasor_20(((t_sample)0.1), samples_to_seconds);
			int gt_6017 = (phasor_6012 > ((t_sample)0.5));
			t_sample out11 = gt_6017;
			t_sample phasor_6018 = __m_phasor_21(((int)220), samples_to_seconds);
			t_sample gate_6021 = ((choice_22 >= 1) ? phasor_6018 : 0);
			t_sample out1 = gate_6021;
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
			
		};
		return __exception;
		
	};
	inline void set_sw4(t_param _value) {
		m_sw_1 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_gatein2(t_param _value) {
		m_gatein_2 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw2(t_param _value) {
		m_sw_3 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob2(t_param _value) {
		m_knob_4 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob1(t_param _value) {
		m_knob_5 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw3(t_param _value) {
		m_sw_6 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw7(t_param _value) {
		m_sw_7 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6(t_param _value) {
		m_knob_8 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3(t_param _value) {
		m_knob_9 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4(t_param _value) {
		m_knob_10 = (_value < 1 ? 1 : (_value > 0 ? 0 : _value));
	};
	inline void set_knob5(t_param _value) {
		m_knob_11 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw8(t_param _value) {
		m_sw_12 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw6(t_param _value) {
		m_sw_13 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_gatein1(t_param _value) {
		m_gatein_14 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw5(t_param _value) {
		m_sw_15 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_16 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	
} State;


///
///	Configuration for the genlib API
///

/// Number of signal inputs and outputs

int gen_kernel_numins = 2;
int gen_kernel_numouts = 12;

int num_inputs() { return gen_kernel_numins; }
int num_outputs() { return gen_kernel_numouts; }
int num_params() { return 16; }

/// Assistive lables for the signal inputs and outputs

const char *gen_kernel_innames[] = { "in1", "in2" };
const char *gen_kernel_outnames[] = { "out1", "out2", "led1", "led2", "led3", "led4", "led5", "led6", "led7", "led8", "cvout1", "cvout2" };

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
		case 0: self->set_gatein1(value); break;
		case 1: self->set_gatein2(value); break;
		case 2: self->set_knob1(value); break;
		case 3: self->set_knob2(value); break;
		case 4: self->set_knob3(value); break;
		case 5: self->set_knob4(value); break;
		case 6: self->set_knob5(value); break;
		case 7: self->set_knob6(value); break;
		case 8: self->set_sw1(value); break;
		case 9: self->set_sw2(value); break;
		case 10: self->set_sw3(value); break;
		case 11: self->set_sw4(value); break;
		case 12: self->set_sw5(value); break;
		case 13: self->set_sw6(value); break;
		case 14: self->set_sw7(value); break;
		case 15: self->set_sw8(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_gatein_14; break;
		case 1: *value = self->m_gatein_2; break;
		case 2: *value = self->m_knob_5; break;
		case 3: *value = self->m_knob_4; break;
		case 4: *value = self->m_knob_9; break;
		case 5: *value = self->m_knob_10; break;
		case 6: *value = self->m_knob_11; break;
		case 7: *value = self->m_knob_8; break;
		case 8: *value = self->m_sw_16; break;
		case 9: *value = self->m_sw_3; break;
		case 10: *value = self->m_sw_6; break;
		case 11: *value = self->m_sw_1; break;
		case 12: *value = self->m_sw_15; break;
		case 13: *value = self->m_sw_13; break;
		case 14: *value = self->m_sw_7; break;
		case 15: *value = self->m_sw_12; break;
		
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
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(16 * sizeof(ParamInfo));
	self->__commonstate.numparams = 16;
	// initialize parameter 0 ("m_gatein_14")
	pi = self->__commonstate.params + 0;
	pi->name = "gatein1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_gatein_14;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_gatein_2")
	pi = self->__commonstate.params + 1;
	pi->name = "gatein2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_gatein_2;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_knob_5")
	pi = self->__commonstate.params + 2;
	pi->name = "knob1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob_5;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_knob_4")
	pi = self->__commonstate.params + 3;
	pi->name = "knob2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob_4;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_knob_9")
	pi = self->__commonstate.params + 4;
	pi->name = "knob3";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob_9;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_knob_10")
	pi = self->__commonstate.params + 5;
	pi->name = "knob4";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob_10;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1;
	pi->outputmax = 0;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_knob_11")
	pi = self->__commonstate.params + 6;
	pi->name = "knob5";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob_11;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 7 ("m_knob_8")
	pi = self->__commonstate.params + 7;
	pi->name = "knob6";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob_8;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 8 ("m_sw_16")
	pi = self->__commonstate.params + 8;
	pi->name = "sw1";
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
	// initialize parameter 9 ("m_sw_3")
	pi = self->__commonstate.params + 9;
	pi->name = "sw2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_3;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 10 ("m_sw_6")
	pi = self->__commonstate.params + 10;
	pi->name = "sw3";
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
	// initialize parameter 11 ("m_sw_1")
	pi = self->__commonstate.params + 11;
	pi->name = "sw4";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_1;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 12 ("m_sw_15")
	pi = self->__commonstate.params + 12;
	pi->name = "sw5";
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
	// initialize parameter 13 ("m_sw_13")
	pi = self->__commonstate.params + 13;
	pi->name = "sw6";
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
	// initialize parameter 14 ("m_sw_7")
	pi = self->__commonstate.params + 14;
	pi->name = "sw7";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_7;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 15 ("m_sw_12")
	pi = self->__commonstate.params + 15;
	pi->name = "sw8";
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
	
	return self;
}

/// Release all resources and memory used by a State object:

void destroy(CommonState *cself) {
	State *self = (State *)cself;
	genlib_sysmem_freeptr(cself->params);
		
	delete self;
}


} // cv_out::
