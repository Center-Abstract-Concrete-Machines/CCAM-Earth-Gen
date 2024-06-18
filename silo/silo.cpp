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
	Change __m_change_39;
	Change __m_change_40;
	Data m_hy_12;
	Data m_hy_13;
	Data m_amps_28;
	Data m_fqs_25;
	Data m_randomDeviations_35;
	Delay m_delay_11;
	Delay m_delay_9;
	Delay m_delay_10;
	Delay m_delay_8;
	Delay m_delay_5;
	Delay m_delay_6;
	Delay m_delay_7;
	Delay m_delay_4;
	int __exception;
	int __loopcount;
	int vectorsize;
	t_sample m_history_15;
	t_sample m_gate_30;
	t_sample m_sw_29;
	t_sample m_knob1_gateInput_31;
	t_sample m_knob6_bandwidth_32;
	t_sample m_sw_33;
	t_sample m_sw_34;
	t_sample m_history_2;
	t_sample samplerate;
	t_sample m_numVoices_1;
	t_sample m_history_14;
	t_sample m_knob4_quantize_27;
	t_sample m_history_3;
	t_sample elapsed;
	t_sample m_sw_19;
	t_sample m_sw_17;
	t_sample m_history_16;
	t_sample m_knob2_LFO_deviation_26;
	t_sample m_knob5_MIDIoffset_20;
	t_sample m_knob3_LFOSpeed_22;
	t_sample m_cvin1_LFO_21;
	t_sample m_sw_24;
	t_sample m_sw_23;
	t_sample m_sw_18;
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
		m_sw_17 = ((int)0);
		m_sw_18 = ((int)0);
		m_sw_19 = ((int)0);
		m_knob5_MIDIoffset_20 = ((int)0);
		m_cvin1_LFO_21 = ((int)0);
		m_knob3_LFOSpeed_22 = ((int)0);
		m_sw_23 = ((int)0);
		m_sw_24 = ((int)0);
		m_fqs_25.reset("fqs", ((int)32), ((int)1));
		m_knob2_LFO_deviation_26 = ((int)0);
		m_knob4_quantize_27 = ((int)0);
		m_amps_28.reset("amps", ((int)8), ((int)1));
		m_sw_29 = ((int)0);
		m_gate_30 = ((int)0);
		m_knob1_gateInput_31 = ((int)0);
		m_knob6_bandwidth_32 = ((int)0);
		m_sw_33 = ((int)0);
		m_sw_34 = ((int)0);
		m_randomDeviations_35.reset("randomDeviations", ((int)8), ((int)1));
		__m_change_39.reset(0);
		__m_change_40.reset(0);
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
		const t_sample in2 = __in2[0];
		t_sample floor_76 = floor(m_knob4_quantize_27);
		int amps_dim = m_amps_28.dim;
		int amps_channels = m_amps_28.channels;
		__loopcount = (__n * GENLIB_LOOPCOUNT_BAIL);
		t_sample mul_364 = (in2 * m_knob1_gateInput_31);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample out12 = ((int)0);
			bool index_ignore_36 = (((int)6) >= amps_dim);
			// samples amps channel 1;
			int chan_37 = ((int)0);
			bool chan_ignore_38 = ((chan_37 < 0) || (chan_37 >= amps_channels));
			t_sample sample_amps_98 = ((chan_ignore_38 || index_ignore_36) ? 0 : m_amps_28.read(((int)6), chan_37));
			t_sample index_amps_99 = ((int)6);
			t_sample out9 = sample_amps_98;
			t_sample mix_785 = (m_history_16 + (((t_sample)0.0042742627044161) * (m_knob5_MIDIoffset_20 - m_history_16)));
			t_sample mix_83 = mix_785;
			t_sample mix_786 = (m_history_15 + (((t_sample)0.0042742627044161) * (mix_83 - m_history_15)));
			t_sample mix_81 = mix_786;
			t_sample mix_787 = (m_history_14 + (((t_sample)0.0042742627044161) * (mix_81 - m_history_14)));
			t_sample mix_79 = mix_787;
			t_sample gen_274 = mix_79;
			t_sample history_84_next_90 = fixdenorm(mix_83);
			t_sample history_82_next_91 = fixdenorm(mix_81);
			t_sample history_80_next_92 = fixdenorm(mix_79);
			t_sample floor_167 = floor(gen_274);
			int newNote = (__m_change_39(floor_167) || __m_change_40(floor_76));
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
					t_sample midi = floor(((go_quantize_d_d_i_i_i_i(safediv(index, m_numVoices_1), floor_76, ((int)12), ((int)0), ((int)0), ((int)0)) * ((int)12)) + floor_167));
					t_sample f = mtof(midi, ((int)440));
					int fqs_dim = m_fqs_25.dim;
					int fqs_channels = m_fqs_25.channels;
					bool index_ignore_41 = ((index >= fqs_dim) || (index < 0));
					if ((!index_ignore_41)) {
						m_fqs_25.write(f, index, 0);
						
					};
					// for loop increment;
					index = (index + ((int)1));
					
				};
				
			};
			// abort processing if an infinite loop is suspected;
			if (((__loopcount--) <= 0)) {
				__exception = GENLIB_ERR_LOOP_OVERFLOW;
				break ;
				
			};
			bool index_ignore_42 = (((int)4) >= amps_dim);
			// samples amps channel 1;
			int chan_43 = ((int)0);
			bool chan_ignore_44 = ((chan_43 < 0) || (chan_43 >= amps_channels));
			t_sample sample_amps_104 = ((chan_ignore_44 || index_ignore_42) ? 0 : m_amps_28.read(((int)4), chan_43));
			t_sample index_amps_105 = ((int)4);
			t_sample out7 = sample_amps_104;
			bool index_ignore_45 = (((int)3) >= amps_dim);
			// samples amps channel 1;
			int chan_46 = ((int)0);
			bool chan_ignore_47 = ((chan_46 < 0) || (chan_46 >= amps_channels));
			t_sample sample_amps_107 = ((chan_ignore_47 || index_ignore_45) ? 0 : m_amps_28.read(((int)3), chan_46));
			t_sample index_amps_108 = ((int)3);
			t_sample out6 = sample_amps_107;
			bool index_ignore_48 = (((int)2) >= amps_dim);
			// samples amps channel 1;
			int chan_49 = ((int)0);
			bool chan_ignore_50 = ((chan_49 < 0) || (chan_49 >= amps_channels));
			t_sample sample_amps_110 = ((chan_ignore_50 || index_ignore_48) ? 0 : m_amps_28.read(((int)2), chan_49));
			t_sample index_amps_111 = ((int)2);
			t_sample out5 = sample_amps_110;
			t_sample mul_363 = (in1 * m_knob1_gateInput_31);
			t_sample bw_rps = ((fabs(m_knob6_bandwidth_32) * ((t_sample)6.2831853071796)) * ((t_sample)2.2675736961451e-05));
			t_sample sum = ((int)0);
			// for loop initializer;
			int i = ((int)0);
			// for loop condition;
			while ((i < m_numVoices_1)) {
				// abort processing if an infinite loop is suspected;
				if (((__loopcount--) <= 0)) {
					__exception = GENLIB_ERR_LOOP_OVERFLOW;
					break ;
					
				};
				int hy2_dim = m_hy_12.dim;
				int hy2_channels = m_hy_12.channels;
				bool index_ignore_51 = ((i >= hy2_dim) || (i < 0));
				// samples hy2 channel 1;
				int chan_52 = ((int)0);
				bool chan_ignore_53 = ((chan_52 < 0) || (chan_52 >= hy2_channels));
				t_sample y2 = ((chan_ignore_53 || index_ignore_51) ? 0 : m_hy_12.read(i, chan_52));
				int hy1_dim = m_hy_13.dim;
				int hy1_channels = m_hy_13.channels;
				bool index_ignore_54 = ((i >= hy1_dim) || (i < 0));
				// samples hy1 channel 1;
				int chan_55 = ((int)0);
				bool chan_ignore_56 = ((chan_55 < 0) || (chan_55 >= hy1_channels));
				t_sample y1 = ((chan_ignore_56 || index_ignore_54) ? 0 : m_hy_13.read(i, chan_55));
				int fqs_dim = m_fqs_25.dim;
				int fqs_channels = m_fqs_25.channels;
				bool index_ignore_57 = ((i >= fqs_dim) || (i < 0));
				// samples fqs channel 1;
				int chan_58 = ((int)0);
				bool chan_ignore_59 = ((chan_58 < 0) || (chan_58 >= fqs_channels));
				t_sample freq = ((chan_ignore_59 || index_ignore_57) ? 0 : m_fqs_25.read(i, chan_58));
				bool index_ignore_60 = ((i >= amps_dim) || (i < 0));
				// samples amps channel 1;
				int chan_61 = ((int)0);
				bool chan_ignore_62 = ((chan_61 < 0) || (chan_61 >= amps_channels));
				t_sample amp = ((chan_ignore_62 || index_ignore_60) ? 0 : m_amps_28.read(i, chan_61));
				t_sample freq_rps = ((freq * ((t_sample)6.2831853071796)) * ((t_sample)2.2675736961451e-05));
				t_sample b = ((((int)2) * cos(freq_rps)) * exp((bw_rps * ((t_sample)-0.5))));
				t_sample c = (-exp((-bw_rps)));
				t_sample a = (((int)1) - (c + b));
				t_sample y = (((a * (mul_364 + mul_363)) + (b * y1)) + (c * y2));
				bool index_ignore_63 = ((i >= hy2_dim) || (i < 0));
				if ((!index_ignore_63)) {
					m_hy_12.write(y1, i, 0);
					
				};
				bool index_ignore_64 = ((i >= hy1_dim) || (i < 0));
				if ((!index_ignore_64)) {
					m_hy_13.write(y, i, 0);
					
				};
				sum = (sum + (y * amp));
				// for loop increment;
				i = (i + ((int)1));
				
			};
			t_sample expr_767 = (sum * ((t_sample)0.35355339059327));
			bool index_ignore_65 = (((int)7) >= amps_dim);
			// samples amps channel 1;
			int chan_66 = ((int)0);
			bool chan_ignore_67 = ((chan_66 < 0) || (chan_66 >= amps_channels));
			t_sample sample_amps_95 = ((chan_ignore_67 || index_ignore_65) ? 0 : m_amps_28.read(((int)7), chan_66));
			t_sample index_amps_96 = ((int)7);
			t_sample out10 = sample_amps_95;
			bool index_ignore_68 = (((int)5) >= amps_dim);
			// samples amps channel 1;
			int chan_69 = ((int)0);
			bool chan_ignore_70 = ((chan_69 < 0) || (chan_69 >= amps_channels));
			t_sample sample_amps_101 = ((chan_ignore_70 || index_ignore_68) ? 0 : m_amps_28.read(((int)5), chan_69));
			t_sample index_amps_102 = ((int)5);
			t_sample out8 = sample_amps_101;
			t_sample mul_173 = (expr_767 * ((t_sample)0.4));
			t_sample tap_180 = m_delay_11.read_step(((int)3571));
			t_sample tap_207 = m_delay_10.read_step(((int)8269));
			t_sample tap_198 = m_delay_9.read_step(((int)2791));
			t_sample mul_178 = (tap_180 * ((t_sample)0.5));
			t_sample tap_225 = m_delay_8.read_step(((int)4447));
			t_sample mul_205 = (tap_207 * ((t_sample)0.5));
			t_sample mix_788 = (mul_173 + (((t_sample)0.8) * (m_history_3 - mul_173)));
			t_sample mix_200 = mix_788;
			t_sample add_177 = (mix_200 + mul_178);
			t_sample mul_176 = (add_177 * ((t_sample)0.5));
			t_sample sub_175 = (tap_180 - mul_176);
			t_sample gen_243 = sub_175;
			t_sample mix_789 = (mul_173 + (((t_sample)0.8) * (m_history_2 - mul_173)));
			t_sample mix_227 = mix_789;
			t_sample add_204 = (mix_227 + mul_205);
			t_sample mul_203 = (add_204 * ((t_sample)0.5));
			t_sample sub_202 = (tap_207 - mul_203);
			t_sample gen_242 = sub_202;
			t_sample tap_192 = m_delay_7.read_step(((int)5167));
			t_sample mul_196 = (tap_198 * ((t_sample)0.5));
			t_sample add_195 = (add_177 + mul_196);
			t_sample mul_194 = (add_195 * ((t_sample)0.5));
			t_sample sub_193 = (tap_198 - mul_194);
			t_sample tap_219 = m_delay_6.read_step(((int)7351));
			t_sample mul_223 = (tap_225 * ((t_sample)0.5));
			t_sample add_222 = (add_204 + mul_223);
			t_sample mul_221 = (add_222 * ((t_sample)0.5));
			t_sample sub_220 = (tap_225 - mul_221);
			t_sample tap_186 = m_delay_5.read_step(((int)3469));
			t_sample mul_190 = (tap_192 * ((t_sample)0.5));
			t_sample add_189 = (add_195 + mul_190);
			t_sample mul_188 = (add_189 * ((t_sample)0.5));
			t_sample sub_187 = (tap_192 - mul_188);
			t_sample tap_213 = m_delay_4.read_step(((int)5419));
			t_sample mul_217 = (tap_219 * ((t_sample)0.5));
			t_sample add_216 = (add_222 + mul_217);
			t_sample mul_215 = (add_216 * ((t_sample)0.5));
			t_sample sub_214 = (tap_219 - mul_215);
			t_sample mul_184 = (tap_186 * ((t_sample)0.5));
			t_sample add_183 = (add_189 + mul_184);
			t_sample mul_182 = (add_183 * ((t_sample)0.5));
			t_sample sub_181 = (tap_186 - mul_182);
			t_sample mul_211 = (tap_213 * ((t_sample)0.5));
			t_sample add_210 = (add_216 + mul_211);
			t_sample mul_209 = (add_210 * ((t_sample)0.5));
			t_sample sub_208 = (tap_213 - mul_209);
			t_sample history_199_next_240 = fixdenorm(sub_175);
			t_sample history_226_next_241 = fixdenorm(sub_202);
			t_sample out1 = gen_242;
			t_sample out2 = gen_243;
			t_sample out11 = ((int)0);
			// samples amps channel 1;
			int chan_71 = ((int)0);
			bool chan_ignore_72 = ((chan_71 < 0) || (chan_71 >= amps_channels));
			t_sample sample_amps_116 = (chan_ignore_72 ? 0 : m_amps_28.read(0, chan_71));
			t_sample index_amps_117 = ((int)0);
			t_sample out3 = sample_amps_116;
			bool index_ignore_73 = (((int)1) >= amps_dim);
			// samples amps channel 1;
			int chan_74 = ((int)0);
			bool chan_ignore_75 = ((chan_74 < 0) || (chan_74 >= amps_channels));
			t_sample sample_amps_113 = ((chan_ignore_75 || index_ignore_73) ? 0 : m_amps_28.read(((int)1), chan_74));
			t_sample index_amps_114 = ((int)1);
			t_sample out4 = sample_amps_113;
			t_sample numVoices_next_784 = fixdenorm(((int)8));
			m_history_16 = history_84_next_90;
			m_history_14 = history_80_next_92;
			m_history_15 = history_82_next_91;
			m_delay_11.write(sub_193);
			m_history_2 = history_226_next_241;
			m_history_3 = history_199_next_240;
			m_delay_4.write(add_210);
			m_delay_5.write(add_183);
			m_delay_6.write(sub_208);
			m_delay_7.write(sub_181);
			m_delay_8.write(sub_214);
			m_delay_9.write(sub_187);
			m_delay_10.write(sub_220);
			m_numVoices_1 = numVoices_next_784;
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
	inline void set_numVoices(t_param _value) {
		m_numVoices_1 = _value;
	};
	inline void set_history_226(t_param _value) {
		m_history_2 = _value;
	};
	inline void set_history_199(t_param _value) {
		m_history_3 = _value;
	};
	inline void set_hy2(void * _value) {
		m_hy_12.setbuffer(_value);
	};
	inline void set_hy1(void * _value) {
		m_hy_13.setbuffer(_value);
	};
	inline void set_history_80(t_param _value) {
		m_history_14 = _value;
	};
	inline void set_history_82(t_param _value) {
		m_history_15 = _value;
	};
	inline void set_history_84(t_param _value) {
		m_history_16 = _value;
	};
	inline void set_sw7(t_param _value) {
		m_sw_17 = _value;
	};
	inline void set_sw5(t_param _value) {
		m_sw_18 = _value;
	};
	inline void set_sw3(t_param _value) {
		m_sw_19 = _value;
	};
	inline void set_knob5_MIDIoffset(t_param _value) {
		m_knob5_MIDIoffset_20 = (_value < 32 ? 32 : (_value > 103 ? 103 : _value));
	};
	inline void set_cvin1_LFO(t_param _value) {
		m_cvin1_LFO_21 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_LFOSpeed(t_param _value) {
		m_knob3_LFOSpeed_22 = (_value < 1e-05 ? 1e-05 : (_value > 6 ? 6 : _value));
	};
	inline void set_sw2(t_param _value) {
		m_sw_23 = _value;
	};
	inline void set_sw1(t_param _value) {
		m_sw_24 = _value;
	};
	inline void set_fqs(void * _value) {
		m_fqs_25.setbuffer(_value);
	};
	inline void set_knob2_LFO_deviation(t_param _value) {
		m_knob2_LFO_deviation_26 = _value;
	};
	inline void set_knob4_quantize(t_param _value) {
		m_knob4_quantize_27 = (_value < 1 ? 1 : (_value > 8 ? 8 : _value));
	};
	inline void set_amps(void * _value) {
		m_amps_28.setbuffer(_value);
	};
	inline void set_sw8(t_param _value) {
		m_sw_29 = _value;
	};
	inline void set_gate1(t_param _value) {
		m_gate_30 = _value;
	};
	inline void set_knob1_gateInput(t_param _value) {
		m_knob1_gateInput_31 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6_bandwidth(t_param _value) {
		m_knob6_bandwidth_32 = (_value < 1 ? 1 : (_value > 100 ? 100 : _value));
	};
	inline void set_sw6(t_param _value) {
		m_sw_33 = _value;
	};
	inline void set_sw4(t_param _value) {
		m_sw_34 = _value;
	};
	inline void set_randomDeviations(void * _value) {
		m_randomDeviations_35.setbuffer(_value);
	};
	inline t_sample go_quantize_d_d_i_i_i_i(t_sample arg_778, t_sample arg_779, int arg_780, int arg_781, int inversion, int transposition) {
		t_sample min_777 = ((arg_779 < ((int)1)) ? ((int)1) : arg_779);
		t_sample mul_776 = (arg_778 * min_777);
		t_sample add_775 = (mul_776 + inversion);
		t_sample round_770 = (round((add_775 * ((t_sample)1))) * ((int)1));
		t_sample div_774 = safediv(round_770, min_777);
		t_sample mul_773 = (div_774 * arg_780);
		t_sample add_772 = (mul_773 + arg_781);
		t_sample round_769 = (round((add_772 * ((t_sample)1))) * ((int)1));
		t_sample div_771 = safediv(round_769, inversion);
		return div_771;
		
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
int num_params() { return 27; }

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
		case 4: self->set_history_199(value); break;
		case 5: self->set_history_226(value); break;
		case 6: self->set_history_80(value); break;
		case 7: self->set_history_82(value); break;
		case 8: self->set_history_84(value); break;
		case 9: self->set_hy1(ref); break;
		case 10: self->set_hy2(ref); break;
		case 11: self->set_knob1_gateInput(value); break;
		case 12: self->set_knob2_LFO_deviation(value); break;
		case 13: self->set_knob3_LFOSpeed(value); break;
		case 14: self->set_knob4_quantize(value); break;
		case 15: self->set_knob5_MIDIoffset(value); break;
		case 16: self->set_knob6_bandwidth(value); break;
		case 17: self->set_numVoices(value); break;
		case 18: self->set_randomDeviations(ref); break;
		case 19: self->set_sw1(value); break;
		case 20: self->set_sw2(value); break;
		case 21: self->set_sw3(value); break;
		case 22: self->set_sw4(value); break;
		case 23: self->set_sw5(value); break;
		case 24: self->set_sw6(value); break;
		case 25: self->set_sw7(value); break;
		case 26: self->set_sw8(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		
		case 1: *value = self->m_cvin1_LFO_21; break;
		
		case 3: *value = self->m_gate_30; break;
		case 4: *value = self->m_history_3; break;
		case 5: *value = self->m_history_2; break;
		case 6: *value = self->m_history_14; break;
		case 7: *value = self->m_history_15; break;
		case 8: *value = self->m_history_16; break;
		
		
		case 11: *value = self->m_knob1_gateInput_31; break;
		case 12: *value = self->m_knob2_LFO_deviation_26; break;
		case 13: *value = self->m_knob3_LFOSpeed_22; break;
		case 14: *value = self->m_knob4_quantize_27; break;
		case 15: *value = self->m_knob5_MIDIoffset_20; break;
		case 16: *value = self->m_knob6_bandwidth_32; break;
		case 17: *value = self->m_numVoices_1; break;
		
		case 19: *value = self->m_sw_24; break;
		case 20: *value = self->m_sw_23; break;
		case 21: *value = self->m_sw_19; break;
		case 22: *value = self->m_sw_34; break;
		case 23: *value = self->m_sw_18; break;
		case 24: *value = self->m_sw_33; break;
		case 25: *value = self->m_sw_17; break;
		case 26: *value = self->m_sw_29; break;
		
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
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(27 * sizeof(ParamInfo));
	self->__commonstate.numparams = 27;
	// initialize parameter 0 ("m_amps_28")
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
	// initialize parameter 1 ("m_cvin1_LFO_21")
	pi = self->__commonstate.params + 1;
	pi->name = "cvin1_LFO";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_cvin1_LFO_21;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_fqs_25")
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
	// initialize parameter 3 ("m_gate_30")
	pi = self->__commonstate.params + 3;
	pi->name = "gate1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_gate_30;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_history_3")
	pi = self->__commonstate.params + 4;
	pi->name = "history_199";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_history_3;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_history_2")
	pi = self->__commonstate.params + 5;
	pi->name = "history_226";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_history_2;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_history_14")
	pi = self->__commonstate.params + 6;
	pi->name = "history_80";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_history_14;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 7 ("m_history_15")
	pi = self->__commonstate.params + 7;
	pi->name = "history_82";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_history_15;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 8 ("m_history_16")
	pi = self->__commonstate.params + 8;
	pi->name = "history_84";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_history_16;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 9 ("m_hy_13")
	pi = self->__commonstate.params + 9;
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
	// initialize parameter 10 ("m_hy_12")
	pi = self->__commonstate.params + 10;
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
	// initialize parameter 11 ("m_knob1_gateInput_31")
	pi = self->__commonstate.params + 11;
	pi->name = "knob1_gateInput";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob1_gateInput_31;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 12 ("m_knob2_LFO_deviation_26")
	pi = self->__commonstate.params + 12;
	pi->name = "knob2_LFO_deviation";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob2_LFO_deviation_26;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 13 ("m_knob3_LFOSpeed_22")
	pi = self->__commonstate.params + 13;
	pi->name = "knob3_LFOSpeed";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_LFOSpeed_22;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1e-05;
	pi->outputmax = 6;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 14 ("m_knob4_quantize_27")
	pi = self->__commonstate.params + 14;
	pi->name = "knob4_quantize";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_quantize_27;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1;
	pi->outputmax = 8;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 15 ("m_knob5_MIDIoffset_20")
	pi = self->__commonstate.params + 15;
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
	// initialize parameter 16 ("m_knob6_bandwidth_32")
	pi = self->__commonstate.params + 16;
	pi->name = "knob6_bandwidth";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_bandwidth_32;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1;
	pi->outputmax = 100;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 17 ("m_numVoices_1")
	pi = self->__commonstate.params + 17;
	pi->name = "numVoices";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_numVoices_1;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 18 ("m_randomDeviations_35")
	pi = self->__commonstate.params + 18;
	pi->name = "randomDeviations";
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
	// initialize parameter 19 ("m_sw_24")
	pi = self->__commonstate.params + 19;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_24;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 20 ("m_sw_23")
	pi = self->__commonstate.params + 20;
	pi->name = "sw2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_23;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 21 ("m_sw_19")
	pi = self->__commonstate.params + 21;
	pi->name = "sw3";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_19;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 22 ("m_sw_34")
	pi = self->__commonstate.params + 22;
	pi->name = "sw4";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_34;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 23 ("m_sw_18")
	pi = self->__commonstate.params + 23;
	pi->name = "sw5";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_18;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 24 ("m_sw_33")
	pi = self->__commonstate.params + 24;
	pi->name = "sw6";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_33;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 25 ("m_sw_17")
	pi = self->__commonstate.params + 25;
	pi->name = "sw7";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_17;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 26 ("m_sw_29")
	pi = self->__commonstate.params + 26;
	pi->name = "sw8";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_29;
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
