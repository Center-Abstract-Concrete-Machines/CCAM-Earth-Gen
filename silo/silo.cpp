#include "silo.h"

namespace silo {

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
	Change __m_change_52;
	Change __m_change_51;
	Data m_hy_13;
	Data m_fqs_33;
	Data m_hy_12;
	Data m_amps_29;
	Delay m_delay_9;
	Delay m_delay_10;
	Delay m_delay_8;
	Delay m_delay_7;
	Delay m_delay_5;
	Delay m_delay_4;
	Delay m_delay_6;
	Delay m_delay_11;
	Phasor __m_phasor_34;
	int __exception;
	int vectorsize;
	int __loopcount;
	t_sample m_sw_28;
	t_sample m_knob6_bandwidth_27;
	t_sample m_cvin1_LFO_26;
	t_sample m_sw_25;
	t_sample samples_to_seconds;
	t_sample m_sw_31;
	t_sample m_sw_30;
	t_sample m_gate_32;
	t_sample m_sw_24;
	t_sample m_sw_18;
	t_sample m_knob4_quantize_22;
	t_sample m_history_3;
	t_sample m_history_14;
	t_sample m_history_2;
	t_sample samplerate;
	t_sample m_numVoices_1;
	t_sample m_knob1_gateInput_23;
	t_sample m_history_15;
	t_sample m_knob3_LFOSpeed_17;
	t_sample m_sw_21;
	t_sample m_history_16;
	t_sample m_knob5_MIDIoffset_20;
	t_sample m_sw_19;
	t_sample elapsed;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_numVoices_1 = ((int)0);
		m_history_2 = ((int)0);
		m_history_3 = ((int)0);
		m_delay_4.reset("m_delay_4", ((int)5419));
		m_delay_5.reset("m_delay_5", ((int)3469));
		m_delay_6.reset("m_delay_6", ((int)7351));
		m_delay_7.reset("m_delay_7", ((int)5167));
		m_delay_8.reset("m_delay_8", ((int)4447));
		m_delay_9.reset("m_delay_9", ((int)2791));
		m_delay_10.reset("m_delay_10", ((int)8269));
		m_delay_11.reset("m_delay_11", ((int)3571));
		m_hy_12.reset("hy2", ((int)8), ((int)1));
		m_hy_13.reset("hy1", ((int)8), ((int)1));
		m_history_14 = ((int)0);
		m_history_15 = ((int)0);
		m_history_16 = ((int)0);
		m_knob3_LFOSpeed_17 = ((int)0);
		m_sw_18 = ((int)0);
		m_sw_19 = ((int)0);
		m_knob5_MIDIoffset_20 = ((int)0);
		m_sw_21 = ((int)0);
		m_knob4_quantize_22 = ((int)0);
		m_knob1_gateInput_23 = ((int)0);
		m_sw_24 = ((int)0);
		m_sw_25 = ((int)0);
		m_cvin1_LFO_26 = ((int)0);
		m_knob6_bandwidth_27 = ((int)0);
		m_sw_28 = ((int)0);
		m_amps_29.reset("amps", ((int)8), ((int)1));
		m_sw_30 = ((int)0);
		m_sw_31 = ((int)0);
		m_gate_32 = ((int)0);
		m_fqs_33.reset("fqs", ((int)32), ((int)1));
		samples_to_seconds = (1 / samplerate);
		__m_phasor_34.reset(0);
		__m_change_51.reset(0);
		__m_change_52.reset(0);
		elapsed = 0;
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
		__loopcount = (__n * GENLIB_LOOPCOUNT_BAIL);
		int amps_dim = m_amps_29.dim;
		int amps_channels = m_amps_29.channels;
		t_sample floor_23122 = floor(m_knob4_quantize_22);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample out12 = ((int)0);
			if ((((int)0) != 0)) {
				__m_phasor_34.phase = 0;
				
			};
			t_sample phasor_9534 = __m_phasor_34(m_knob3_LFOSpeed_17, samples_to_seconds);
			t_sample s = ((phasor_9534 * ((int)2)) - ((int)1));
			// for loop initializer;
			int i = ((int)0);
			// for loop condition;
			// abort processing if an infinite loop is suspected;
			if (((__loopcount--) <= 0)) {
				__exception = GENLIB_ERR_LOOP_OVERFLOW;
				break ;
				
			};
			while ((i < m_numVoices_1)) {
				// abort processing if an infinite loop is suspected;
				if (((__loopcount--) <= 0)) {
					__exception = GENLIB_ERR_LOOP_OVERFLOW;
					break ;
					
				};
				t_sample m_sin_36 = go_unit_sine_d(s);
				int amps_dim = m_amps_29.dim;
				int amps_channels = m_amps_29.channels;
				bool index_ignore_37 = ((i >= amps_dim) || (i < 0));
				if ((!index_ignore_37)) {
					m_amps_29.write(m_sin_36, i, 0);
					
				};
				s = (s + ((t_sample)0.125));
				s = wrap(s, ((int)0), ((int)1));
				// for loop increment;
				i = (i + ((int)1));
				
			};
			// samples amps channel 1;
			int chan_38 = ((int)0);
			bool chan_ignore_39 = ((chan_38 < 0) || (chan_38 >= amps_channels));
			t_sample expr_27448 = (chan_ignore_39 ? 0 : m_amps_29.read(0, chan_38));
			t_sample out11 = expr_27448;
			bool index_ignore_40 = (((int)5) >= amps_dim);
			// samples amps channel 1;
			int chan_41 = ((int)0);
			bool chan_ignore_42 = ((chan_41 < 0) || (chan_41 >= amps_channels));
			t_sample sample_amps_9501 = ((chan_ignore_42 || index_ignore_40) ? 0 : m_amps_29.read(((int)5), chan_41));
			t_sample index_amps_9502 = ((int)5);
			t_sample out8 = sample_amps_9501;
			bool index_ignore_43 = (((int)4) >= amps_dim);
			// samples amps channel 1;
			int chan_44 = ((int)0);
			bool chan_ignore_45 = ((chan_44 < 0) || (chan_44 >= amps_channels));
			t_sample sample_amps_9504 = ((chan_ignore_45 || index_ignore_43) ? 0 : m_amps_29.read(((int)4), chan_44));
			t_sample index_amps_9505 = ((int)4);
			t_sample out7 = sample_amps_9504;
			bool index_ignore_46 = (((int)6) >= amps_dim);
			// samples amps channel 1;
			int chan_47 = ((int)0);
			bool chan_ignore_48 = ((chan_47 < 0) || (chan_47 >= amps_channels));
			t_sample sample_amps_9498 = ((chan_ignore_48 || index_ignore_46) ? 0 : m_amps_29.read(((int)6), chan_47));
			t_sample index_amps_9499 = ((int)6);
			t_sample out9 = sample_amps_9498;
			// samples amps channel 1;
			int chan_49 = ((int)0);
			bool chan_ignore_50 = ((chan_49 < 0) || (chan_49 >= amps_channels));
			t_sample sample_amps_9516 = (chan_ignore_50 ? 0 : m_amps_29.read(0, chan_49));
			t_sample index_amps_9517 = ((int)0);
			t_sample out3 = sample_amps_9516;
			t_sample mix_27529 = (m_history_16 + (((t_sample)0.0042742627044161) * (m_knob5_MIDIoffset_20 - m_history_16)));
			t_sample mix_653 = mix_27529;
			t_sample mix_27530 = (m_history_15 + (((t_sample)0.0042742627044161) * (mix_653 - m_history_15)));
			t_sample mix_651 = mix_27530;
			t_sample mix_27531 = (m_history_14 + (((t_sample)0.0042742627044161) * (mix_651 - m_history_14)));
			t_sample mix_649 = mix_27531;
			t_sample gen_13321 = mix_649;
			t_sample history_654_next_656 = fixdenorm(mix_653);
			t_sample history_652_next_657 = fixdenorm(mix_651);
			t_sample history_650_next_658 = fixdenorm(mix_649);
			t_sample floor_9525 = floor(gen_13321);
			int newNote = (__m_change_51(floor_9525) || __m_change_52(floor_23122));
			if (((elapsed == ((int)0)) || (newNote != ((int)1)))) {
				// for loop initializer;
				int index = ((int)0);
				// for loop condition;
				while ((index < m_numVoices_1)) {
					// abort processing if an infinite loop is suspected;
					if (((__loopcount--) <= 0)) {
						__exception = GENLIB_ERR_LOOP_OVERFLOW;
						break ;
						
					};
					t_sample midi = floor(((go_quantize_d_d_i_i_i_i(safediv(index, m_numVoices_1), floor_23122, ((int)12), ((int)0), ((int)0), ((int)0)) * ((int)12)) + floor_9525));
					t_sample f = mtof(midi, ((int)440));
					int fqs_dim = m_fqs_33.dim;
					int fqs_channels = m_fqs_33.channels;
					bool index_ignore_53 = ((index >= fqs_dim) || (index < 0));
					if ((!index_ignore_53)) {
						m_fqs_33.write(f, index, 0);
						
					};
					// for loop increment;
					index = (index + ((int)1));
					
				};
				
			};
			bool index_ignore_54 = (((int)3) >= amps_dim);
			// samples amps channel 1;
			int chan_55 = ((int)0);
			bool chan_ignore_56 = ((chan_55 < 0) || (chan_55 >= amps_channels));
			t_sample sample_amps_9507 = ((chan_ignore_56 || index_ignore_54) ? 0 : m_amps_29.read(((int)3), chan_55));
			t_sample index_amps_9508 = ((int)3);
			t_sample out6 = sample_amps_9507;
			bool index_ignore_57 = (((int)2) >= amps_dim);
			// samples amps channel 1;
			int chan_58 = ((int)0);
			bool chan_ignore_59 = ((chan_58 < 0) || (chan_58 >= amps_channels));
			t_sample sample_amps_9510 = ((chan_ignore_59 || index_ignore_57) ? 0 : m_amps_29.read(((int)2), chan_58));
			t_sample index_amps_9511 = ((int)2);
			t_sample out5 = sample_amps_9510;
			bool index_ignore_60 = (((int)1) >= amps_dim);
			// samples amps channel 1;
			int chan_61 = ((int)0);
			bool chan_ignore_62 = ((chan_61 < 0) || (chan_61 >= amps_channels));
			t_sample sample_amps_9513 = ((chan_ignore_62 || index_ignore_60) ? 0 : m_amps_29.read(((int)1), chan_61));
			t_sample index_amps_9514 = ((int)1);
			t_sample out4 = sample_amps_9513;
			bool index_ignore_63 = (((int)7) >= amps_dim);
			// samples amps channel 1;
			int chan_64 = ((int)0);
			bool chan_ignore_65 = ((chan_64 < 0) || (chan_64 >= amps_channels));
			t_sample sample_amps_9495 = ((chan_ignore_65 || index_ignore_63) ? 0 : m_amps_29.read(((int)7), chan_64));
			t_sample index_amps_9496 = ((int)7);
			t_sample out10 = sample_amps_9495;
			t_sample mix_27532 = (((int)0) + (m_knob1_gateInput_23 * (in1 - ((int)0))));
			t_sample mix_24254 = mix_27532;
			t_sample mix_27533 = (((int)0) + (m_knob1_gateInput_23 * (in2 - ((int)0))));
			t_sample mix_24255 = mix_27533;
			t_sample bw_rps = safediv((fabs(m_knob6_bandwidth_27) * ((t_sample)6.2831853071796)), samplerate);
			t_sample sum = ((int)0);
			// for loop initializer;
			int i_27466 = ((int)0);
			// for loop condition;
			while ((i_27466 < m_numVoices_1)) {
				// abort processing if an infinite loop is suspected;
				if (((__loopcount--) <= 0)) {
					__exception = GENLIB_ERR_LOOP_OVERFLOW;
					break ;
					
				};
				int hy2_dim = m_hy_12.dim;
				int hy2_channels = m_hy_12.channels;
				bool index_ignore_66 = ((i_27466 >= hy2_dim) || (i_27466 < 0));
				// samples hy2 channel 1;
				int chan_67 = ((int)0);
				bool chan_ignore_68 = ((chan_67 < 0) || (chan_67 >= hy2_channels));
				t_sample y2 = ((chan_ignore_68 || index_ignore_66) ? 0 : m_hy_12.read(i_27466, chan_67));
				int hy1_dim = m_hy_13.dim;
				int hy1_channels = m_hy_13.channels;
				bool index_ignore_69 = ((i_27466 >= hy1_dim) || (i_27466 < 0));
				// samples hy1 channel 1;
				int chan_70 = ((int)0);
				bool chan_ignore_71 = ((chan_70 < 0) || (chan_70 >= hy1_channels));
				t_sample y1 = ((chan_ignore_71 || index_ignore_69) ? 0 : m_hy_13.read(i_27466, chan_70));
				int fqs_dim = m_fqs_33.dim;
				int fqs_channels = m_fqs_33.channels;
				bool index_ignore_72 = ((i_27466 >= fqs_dim) || (i_27466 < 0));
				// samples fqs channel 1;
				int chan_73 = ((int)0);
				bool chan_ignore_74 = ((chan_73 < 0) || (chan_73 >= fqs_channels));
				t_sample freq = ((chan_ignore_74 || index_ignore_72) ? 0 : m_fqs_33.read(i_27466, chan_73));
				bool index_ignore_75 = ((i_27466 >= amps_dim) || (i_27466 < 0));
				// samples amps channel 1;
				int chan_76 = ((int)0);
				bool chan_ignore_77 = ((chan_76 < 0) || (chan_76 >= amps_channels));
				t_sample amp = ((chan_ignore_77 || index_ignore_75) ? 0 : m_amps_29.read(i_27466, chan_76));
				t_sample freq_rps = safediv((freq * ((t_sample)6.2831853071796)), samplerate);
				t_sample b = ((((int)2) * cos(freq_rps)) * exp((bw_rps * ((t_sample)-0.5))));
				t_sample c = (-exp((-bw_rps)));
				t_sample a = (((int)1) - (c + b));
				t_sample y = (((a * (mix_24255 + mix_24254)) + (b * y1)) + (c * y2));
				bool index_ignore_78 = ((i_27466 >= hy2_dim) || (i_27466 < 0));
				if ((!index_ignore_78)) {
					m_hy_12.write(y1, i_27466, 0);
					
				};
				bool index_ignore_79 = ((i_27466 >= hy1_dim) || (i_27466 < 0));
				if ((!index_ignore_79)) {
					m_hy_13.write(y, i_27466, 0);
					
				};
				sum = (sum + (y * amp));
				// for loop increment;
				i_27466 = (i_27466 + ((int)1));
				
			};
			t_sample expr_27465 = (sum * ((t_sample)0.35355339059327));
			t_sample mul_9535 = (expr_27465 * ((t_sample)0.4));
			t_sample tap_527 = m_delay_11.read_step(((int)3571));
			t_sample tap_554 = m_delay_10.read_step(((int)8269));
			t_sample tap_545 = m_delay_9.read_step(((int)2791));
			t_sample mul_525 = (tap_527 * ((t_sample)0.5));
			t_sample tap_572 = m_delay_8.read_step(((int)4447));
			t_sample mul_552 = (tap_554 * ((t_sample)0.5));
			t_sample mix_27534 = (mul_9535 + (((t_sample)0.8) * (m_history_3 - mul_9535)));
			t_sample mix_547 = mix_27534;
			t_sample add_524 = (mix_547 + mul_525);
			t_sample mul_523 = (add_524 * ((t_sample)0.5));
			t_sample sub_522 = (tap_527 - mul_523);
			t_sample gen_9537 = sub_522;
			t_sample mix_27535 = (mul_9535 + (((t_sample)0.8) * (m_history_2 - mul_9535)));
			t_sample mix_574 = mix_27535;
			t_sample add_551 = (mix_574 + mul_552);
			t_sample mul_550 = (add_551 * ((t_sample)0.5));
			t_sample sub_549 = (tap_554 - mul_550);
			t_sample gen_9536 = sub_549;
			t_sample tap_539 = m_delay_7.read_step(((int)5167));
			t_sample mul_543 = (tap_545 * ((t_sample)0.5));
			t_sample add_542 = (add_524 + mul_543);
			t_sample mul_541 = (add_542 * ((t_sample)0.5));
			t_sample sub_540 = (tap_545 - mul_541);
			t_sample tap_566 = m_delay_6.read_step(((int)7351));
			t_sample mul_570 = (tap_572 * ((t_sample)0.5));
			t_sample add_569 = (add_551 + mul_570);
			t_sample mul_568 = (add_569 * ((t_sample)0.5));
			t_sample sub_567 = (tap_572 - mul_568);
			t_sample tap_533 = m_delay_5.read_step(((int)3469));
			t_sample mul_537 = (tap_539 * ((t_sample)0.5));
			t_sample add_536 = (add_542 + mul_537);
			t_sample mul_535 = (add_536 * ((t_sample)0.5));
			t_sample sub_534 = (tap_539 - mul_535);
			t_sample tap_560 = m_delay_4.read_step(((int)5419));
			t_sample mul_564 = (tap_566 * ((t_sample)0.5));
			t_sample add_563 = (add_569 + mul_564);
			t_sample mul_562 = (add_563 * ((t_sample)0.5));
			t_sample sub_561 = (tap_566 - mul_562);
			t_sample mul_531 = (tap_533 * ((t_sample)0.5));
			t_sample add_530 = (add_536 + mul_531);
			t_sample mul_529 = (add_530 * ((t_sample)0.5));
			t_sample sub_528 = (tap_533 - mul_529);
			t_sample mul_558 = (tap_560 * ((t_sample)0.5));
			t_sample add_557 = (add_563 + mul_558);
			t_sample mul_556 = (add_557 * ((t_sample)0.5));
			t_sample sub_555 = (tap_560 - mul_556);
			t_sample history_546_next_575 = fixdenorm(sub_522);
			t_sample history_573_next_576 = fixdenorm(sub_549);
			t_sample out2 = gen_9537;
			t_sample out1 = gen_9536;
			t_sample numVoices_next_27467 = fixdenorm(((int)8));
			m_history_16 = history_654_next_656;
			m_history_14 = history_650_next_658;
			m_history_15 = history_652_next_657;
			m_delay_11.write(sub_540);
			m_history_2 = history_573_next_576;
			m_history_3 = history_546_next_575;
			m_delay_4.write(add_557);
			m_delay_5.write(add_530);
			m_delay_6.write(sub_555);
			m_delay_7.write(sub_528);
			m_delay_8.write(sub_561);
			m_delay_9.write(sub_534);
			m_delay_10.write(sub_567);
			m_numVoices_1 = numVoices_next_27467;
			m_delay_4.step();
			m_delay_5.step();
			m_delay_6.step();
			m_delay_7.step();
			m_delay_8.step();
			m_delay_9.step();
			m_delay_10.step();
			m_delay_11.step();
			(elapsed++);
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
	inline void set_hy2(void * _value) {
		m_hy_12.setbuffer(_value);
	};
	inline void set_hy1(void * _value) {
		m_hy_13.setbuffer(_value);
	};
	inline void set_knob3_LFOSpeed(t_param _value) {
		m_knob3_LFOSpeed_17 = (_value < 1e-05 ? 1e-05 : (_value > 6 ? 6 : _value));
	};
	inline void set_sw7(t_param _value) {
		m_sw_18 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw2(t_param _value) {
		m_sw_19 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5_MIDIoffset(t_param _value) {
		m_knob5_MIDIoffset_20 = (_value < 32 ? 32 : (_value > 103 ? 103 : _value));
	};
	inline void set_sw8(t_param _value) {
		m_sw_21 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_quantize(t_param _value) {
		m_knob4_quantize_22 = (_value < 1 ? 1 : (_value > 8 ? 8 : _value));
	};
	inline void set_knob1_gateInput(t_param _value) {
		m_knob1_gateInput_23 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw6(t_param _value) {
		m_sw_24 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw5(t_param _value) {
		m_sw_25 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_cvin1_LFO(t_param _value) {
		m_cvin1_LFO_26 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6_bandwidth(t_param _value) {
		m_knob6_bandwidth_27 = (_value < 1 ? 1 : (_value > 100 ? 100 : _value));
	};
	inline void set_sw3(t_param _value) {
		m_sw_28 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_amps(void * _value) {
		m_amps_29.setbuffer(_value);
	};
	inline void set_sw1(t_param _value) {
		m_sw_30 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw4(t_param _value) {
		m_sw_31 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_gate1(t_param _value) {
		m_gate_32 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_fqs(void * _value) {
		m_fqs_33.setbuffer(_value);
	};
	inline t_sample go_unit_sine_d(t_sample arg_27446) {
		t_sample mul_27445 = (arg_27446 * ((t_sample)3.1415926535898));
		t_sample cos_27444 = cos(mul_27445);
		int irange_27526 = ((-1) - ((int)1));
		int orange_27527 = (((int)1) - ((int)0));
		t_sample sub_27528 = (cos_27444 - ((int)1));
		t_sample scale_27525 = ((safepow(safediv(sub_27528, irange_27526), ((int)1)) * orange_27527) + ((int)0));
		return scale_27525;
		
	};
	inline t_sample go_quantize_d_d_i_i_i_i(t_sample arg_27458, t_sample arg_27459, int arg_27460, int arg_27461, int inversion, int transposition) {
		t_sample min_27457 = ((arg_27459 < ((int)1)) ? ((int)1) : arg_27459);
		t_sample mul_27456 = (arg_27458 * min_27457);
		t_sample add_27455 = (mul_27456 + inversion);
		t_sample round_27450 = (round((add_27455 * ((t_sample)1))) * ((int)1));
		t_sample div_27454 = safediv(round_27450, min_27457);
		t_sample mul_27453 = (div_27454 * arg_27460);
		t_sample add_27452 = (mul_27453 + arg_27461);
		t_sample round_27449 = (round((add_27452 * ((t_sample)1))) * ((int)1));
		t_sample div_27451 = safediv(round_27449, inversion);
		return div_27451;
		
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
int num_params() { return 19; }

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
		case 0: self->set_amps(ref); break;
		case 1: self->set_cvin1_LFO(value); break;
		case 2: self->set_fqs(ref); break;
		case 3: self->set_gate1(value); break;
		case 4: self->set_hy1(ref); break;
		case 5: self->set_hy2(ref); break;
		case 6: self->set_knob1_gateInput(value); break;
		case 7: self->set_knob3_LFOSpeed(value); break;
		case 8: self->set_knob4_quantize(value); break;
		case 9: self->set_knob5_MIDIoffset(value); break;
		case 10: self->set_knob6_bandwidth(value); break;
		case 11: self->set_sw1(value); break;
		case 12: self->set_sw2(value); break;
		case 13: self->set_sw3(value); break;
		case 14: self->set_sw4(value); break;
		case 15: self->set_sw5(value); break;
		case 16: self->set_sw6(value); break;
		case 17: self->set_sw7(value); break;
		case 18: self->set_sw8(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		
		case 1: *value = self->m_cvin1_LFO_26; break;
		
		case 3: *value = self->m_gate_32; break;
		
		
		case 6: *value = self->m_knob1_gateInput_23; break;
		case 7: *value = self->m_knob3_LFOSpeed_17; break;
		case 8: *value = self->m_knob4_quantize_22; break;
		case 9: *value = self->m_knob5_MIDIoffset_20; break;
		case 10: *value = self->m_knob6_bandwidth_27; break;
		case 11: *value = self->m_sw_30; break;
		case 12: *value = self->m_sw_19; break;
		case 13: *value = self->m_sw_28; break;
		case 14: *value = self->m_sw_31; break;
		case 15: *value = self->m_sw_25; break;
		case 16: *value = self->m_sw_24; break;
		case 17: *value = self->m_sw_18; break;
		case 18: *value = self->m_sw_21; break;
		
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
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(19 * sizeof(ParamInfo));
	self->__commonstate.numparams = 19;
	// initialize parameter 0 ("m_amps_29")
	pi = self->__commonstate.params + 0;
	pi->name = "amps";
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
	// initialize parameter 1 ("m_cvin1_LFO_26")
	pi = self->__commonstate.params + 1;
	pi->name = "cvin1_LFO";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_cvin1_LFO_26;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_fqs_33")
	pi = self->__commonstate.params + 2;
	pi->name = "fqs";
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
	// initialize parameter 3 ("m_gate_32")
	pi = self->__commonstate.params + 3;
	pi->name = "gate1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_gate_32;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_hy_13")
	pi = self->__commonstate.params + 4;
	pi->name = "hy1";
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
	// initialize parameter 5 ("m_hy_12")
	pi = self->__commonstate.params + 5;
	pi->name = "hy2";
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
	// initialize parameter 6 ("m_knob1_gateInput_23")
	pi = self->__commonstate.params + 6;
	pi->name = "knob1_gateInput";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob1_gateInput_23;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 7 ("m_knob3_LFOSpeed_17")
	pi = self->__commonstate.params + 7;
	pi->name = "knob3_LFOSpeed";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_LFOSpeed_17;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1e-05;
	pi->outputmax = 6;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 8 ("m_knob4_quantize_22")
	pi = self->__commonstate.params + 8;
	pi->name = "knob4_quantize";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_quantize_22;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1;
	pi->outputmax = 8;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 9 ("m_knob5_MIDIoffset_20")
	pi = self->__commonstate.params + 9;
	pi->name = "knob5_MIDIoffset";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_MIDIoffset_20;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 32;
	pi->outputmax = 103;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 10 ("m_knob6_bandwidth_27")
	pi = self->__commonstate.params + 10;
	pi->name = "knob6_bandwidth";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_bandwidth_27;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1;
	pi->outputmax = 100;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 11 ("m_sw_30")
	pi = self->__commonstate.params + 11;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_30;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 12 ("m_sw_19")
	pi = self->__commonstate.params + 12;
	pi->name = "sw2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_19;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 13 ("m_sw_28")
	pi = self->__commonstate.params + 13;
	pi->name = "sw3";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_28;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 14 ("m_sw_31")
	pi = self->__commonstate.params + 14;
	pi->name = "sw4";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_31;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 15 ("m_sw_25")
	pi = self->__commonstate.params + 15;
	pi->name = "sw5";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_25;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 16 ("m_sw_24")
	pi = self->__commonstate.params + 16;
	pi->name = "sw6";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_24;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 17 ("m_sw_18")
	pi = self->__commonstate.params + 17;
	pi->name = "sw7";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_18;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 18 ("m_sw_21")
	pi = self->__commonstate.params + 18;
	pi->name = "sw8";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_21;
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


} // silo::
