#include "sequencer.h"

namespace sequencer {

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
	Change __m_change_33;
	Change __m_change_26;
	Change __m_change_25;
	Change __m_change_24;
	Change __m_change_28;
	Change __m_change_32;
	Delta __m_delta_29;
	PlusEquals __m_pluseq_34;
	int __exception;
	int vectorsize;
	t_sample m_maj_23;
	t_sample m_cvin_7;
	t_sample m_knob_4;
	t_sample m_sixth_22;
	t_sample m_history_21;
	t_sample m_history_20;
	t_sample m_knob_3;
	t_sample __m_latch_27;
	t_sample m_knob_2;
	t_sample samplerate;
	t_sample m_cvin_1;
	t_sample m_knob_6;
	t_sample m_history_19;
	t_sample m_history_17;
	t_sample m_knob_10;
	t_sample m_knob_11;
	t_sample m_cvin_9;
	t_sample m_knob_8;
	t_sample m_history_18;
	t_sample m_gate_12;
	t_sample m_gate_14;
	t_sample m_cvin_13;
	t_sample m_history_16;
	t_sample m_knob_5;
	t_sample m_gatein_15;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_cvin_1 = ((int)0);
		m_knob_2 = ((int)0);
		m_knob_3 = ((int)0);
		m_knob_4 = ((int)1);
		m_knob_5 = ((int)0);
		m_knob_6 = ((int)1);
		m_cvin_7 = ((int)0);
		m_knob_8 = ((int)1);
		m_cvin_9 = ((int)0);
		m_knob_10 = ((int)1);
		m_knob_11 = ((int)0);
		m_gate_12 = ((int)0);
		m_cvin_13 = ((int)0);
		m_gate_14 = ((int)0);
		m_gatein_15 = ((int)0);
		m_history_16 = ((int)0);
		m_history_17 = ((int)0);
		m_history_18 = ((int)0);
		m_history_19 = ((int)0);
		m_history_20 = ((int)0);
		m_history_21 = ((int)0);
		m_sixth_22 = ((int)0);
		m_maj_23 = ((int)0);
		__m_change_24.reset(0);
		__m_change_25.reset(0);
		__m_change_26.reset(0);
		__m_latch_27 = 11025;
		__m_change_28.reset(0);
		__m_delta_29.reset(0);
		__m_change_32.reset(0);
		__m_change_33.reset(0);
		__m_pluseq_34.reset(0);
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
		t_sample * __out13 = __outs[12];
		t_sample * __out14 = __outs[13];
		if (__exception) {
			return __exception;
			
		} else if (( (__in1 == 0) || (__in2 == 0) || (__out1 == 0) || (__out2 == 0) || (__out3 == 0) || (__out4 == 0) || (__out5 == 0) || (__out6 == 0) || (__out7 == 0) || (__out8 == 0) || (__out9 == 0) || (__out10 == 0) || (__out11 == 0) || (__out12 == 0) || (__out13 == 0) || (__out14 == 0) )) {
			__exception = GENLIB_ERR_NULL_BUFFER;
			return __exception;
			
		};
		int int_2234 = int(m_gate_12);
		int int_2379 = int(m_gatein_15);
		t_sample history_2286_next_2322 = fixdenorm(((int)8));
		t_sample mstosamps_2273 = (((int)0) * (samplerate * 0.001));
		t_sample max_2274 = ((mstosamps_2273 < vectorsize) ? vectorsize : mstosamps_2273);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample out2 = ((int)0);
			t_sample out1 = ((int)0);
			int change_2235 = __m_change_24(int_2234);
			int eqp_2236 = ((int_2234 == change_2235) ? int_2234 : 0);
			int gen_2237 = eqp_2236;
			int change_2378 = __m_change_25(int_2379);
			int eqp_2380 = ((int_2379 == change_2378) ? int_2379 : 0);
			int gen_2249 = eqp_2380;
			int gt_2258 = (gen_2249 > ((int)0));
			int change_2257 = __m_change_26(gt_2258);
			int gt_2256 = (change_2257 > ((int)0));
			int gen_2259 = gt_2256;
			t_sample add_2264 = (m_history_16 + ((int)1));
			t_sample switch_2261 = (gen_2259 ? ((int)0) : add_2264);
			__m_latch_27 = ((gen_2259 != 0) ? add_2264 : __m_latch_27);
			t_sample latch_2263 = __m_latch_27;
			t_sample gen_2266 = latch_2263;
			t_sample history_2262_next_2265 = fixdenorm(switch_2261);
			t_sample rdiv_2253 = safediv(((int)1), gen_2266);
			t_sample add_2255 = (m_history_17 + rdiv_2253);
			t_sample switch_2252 = (gen_2259 ? ((int)0) : add_2255);
			t_sample wrap_2254 = wrap(switch_2252, ((int)0), ((int)1));
			t_sample gen_2374 = wrap_2254;
			t_sample history_2251_next_2267 = fixdenorm(wrap_2254);
			t_sample mul_2291 = (gen_2374 * ((t_sample)0.125));
			t_sample sub_2307 = (gen_2374 - m_history_18);
			t_sample add_2308 = (gen_2374 + m_history_18);
			t_sample div_2306 = safediv(sub_2307, add_2308);
			t_sample abs_2305 = fabs(div_2306);
			int gt_2303 = (abs_2305 > ((t_sample)0.5));
			int change_2302 = __m_change_28(gt_2303);
			int gt_2301 = (change_2302 > ((int)0));
			int gen_2310 = gt_2301;
			t_sample history_2304_next_2309 = fixdenorm(gen_2374);
			t_sample delta_2316 = __m_delta_29(gen_2374);
			t_sample wrap_2317 = wrap(delta_2316, (-0.5), ((t_sample)0.5));
			t_sample gen_2318 = wrap_2317;
			t_sample mul_2313 = (gen_2318 * ((t_sample)0.125));
			t_sample add_2311 = (mul_2313 + m_history_21);
			t_sample sub_2289 = (add_2311 - mul_2291);
			t_sample round_2300 = (trunc((sub_2289 * ((t_sample)8))) * ((t_sample)0.125));
			t_sample add_2290 = (round_2300 + mul_2291);
			t_sample sub_2320 = (m_history_20 - ((int)8));
			t_sample add_2321 = (m_history_20 + ((int)8));
			t_sample div_2319 = safediv(sub_2320, add_2321);
			t_sample abs_2284 = fabs(div_2319);
			int gt_2285 = (abs_2284 > ((t_sample)0.015625));
			int and_2288 = (gt_2285 && ((int)1));
			t_sample switch_2292 = (and_2288 ? and_2288 : m_history_19);
			t_sample switch_2295 = (gen_2310 ? switch_2292 : ((int)0));
			t_sample gen_2298 = switch_2295;
			t_sample switch_2294 = (switch_2295 ? ((int)0) : switch_2292);
			t_sample history_2296_next_2297 = fixdenorm(switch_2294);
			int or_2287 = (gen_2298 || gen_2237);
			t_sample switch_2315 = (or_2287 ? add_2290 : add_2311);
			t_sample wrap_2312 = wrap(switch_2315, ((int)0), ((int)1));
			t_sample gen_2324 = wrap_2312;
			t_sample history_2314_next_2323 = fixdenorm(wrap_2312);
			t_sample mul_2240 = (gen_2324 * ((int)8));
			t_sample floor_2239 = floor(mul_2240);
			t_sample add_2220 = (floor_2239 + ((int)1));
			t_sample choice_30 = int(add_2220);
			t_sample gate_2226 = (((choice_30 >= 1) && (choice_30 < 2)) ? ((int)1) : 0);
			t_sample gate_2227 = (((choice_30 >= 2) && (choice_30 < 3)) ? ((int)1) : 0);
			t_sample gate_2228 = (((choice_30 >= 3) && (choice_30 < 4)) ? ((int)1) : 0);
			t_sample gate_2229 = (((choice_30 >= 4) && (choice_30 < 5)) ? ((int)1) : 0);
			t_sample gate_2230 = (((choice_30 >= 5) && (choice_30 < 6)) ? ((int)1) : 0);
			t_sample gate_2231 = (((choice_30 >= 6) && (choice_30 < 7)) ? ((int)1) : 0);
			t_sample gate_2232 = (((choice_30 >= 7) && (choice_30 < 8)) ? ((int)1) : 0);
			t_sample gate_2233 = ((choice_30 >= 8) ? ((int)1) : 0);
			t_sample out10 = gate_2233;
			t_sample out5 = gate_2228;
			t_sample out7 = gate_2230;
			t_sample out8 = gate_2231;
			t_sample out9 = gate_2232;
			t_sample out3 = gate_2226;
			t_sample out6 = gate_2229;
			t_sample out4 = gate_2227;
			t_sample choice_31 = int(add_2220);
			t_sample selector_2241 = ((choice_31 >= 8) ? m_knob_8 : ((choice_31 >= 7) ? m_knob_10 : ((choice_31 >= 6) ? m_knob_4 : ((choice_31 >= 5) ? m_knob_6 : ((choice_31 >= 4) ? m_knob_5 : ((choice_31 >= 3) ? m_knob_2 : ((choice_31 >= 2) ? m_knob_3 : ((choice_31 >= 1) ? m_knob_11 : 0))))))));
			int expr_2247 = ((int)0);
			t_sample mul_2245 = (selector_2241 * ((int)8));
			t_sample floor_2244 = floor(mul_2245);
			if ((floor_2244 == ((int)0))) {
				expr_2247 = ((int)0);
				
			} else {
				if ((floor_2244 == ((int)1))) {
					expr_2247 = ((int)2);
					
				} else {
					if ((floor_2244 == ((int)2))) {
						expr_2247 = ((int)3);
						
					} else {
						if ((floor_2244 == ((int)3))) {
							expr_2247 = ((int)5);
							
						} else {
							if ((floor_2244 == ((int)4))) {
								expr_2247 = ((int)7);
								
							} else {
								if ((floor_2244 == ((int)5))) {
									expr_2247 = ((int)9);
									
								} else {
									if ((floor_2244 == ((int)6))) {
										expr_2247 = ((int)10);
										
									} else {
										if ((floor_2244 == ((int)7))) {
											expr_2247 = ((int)12);
											
										};
										
									};
									
								};
								
							};
							
						};
						
					};
					
				};
				
			};
			t_sample div_2243 = (expr_2247 * ((t_sample)0.083333333333333));
			t_sample div_2242 = (div_2243 * ((t_sample)0.2));
			t_sample out14 = div_2242;
			t_sample out13 = div_2242;
			t_sample add_2222 = (add_2220 + ((int)1));
			int change_2282 = __m_change_32(add_2222);
			int neq_2281 = (change_2282 != ((int)0));
			int gt_2279 = (neq_2281 > ((int)0));
			int change_2278 = __m_change_33(gt_2279);
			int gt_2277 = (change_2278 > ((int)0));
			int plusequals_2276 = __m_pluseq_34.post(((int)1), gt_2277, 0);
			int lte_2275 = (plusequals_2276 <= max_2274);
			t_sample out12 = lte_2275;
			t_sample out11 = lte_2275;
			m_history_16 = history_2262_next_2265;
			m_history_19 = history_2296_next_2297;
			m_history_20 = history_2286_next_2322;
			m_history_21 = history_2314_next_2323;
			m_history_18 = history_2304_next_2309;
			m_history_17 = history_2251_next_2267;
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
			(*(__out14++)) = out14;
			
		};
		return __exception;
		
	};
	inline void set_cvin3(t_param _value) {
		m_cvin_1 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3(t_param _value) {
		m_knob_2 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob2(t_param _value) {
		m_knob_3 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6(t_param _value) {
		m_knob_4 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4(t_param _value) {
		m_knob_5 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5(t_param _value) {
		m_knob_6 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_cvin2(t_param _value) {
		m_cvin_7 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob8(t_param _value) {
		m_knob_8 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_cvin4(t_param _value) {
		m_cvin_9 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob7(t_param _value) {
		m_knob_10 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob1(t_param _value) {
		m_knob_11 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_gate2(t_param _value) {
		m_gate_12 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_cvin1(t_param _value) {
		m_cvin_13 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_gate1(t_param _value) {
		m_gate_14 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_gatein1(t_param _value) {
		m_gatein_15 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	
} State;


///
///	Configuration for the genlib API
///

/// Number of signal inputs and outputs

int gen_kernel_numins = 2;
int gen_kernel_numouts = 14;

int num_inputs() { return gen_kernel_numins; }
int num_outputs() { return gen_kernel_numouts; }
int num_params() { return 15; }

/// Assistive lables for the signal inputs and outputs

const char *gen_kernel_innames[] = { "in1", "in2" };
const char *gen_kernel_outnames[] = { "out1", "out2", "led1", "led2", "led3", "led4", "led5", "led6", "led7", "led8", "gateout1", "gateout2", "cvout1", "cvout2" };

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
		case 0: self->set_cvin1(value); break;
		case 1: self->set_cvin2(value); break;
		case 2: self->set_cvin3(value); break;
		case 3: self->set_cvin4(value); break;
		case 4: self->set_gate1(value); break;
		case 5: self->set_gate2(value); break;
		case 6: self->set_gatein1(value); break;
		case 7: self->set_knob1(value); break;
		case 8: self->set_knob2(value); break;
		case 9: self->set_knob3(value); break;
		case 10: self->set_knob4(value); break;
		case 11: self->set_knob5(value); break;
		case 12: self->set_knob6(value); break;
		case 13: self->set_knob7(value); break;
		case 14: self->set_knob8(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_cvin_13; break;
		case 1: *value = self->m_cvin_7; break;
		case 2: *value = self->m_cvin_1; break;
		case 3: *value = self->m_cvin_9; break;
		case 4: *value = self->m_gate_14; break;
		case 5: *value = self->m_gate_12; break;
		case 6: *value = self->m_gatein_15; break;
		case 7: *value = self->m_knob_11; break;
		case 8: *value = self->m_knob_3; break;
		case 9: *value = self->m_knob_2; break;
		case 10: *value = self->m_knob_5; break;
		case 11: *value = self->m_knob_6; break;
		case 12: *value = self->m_knob_4; break;
		case 13: *value = self->m_knob_10; break;
		case 14: *value = self->m_knob_8; break;
		
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
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(15 * sizeof(ParamInfo));
	self->__commonstate.numparams = 15;
	// initialize parameter 0 ("m_cvin_13")
	pi = self->__commonstate.params + 0;
	pi->name = "cvin1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_cvin_13;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_cvin_7")
	pi = self->__commonstate.params + 1;
	pi->name = "cvin2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_cvin_7;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_cvin_1")
	pi = self->__commonstate.params + 2;
	pi->name = "cvin3";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_cvin_1;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_cvin_9")
	pi = self->__commonstate.params + 3;
	pi->name = "cvin4";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_cvin_9;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_gate_14")
	pi = self->__commonstate.params + 4;
	pi->name = "gate1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_gate_14;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_gate_12")
	pi = self->__commonstate.params + 5;
	pi->name = "gate2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_gate_12;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_gatein_15")
	pi = self->__commonstate.params + 6;
	pi->name = "gatein1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_gatein_15;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 7 ("m_knob_11")
	pi = self->__commonstate.params + 7;
	pi->name = "knob1";
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
	// initialize parameter 8 ("m_knob_3")
	pi = self->__commonstate.params + 8;
	pi->name = "knob2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob_3;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 9 ("m_knob_2")
	pi = self->__commonstate.params + 9;
	pi->name = "knob3";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob_2;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 10 ("m_knob_5")
	pi = self->__commonstate.params + 10;
	pi->name = "knob4";
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
	// initialize parameter 11 ("m_knob_6")
	pi = self->__commonstate.params + 11;
	pi->name = "knob5";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob_6;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 12 ("m_knob_4")
	pi = self->__commonstate.params + 12;
	pi->name = "knob6";
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
	// initialize parameter 13 ("m_knob_10")
	pi = self->__commonstate.params + 13;
	pi->name = "knob7";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob_10;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 14 ("m_knob_8")
	pi = self->__commonstate.params + 14;
	pi->name = "knob8";
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
	
	return self;
}

/// Release all resources and memory used by a State object:

void destroy(CommonState *cself) {
	State *self = (State *)cself;
	genlib_sysmem_freeptr(cself->params);
		
	delete self;
}


} // sequencer::
