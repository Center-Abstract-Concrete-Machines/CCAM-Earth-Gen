#include "KHAIROS.h"

namespace KHAIROS {

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
	Change __m_change_109;
	Change __m_change_179;
	Change __m_change_61;
	Change __m_change_60;
	Change __m_change_59;
	Change __m_change_62;
	Change __m_change_64;
	Change __m_change_63;
	Change __m_change_65;
	Change __m_change_175;
	Change __m_change_108;
	Change __m_change_190;
	Change __m_change_197;
	Change __m_change_211;
	Change __m_change_204;
	Change __m_change_66;
	Data m_kick_array_53;
	Data m_grid_matrix_noise_37;
	Data m_hihat_hit_values_55;
	Data m_snare_array_35;
	Data m_snare_hit_values_58;
	Data m_snare_patterns_31;
	Data m_noise_array_34;
	Data m_hihat_array_42;
	Data m_hihat_patterns_43;
	Delta __m_delta_107;
	Delta __m_delta_203;
	Delta __m_delta_210;
	Delta __m_delta_189;
	Delta __m_delta_196;
	Delta __m_delta_178;
	Phasor __m_phasor_177;
	Phasor __m_phasor_188;
	Phasor __m_phasor_187;
	PlusEquals __m_pluseq_214;
	PlusEquals __m_pluseq_213;
	PlusEquals __m_pluseq_212;
	PlusEquals __m_pluseq_205;
	PlusEquals __m_pluseq_198;
	PlusEquals __m_pluseq_176;
	PlusEquals __m_pluseq_215;
	int __loopcount;
	int __exception;
	int vectorsize;
	t_sample __m_count_180;
	t_sample m_knob3_Y_41;
	t_sample __m_carry_182;
	t_sample m_hit_2_hihat_12;
	t_sample m_hit_3_hihat_11;
	t_sample m_hit_1_hihat_13;
	t_sample m_hit_4_hihat_10;
	t_sample m_hit_8_snare_14;
	t_sample samples_to_seconds;
	t_sample __m_latch_174;
	t_sample m_hit_7_snare_15;
	t_sample m_hit_5_snare_17;
	t_sample m_hit_6_snare_16;
	t_sample m_hit_5_hihat_9;
	t_sample __m_count_191;
	t_sample __m_latch_195;
	t_sample __m_latch_209;
	t_sample m_history_3;
	t_sample m_history_2;
	t_sample samplerate;
	t_sample m_history_1;
	t_sample m_hit_4_snare_18;
	t_sample m_history_4;
	t_sample __m_latch_202;
	t_sample m_hit_6_hihat_8;
	t_sample m_history_5;
	t_sample m_hit_7_hihat_7;
	t_sample m_hit_8_hihat_6;
	t_sample m_sw_40;
	t_sample m_hit_3_snare_19;
	t_sample m_hit_1_snare_21;
	t_sample m_sw_36;
	t_sample m_led_48;
	t_sample m_led_50;
	t_sample m_led_52;
	t_sample m_led_51;
	t_sample m_sw_33;
	t_sample m_led_47;
	t_sample m_led_45;
	t_sample m_sw_39;
	t_sample m_led_46;
	t_sample m_knob6_hihatDensity_38;
	t_sample m_knob2_X_44;
	t_sample m_hit_2_snare_20;
	t_sample m_knob5_snareDensity_54;
	t_sample m_knob1_bpm_56;
	t_sample m_z_24;
	t_sample m_x_25;
	t_sample m_history_23;
	t_sample elapsed;
	t_sample m_history_22;
	t_sample m_sw_32;
	t_sample m_y_26;
	t_sample m_knob4_swing_28;
	t_sample m_sw_57;
	t_sample m_mix_27;
	t_sample m_sw_30;
	t_sample m_sw_29;
	t_sample m_led_49;
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
		m_hit_8_hihat_6 = ((int)0);
		m_hit_7_hihat_7 = ((int)0);
		m_hit_6_hihat_8 = ((int)0);
		m_hit_5_hihat_9 = ((int)0);
		m_hit_4_hihat_10 = ((int)0);
		m_hit_3_hihat_11 = ((int)0);
		m_hit_2_hihat_12 = ((int)0);
		m_hit_1_hihat_13 = ((int)0);
		m_hit_8_snare_14 = ((int)0);
		m_hit_7_snare_15 = ((int)0);
		m_hit_6_snare_16 = ((int)0);
		m_hit_5_snare_17 = ((int)0);
		m_hit_4_snare_18 = ((int)0);
		m_hit_3_snare_19 = ((int)0);
		m_hit_2_snare_20 = ((int)0);
		m_hit_1_snare_21 = ((int)0);
		m_history_22 = ((int)0);
		m_history_23 = ((int)0);
		m_z_24 = ((int)0);
		m_x_25 = ((int)0);
		m_y_26 = ((int)0);
		m_mix_27 = ((t_sample)0.5);
		m_knob4_swing_28 = ((int)0);
		m_sw_29 = ((int)0);
		m_sw_30 = ((int)0);
		m_snare_patterns_31.reset("snare_patterns", ((int)8), ((int)64));
		m_sw_32 = ((int)0);
		m_sw_33 = ((int)0);
		m_noise_array_34.reset("noise_array", ((int)48000), ((int)1));
		m_snare_array_35.reset("snare_array", ((int)8), ((int)2));
		m_sw_36 = ((int)0);
		m_grid_matrix_noise_37.reset("grid_matrix_noise", ((int)64), ((int)1));
		m_knob6_hihatDensity_38 = ((int)1);
		m_sw_39 = ((int)0);
		m_sw_40 = ((int)0);
		m_knob3_Y_41 = ((int)0);
		m_hihat_array_42.reset("hihat_array", ((int)8), ((int)2));
		m_hihat_patterns_43.reset("hihat_patterns", ((int)8), ((int)64));
		m_knob2_X_44 = ((int)0);
		m_led_45 = ((int)0);
		m_led_46 = ((int)0);
		m_led_47 = ((int)0);
		m_led_48 = ((int)0);
		m_led_49 = ((int)0);
		m_led_50 = ((int)0);
		m_led_51 = ((int)0);
		m_led_52 = ((int)0);
		m_kick_array_53.reset("kick_array", ((int)8), ((int)1));
		m_knob5_snareDensity_54 = ((int)1);
		m_hihat_hit_values_55.reset("hihat_hit_values", ((int)8), ((int)64));
		m_knob1_bpm_56 = ((int)0);
		m_sw_57 = ((int)0);
		m_snare_hit_values_58.reset("snare_hit_values", ((int)8), ((int)64));
		__m_change_59.reset(0);
		__m_change_60.reset(0);
		__m_change_61.reset(0);
		__m_change_62.reset(0);
		__m_change_63.reset(0);
		__m_change_64.reset(0);
		__m_change_65.reset(0);
		__m_change_66.reset(0);
		elapsed = 0;
		__m_delta_107.reset(0);
		__m_change_108.reset(0);
		__m_change_109.reset(0);
		__m_latch_174 = 0;
		__m_change_175.reset(0);
		__m_pluseq_176.reset(0);
		samples_to_seconds = (1 / samplerate);
		__m_phasor_177.reset(0);
		__m_delta_178.reset(0);
		__m_change_179.reset(0);
		__m_count_180 = 0;
		__m_carry_182 = 0;
		__m_phasor_187.reset(0);
		__m_phasor_188.reset(0);
		__m_delta_189.reset(0);
		__m_change_190.reset(0);
		__m_count_191 = 0;
		__m_latch_195 = 0;
		__m_delta_196.reset(0);
		__m_change_197.reset(0);
		__m_pluseq_198.reset(0);
		__m_latch_202 = 0;
		__m_delta_203.reset(0);
		__m_change_204.reset(0);
		__m_pluseq_205.reset(0);
		__m_latch_209 = 0;
		__m_delta_210.reset(0);
		__m_change_211.reset(0);
		__m_pluseq_212.reset(0);
		__m_pluseq_213.reset(0);
		__m_pluseq_214.reset(0);
		__m_pluseq_215.reset(0);
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
		t_sample * __out15 = __outs[14];
		t_sample * __out16 = __outs[15];
		t_sample * __out17 = __outs[16];
		t_sample * __out18 = __outs[17];
		t_sample * __out19 = __outs[18];
		t_sample * __out20 = __outs[19];
		t_sample * __out21 = __outs[20];
		t_sample * __out22 = __outs[21];
		t_sample * __out23 = __outs[22];
		t_sample * __out24 = __outs[23];
		t_sample * __out25 = __outs[24];
		t_sample * __out26 = __outs[25];
		t_sample * __out27 = __outs[26];
		t_sample * __out28 = __outs[27];
		t_sample * __out29 = __outs[28];
		t_sample * __out30 = __outs[29];
		t_sample * __out31 = __outs[30];
		t_sample * __out32 = __outs[31];
		t_sample * __out33 = __outs[32];
		t_sample * __out34 = __outs[33];
		if (__exception) {
			return __exception;
			
		} else if (( (__in1 == 0) || (__in2 == 0) || (__out1 == 0) || (__out2 == 0) || (__out3 == 0) || (__out4 == 0) || (__out5 == 0) || (__out6 == 0) || (__out7 == 0) || (__out8 == 0) || (__out9 == 0) || (__out10 == 0) || (__out11 == 0) || (__out12 == 0) || (__out13 == 0) || (__out14 == 0) || (__out15 == 0) || (__out16 == 0) || (__out17 == 0) || (__out18 == 0) || (__out19 == 0) || (__out20 == 0) || (__out21 == 0) || (__out22 == 0) || (__out23 == 0) || (__out24 == 0) || (__out25 == 0) || (__out26 == 0) || (__out27 == 0) || (__out28 == 0) || (__out29 == 0) || (__out30 == 0) || (__out31 == 0) || (__out32 == 0) || (__out33 == 0) || (__out34 == 0) )) {
			__exception = GENLIB_ERR_NULL_BUFFER;
			return __exception;
			
		};
		__loopcount = (__n * GENLIB_LOOPCOUNT_BAIL);
		samples_to_seconds = (1 / samplerate);
		int grid_matrix_noise_dim = m_grid_matrix_noise_37.dim;
		int grid_matrix_noise_channels = m_grid_matrix_noise_37.channels;
		int kick_array_dim = m_kick_array_53.dim;
		int kick_array_channels = m_kick_array_53.channels;
		int hihat_array_dim = m_hihat_array_42.dim;
		int hihat_array_channels = m_hihat_array_42.channels;
		int snare_array_dim = m_snare_array_35.dim;
		int snare_array_channels = m_snare_array_35.channels;
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			int sw_1 = (__m_change_59((m_sw_57 > ((int)0))) > ((int)0));
			int sw_2 = (__m_change_60((m_sw_29 > ((int)0))) > ((int)0));
			int sw_3 = (__m_change_61((m_sw_40 > ((int)0))) > ((int)0));
			int sw_4 = (__m_change_62((m_sw_33 > ((int)0))) > ((int)0));
			int sw_5 = (__m_change_63((m_sw_36 > ((int)0))) > ((int)0));
			int sw_6 = (__m_change_64((m_sw_30 > ((int)0))) > ((int)0));
			int sw_7 = (__m_change_65((m_sw_32 > ((int)0))) > ((int)0));
			int sw_8 = (__m_change_66((m_sw_39 > ((int)0))) > ((int)0));
			if ((elapsed == ((int)0))) {
				// for loop initializer;
				int i = ((int)0);
				// for loop condition;
				int kick_array_dim = m_kick_array_53.dim;
				int kick_array_channels = m_kick_array_53.channels;
				while ((i < kick_array_dim)) {
					// abort processing if an infinite loop is suspected;
					if (((__loopcount--) <= 0)) {
						__exception = GENLIB_ERR_LOOP_OVERFLOW;
						break ;
						
					};
					bool index_ignore_67 = ((i >= kick_array_dim) || (i < 0));
					if ((!index_ignore_67)) {
						m_kick_array_53.write(((int)0), i, 0);
						
					};
					// for loop increment;
					i = (i + ((int)1));
					
				};
				m_led_52 = ((int)1);
				m_led_51 = ((int)1);
				m_led_50 = ((int)1);
				m_led_49 = ((int)1);
				m_led_48 = ((int)1);
				m_led_47 = ((int)1);
				m_led_46 = ((int)1);
				m_led_45 = ((int)1);
				
			};
			// abort processing if an infinite loop is suspected;
			if (((__loopcount--) <= 0)) {
				__exception = GENLIB_ERR_LOOP_OVERFLOW;
				break ;
				
			};
			if (sw_1) {
				int kick_array_dim = m_kick_array_53.dim;
				int kick_array_channels = m_kick_array_53.channels;
				// samples kick_array channel 1;
				int chan_68 = ((int)0);
				bool chan_ignore_69 = ((chan_68 < 0) || (chan_68 >= kick_array_channels));
				t_sample a = (chan_ignore_69 ? 0 : m_kick_array_53.read(0, chan_68));
				m_kick_array_53.write((!a), 0, 0);
				m_led_52 = a;
				
			};
			if (sw_2) {
				int kick_array_dim = m_kick_array_53.dim;
				int kick_array_channels = m_kick_array_53.channels;
				bool index_ignore_70 = (((int)1) >= kick_array_dim);
				// samples kick_array channel 1;
				int chan_71 = ((int)0);
				bool chan_ignore_72 = ((chan_71 < 0) || (chan_71 >= kick_array_channels));
				t_sample a = ((chan_ignore_72 || index_ignore_70) ? 0 : m_kick_array_53.read(((int)1), chan_71));
				bool index_ignore_73 = (((int)1) >= kick_array_dim);
				if ((!index_ignore_73)) {
					m_kick_array_53.write((!a), ((int)1), 0);
					
				};
				m_led_51 = a;
				
			};
			if (sw_3) {
				int kick_array_dim = m_kick_array_53.dim;
				int kick_array_channels = m_kick_array_53.channels;
				bool index_ignore_74 = (((int)2) >= kick_array_dim);
				// samples kick_array channel 1;
				int chan_75 = ((int)0);
				bool chan_ignore_76 = ((chan_75 < 0) || (chan_75 >= kick_array_channels));
				t_sample a = ((chan_ignore_76 || index_ignore_74) ? 0 : m_kick_array_53.read(((int)2), chan_75));
				bool index_ignore_77 = (((int)2) >= kick_array_dim);
				if ((!index_ignore_77)) {
					m_kick_array_53.write((!a), ((int)2), 0);
					
				};
				m_led_50 = a;
				
			};
			if (sw_4) {
				int kick_array_dim = m_kick_array_53.dim;
				int kick_array_channels = m_kick_array_53.channels;
				bool index_ignore_78 = (((int)3) >= kick_array_dim);
				// samples kick_array channel 1;
				int chan_79 = ((int)0);
				bool chan_ignore_80 = ((chan_79 < 0) || (chan_79 >= kick_array_channels));
				t_sample a = ((chan_ignore_80 || index_ignore_78) ? 0 : m_kick_array_53.read(((int)3), chan_79));
				bool index_ignore_81 = (((int)3) >= kick_array_dim);
				if ((!index_ignore_81)) {
					m_kick_array_53.write((!a), ((int)3), 0);
					
				};
				m_led_49 = a;
				
			};
			if (sw_5) {
				int kick_array_dim = m_kick_array_53.dim;
				int kick_array_channels = m_kick_array_53.channels;
				bool index_ignore_82 = (((int)4) >= kick_array_dim);
				// samples kick_array channel 1;
				int chan_83 = ((int)0);
				bool chan_ignore_84 = ((chan_83 < 0) || (chan_83 >= kick_array_channels));
				t_sample a = ((chan_ignore_84 || index_ignore_82) ? 0 : m_kick_array_53.read(((int)4), chan_83));
				bool index_ignore_85 = (((int)4) >= kick_array_dim);
				if ((!index_ignore_85)) {
					m_kick_array_53.write((!a), ((int)4), 0);
					
				};
				m_led_48 = a;
				
			};
			if (sw_6) {
				int kick_array_dim = m_kick_array_53.dim;
				int kick_array_channels = m_kick_array_53.channels;
				bool index_ignore_86 = (((int)5) >= kick_array_dim);
				// samples kick_array channel 1;
				int chan_87 = ((int)0);
				bool chan_ignore_88 = ((chan_87 < 0) || (chan_87 >= kick_array_channels));
				t_sample a = ((chan_ignore_88 || index_ignore_86) ? 0 : m_kick_array_53.read(((int)5), chan_87));
				bool index_ignore_89 = (((int)5) >= kick_array_dim);
				if ((!index_ignore_89)) {
					m_kick_array_53.write((!a), ((int)5), 0);
					
				};
				m_led_47 = a;
				
			};
			if (sw_7) {
				int kick_array_dim = m_kick_array_53.dim;
				int kick_array_channels = m_kick_array_53.channels;
				bool index_ignore_90 = (((int)6) >= kick_array_dim);
				// samples kick_array channel 1;
				int chan_91 = ((int)0);
				bool chan_ignore_92 = ((chan_91 < 0) || (chan_91 >= kick_array_channels));
				t_sample a = ((chan_ignore_92 || index_ignore_90) ? 0 : m_kick_array_53.read(((int)6), chan_91));
				bool index_ignore_93 = (((int)6) >= kick_array_dim);
				if ((!index_ignore_93)) {
					m_kick_array_53.write((!a), ((int)6), 0);
					
				};
				m_led_46 = a;
				
			};
			if (sw_8) {
				int kick_array_dim = m_kick_array_53.dim;
				int kick_array_channels = m_kick_array_53.channels;
				bool index_ignore_94 = (((int)7) >= kick_array_dim);
				// samples kick_array channel 1;
				int chan_95 = ((int)0);
				bool chan_ignore_96 = ((chan_95 < 0) || (chan_95 >= kick_array_channels));
				t_sample a = ((chan_ignore_96 || index_ignore_94) ? 0 : m_kick_array_53.read(((int)7), chan_95));
				bool index_ignore_97 = (((int)7) >= kick_array_dim);
				if ((!index_ignore_97)) {
					m_kick_array_53.write((!a), ((int)7), 0);
					
				};
				m_led_45 = a;
				
			};
			t_sample expr_12717 = m_led_52;
			t_sample expr_12718 = m_led_51;
			t_sample expr_12719 = m_led_50;
			t_sample expr_12720 = m_led_49;
			t_sample expr_12721 = m_led_48;
			t_sample expr_12722 = m_led_47;
			t_sample expr_12723 = m_led_46;
			t_sample expr_12724 = m_led_45;
			if ((elapsed == ((int)0))) {
				// for loop initializer;
				int c = ((int)0);
				// for loop condition;
				while ((c < ((int)64))) {
					// abort processing if an infinite loop is suspected;
					if (((__loopcount--) <= 0)) {
						__exception = GENLIB_ERR_LOOP_OVERFLOW;
						break ;
						
					};
					// for loop initializer;
					int i_12743 = ((int)0);
					// for loop condition;
					while ((i_12743 < ((int)8))) {
						// abort processing if an infinite loop is suspected;
						if (((__loopcount--) <= 0)) {
							__exception = GENLIB_ERR_LOOP_OVERFLOW;
							break ;
							
						};
						t_sample noise_12946 = noise();
						t_sample sub_12949 = (noise_12946 - (-1));
						t_sample scale_12945 = ((safepow((sub_12949 * ((t_sample)0.5)), ((int)1)) * ((t_sample)0.85)) + ((t_sample)0.1));
						t_sample noise_12956 = noise();
						t_sample sub_12959 = (noise_12956 - (-1));
						t_sample scale_12955 = ((safepow((sub_12959 * ((t_sample)0.5)), ((int)1)) * ((t_sample)0.85)) + ((t_sample)0.1));
						int snare_patterns_dim = m_snare_patterns_31.dim;
						int snare_patterns_channels = m_snare_patterns_31.channels;
						bool chan_ignore_98 = ((c < 0) || (c >= snare_patterns_channels));
						bool index_ignore_99 = ((i_12743 >= snare_patterns_dim) || (i_12743 < 0));
						if ((!(chan_ignore_98 || index_ignore_99))) {
							m_snare_patterns_31.write(((int)1), i_12743, c);
							
						};
						int snare_hit_values_dim = m_snare_hit_values_58.dim;
						int snare_hit_values_channels = m_snare_hit_values_58.channels;
						bool chan_ignore_100 = ((c < 0) || (c >= snare_hit_values_channels));
						bool index_ignore_101 = ((i_12743 >= snare_hit_values_dim) || (i_12743 < 0));
						if ((!(chan_ignore_100 || index_ignore_101))) {
							m_snare_hit_values_58.write(scale_12945, i_12743, c);
							
						};
						int hihat_patterns_dim = m_hihat_patterns_43.dim;
						int hihat_patterns_channels = m_hihat_patterns_43.channels;
						bool chan_ignore_102 = ((c < 0) || (c >= hihat_patterns_channels));
						bool index_ignore_103 = ((i_12743 >= hihat_patterns_dim) || (i_12743 < 0));
						if ((!(chan_ignore_102 || index_ignore_103))) {
							m_hihat_patterns_43.write(((int)1), i_12743, c);
							
						};
						int hihat_hit_values_dim = m_hihat_hit_values_55.dim;
						int hihat_hit_values_channels = m_hihat_hit_values_55.channels;
						bool chan_ignore_104 = ((c < 0) || (c >= hihat_hit_values_channels));
						bool index_ignore_105 = ((i_12743 >= hihat_hit_values_dim) || (i_12743 < 0));
						if ((!(chan_ignore_104 || index_ignore_105))) {
							m_hihat_hit_values_55.write(scale_12955, i_12743, c);
							
						};
						// for loop increment;
						i_12743 = (i_12743 + ((int)1));
						
					};
					// for loop increment;
					c = (c + ((int)1));
					
				};
				
			};
			t_sample sub_12968 = (m_knob2_X_44 - ((int)0));
			t_sample scale_12965 = ((safepow((sub_12968 * ((t_sample)1)), ((int)1)) * ((int)7)) + ((int)1));
			t_sample expr_12714 = (round((scale_12965 * ((t_sample)1))) * ((int)1));
			t_sample sub_12972 = (m_knob3_Y_41 - ((int)0));
			t_sample scale_12969 = ((safepow((sub_12972 * ((t_sample)1)), ((int)1)) * ((int)7)) + ((int)1));
			t_sample expr_12715 = (round((scale_12969 * ((t_sample)1))) * ((int)1));
			t_sample out30 = expr_12715;
			t_sample out29 = expr_12714;
			t_sample noise_12657 = noise();
			t_sample mix_12979 = (noise_12657 + (((t_sample)0.7) * (m_history_5 - noise_12657)));
			t_sample mix_12655 = mix_12979;
			t_sample noise_12640 = noise();
			t_sample mix_12980 = (noise_12640 + (((t_sample)0.5) * (m_history_4 - noise_12640)));
			t_sample mix_12617 = mix_12980;
			t_sample mix_12981 = (mix_12617 + (((t_sample)0.6) * (m_history_3 - mix_12617)));
			t_sample mix_12638 = mix_12981;
			int or_12469 = (((int)0) || (elapsed == ((int)0)));
			t_sample switch_12472 = (or_12469 ? ((t_sample)0.31) : m_z_24);
			t_sample mul_12489 = (switch_12472 * ((int)1));
			t_sample switch_12471 = (or_12469 ? ((t_sample)0.41) : m_y_26);
			t_sample mul_12484 = (switch_12471 * ((int)1));
			t_sample switch_12470 = (or_12469 ? ((t_sample)0.1) : m_x_25);
			t_sample mul_12492 = (mul_12489 * ((t_sample)0.0002));
			t_sample add_12486 = (switch_12471 + mul_12492);
			t_sample fixnan_12475 = fixnan(add_12486);
			t_sample gen_12498 = fixnan_12475;
			t_sample mul_12493 = (mul_12484 * ((t_sample)0.0002));
			t_sample add_12487 = (switch_12470 + mul_12493);
			t_sample fixnan_12473 = fixnan(add_12487);
			t_sample mul_12481 = (switch_12472 * (-0.45));
			t_sample pow_12479 = safepow(switch_12470, ((int)3));
			t_sample mul_12480 = (pow_12479 * (-1));
			t_sample mul_12483 = (switch_12470 * ((t_sample)0.8));
			t_sample mul_12482 = (switch_12471 * (-1.1));
			t_sample add_12478 = (mul_12483 + mul_12482);
			t_sample add_12477 = (add_12478 + mul_12481);
			t_sample add_12476 = (add_12477 + mul_12480);
			t_sample mul_12491 = (add_12476 * ((t_sample)0.0002));
			t_sample add_12485 = (switch_12472 + mul_12491);
			t_sample fixnan_12474 = fixnan(add_12485);
			t_sample y_next_12494 = fixdenorm(fixnan_12475);
			t_sample x_next_12495 = fixdenorm(fixnan_12473);
			t_sample z_next_12496 = fixdenorm(fixnan_12474);
			t_sample elapsed_12501 = elapsed;
			int eq_12500 = (elapsed_12501 == ((int)0));
			int or_12508 = (eq_12500 || ((int)0));
			t_sample switch_12504 = (or_12508 ? ((int)10000000000) : m_history_23);
			t_sample min_12507 = ((switch_12504 < gen_12498) ? switch_12504 : gen_12498);
			t_sample gen_12511 = min_12507;
			int iftrue_106 = (-10000000000);
			t_sample switch_12503 = (or_12508 ? iftrue_106 : m_history_22);
			t_sample max_12506 = ((gen_12498 < switch_12503) ? switch_12503 : gen_12498);
			t_sample gen_12512 = max_12506;
			t_sample history_12502_next_12509 = fixdenorm(min_12507);
			t_sample history_12505_next_12510 = fixdenorm(max_12506);
			t_sample irange_12983 = (gen_12512 - gen_12511);
			t_sample sub_12985 = (gen_12498 - gen_12511);
			t_sample scale_12982 = ((safepow(safediv(sub_12985, irange_12983), ((int)1)) * ((int)2)) + ((int)-1));
			t_sample scale_12513 = scale_12982;
			t_sample gen_12514 = scale_12513;
			t_sample mul_12461 = (m_knob4_swing_28 * gen_12514);
			t_sample out33 = mul_12461;
			t_sample mstosamps_12518 = (((int)1) * (samplerate * 0.001));
			t_sample max_12519 = ((mstosamps_12518 < vectorsize) ? vectorsize : mstosamps_12518);
			t_sample sub_12989 = (m_knob1_bpm_56 - ((int)0));
			t_sample scale_12986 = ((safepow((sub_12989 * ((t_sample)1)), ((int)1)) * ((int)-460)) + ((int)500));
			t_sample scale_12609 = scale_12986;
			t_sample div_12710 = (scale_12609 * ((t_sample)0.016666666666667));
			t_sample div_12571 = (div_12710 * ((t_sample)0.125));
			t_sample div_12463 = safediv(div_12571, samplerate);
			t_sample mul_12467 = (div_12463 * mul_12461);
			t_sample add_12462 = (div_12463 + mul_12467);
			t_sample add_12466 = (m_history_2 + add_12462);
			t_sample wrap_12464 = wrap(add_12466, ((int)0), ((int)1));
			t_sample mul_12708 = (wrap_12464 * ((int)8));
			t_sample floor_12707 = floor(mul_12708);
			t_sample out28 = floor_12707;
			t_sample sub_12653 = (noise_12657 - mix_12655);
			t_sample wrap_12684 = wrap(mul_12708, ((int)0), ((int)1));
			t_sample delta_12659 = __m_delta_107(wrap_12684);
			t_sample abs_12663 = fabs(delta_12659);
			int gt_12662 = (abs_12663 > ((t_sample)0.5));
			int change_12661 = __m_change_108(gt_12662);
			int gt_12660 = (change_12661 > ((int)0));
			int trigger_beat_12669 = gt_12660;
			int trigger_beat_12683 = trigger_beat_12669;
			int trig = (__m_change_109((trigger_beat_12683 > ((int)0))) > ((int)0));
			if (trig) {
				int snare_array_dim = m_snare_array_35.dim;
				int snare_array_channels = m_snare_array_35.channels;
				// samples snare_array channel 1;
				int chan_110 = ((int)0);
				bool chan_ignore_111 = ((chan_110 < 0) || (chan_110 >= snare_array_channels));
				m_hit_1_snare_21 = (chan_ignore_111 ? 0 : m_snare_array_35.read(0, chan_110));
				bool index_ignore_112 = (((int)1) >= snare_array_dim);
				// samples snare_array channel 1;
				int chan_113 = ((int)0);
				bool chan_ignore_114 = ((chan_113 < 0) || (chan_113 >= snare_array_channels));
				m_hit_2_snare_20 = ((chan_ignore_114 || index_ignore_112) ? 0 : m_snare_array_35.read(((int)1), chan_113));
				bool index_ignore_115 = (((int)2) >= snare_array_dim);
				// samples snare_array channel 1;
				int chan_116 = ((int)0);
				bool chan_ignore_117 = ((chan_116 < 0) || (chan_116 >= snare_array_channels));
				m_hit_3_snare_19 = ((chan_ignore_117 || index_ignore_115) ? 0 : m_snare_array_35.read(((int)2), chan_116));
				bool index_ignore_118 = (((int)3) >= snare_array_dim);
				// samples snare_array channel 1;
				int chan_119 = ((int)0);
				bool chan_ignore_120 = ((chan_119 < 0) || (chan_119 >= snare_array_channels));
				m_hit_4_snare_18 = ((chan_ignore_120 || index_ignore_118) ? 0 : m_snare_array_35.read(((int)3), chan_119));
				bool index_ignore_121 = (((int)4) >= snare_array_dim);
				// samples snare_array channel 1;
				int chan_122 = ((int)0);
				bool chan_ignore_123 = ((chan_122 < 0) || (chan_122 >= snare_array_channels));
				m_hit_5_snare_17 = ((chan_ignore_123 || index_ignore_121) ? 0 : m_snare_array_35.read(((int)4), chan_122));
				bool index_ignore_124 = (((int)5) >= snare_array_dim);
				// samples snare_array channel 1;
				int chan_125 = ((int)0);
				bool chan_ignore_126 = ((chan_125 < 0) || (chan_125 >= snare_array_channels));
				m_hit_6_snare_16 = ((chan_ignore_126 || index_ignore_124) ? 0 : m_snare_array_35.read(((int)5), chan_125));
				bool index_ignore_127 = (((int)6) >= snare_array_dim);
				// samples snare_array channel 1;
				int chan_128 = ((int)0);
				bool chan_ignore_129 = ((chan_128 < 0) || (chan_128 >= snare_array_channels));
				m_hit_7_snare_15 = ((chan_ignore_129 || index_ignore_127) ? 0 : m_snare_array_35.read(((int)6), chan_128));
				bool index_ignore_130 = (((int)7) >= snare_array_dim);
				// samples snare_array channel 1;
				int chan_131 = ((int)0);
				bool chan_ignore_132 = ((chan_131 < 0) || (chan_131 >= snare_array_channels));
				m_hit_8_snare_14 = ((chan_ignore_132 || index_ignore_130) ? 0 : m_snare_array_35.read(((int)7), chan_131));
				int hihat_array_dim = m_hihat_array_42.dim;
				int hihat_array_channels = m_hihat_array_42.channels;
				// samples hihat_array channel 1;
				int chan_133 = ((int)0);
				bool chan_ignore_134 = ((chan_133 < 0) || (chan_133 >= hihat_array_channels));
				m_hit_1_hihat_13 = (chan_ignore_134 ? 0 : m_hihat_array_42.read(0, chan_133));
				bool index_ignore_135 = (((int)1) >= hihat_array_dim);
				// samples hihat_array channel 1;
				int chan_136 = ((int)0);
				bool chan_ignore_137 = ((chan_136 < 0) || (chan_136 >= hihat_array_channels));
				m_hit_2_hihat_12 = ((chan_ignore_137 || index_ignore_135) ? 0 : m_hihat_array_42.read(((int)1), chan_136));
				bool index_ignore_138 = (((int)2) >= hihat_array_dim);
				// samples hihat_array channel 1;
				int chan_139 = ((int)0);
				bool chan_ignore_140 = ((chan_139 < 0) || (chan_139 >= hihat_array_channels));
				m_hit_3_hihat_11 = ((chan_ignore_140 || index_ignore_138) ? 0 : m_hihat_array_42.read(((int)2), chan_139));
				bool index_ignore_141 = (((int)3) >= hihat_array_dim);
				// samples hihat_array channel 1;
				int chan_142 = ((int)0);
				bool chan_ignore_143 = ((chan_142 < 0) || (chan_142 >= hihat_array_channels));
				m_hit_4_hihat_10 = ((chan_ignore_143 || index_ignore_141) ? 0 : m_hihat_array_42.read(((int)3), chan_142));
				bool index_ignore_144 = (((int)4) >= hihat_array_dim);
				// samples hihat_array channel 1;
				int chan_145 = ((int)0);
				bool chan_ignore_146 = ((chan_145 < 0) || (chan_145 >= hihat_array_channels));
				m_hit_5_hihat_9 = ((chan_ignore_146 || index_ignore_144) ? 0 : m_hihat_array_42.read(((int)4), chan_145));
				bool index_ignore_147 = (((int)5) >= hihat_array_dim);
				// samples hihat_array channel 1;
				int chan_148 = ((int)0);
				bool chan_ignore_149 = ((chan_148 < 0) || (chan_148 >= hihat_array_channels));
				m_hit_6_hihat_8 = ((chan_ignore_149 || index_ignore_147) ? 0 : m_hihat_array_42.read(((int)5), chan_148));
				bool index_ignore_150 = (((int)6) >= hihat_array_dim);
				// samples hihat_array channel 1;
				int chan_151 = ((int)0);
				bool chan_ignore_152 = ((chan_151 < 0) || (chan_151 >= hihat_array_channels));
				m_hit_7_hihat_7 = ((chan_ignore_152 || index_ignore_150) ? 0 : m_hihat_array_42.read(((int)6), chan_151));
				bool index_ignore_153 = (((int)7) >= hihat_array_dim);
				// samples hihat_array channel 1;
				int chan_154 = ((int)0);
				bool chan_ignore_155 = ((chan_154 < 0) || (chan_154 >= hihat_array_channels));
				m_hit_8_hihat_6 = ((chan_ignore_155 || index_ignore_153) ? 0 : m_hihat_array_42.read(((int)7), chan_154));
				// for loop initializer;
				int i_12745 = ((int)0);
				// for loop condition;
				while ((i_12745 < snare_array_dim)) {
					// abort processing if an infinite loop is suspected;
					if (((__loopcount--) <= 0)) {
						__exception = GENLIB_ERR_LOOP_OVERFLOW;
						break ;
						
					};
					t_sample sub_12993 = (m_knob2_X_44 - ((int)0));
					t_sample scale_12990 = ((safepow((sub_12993 * ((t_sample)1)), ((int)1)) * ((int)7)) + ((int)0));
					t_sample sub_12997 = (m_knob3_Y_41 - ((int)0));
					t_sample scale_12994 = ((safepow((sub_12997 * ((t_sample)1)), ((int)1)) * ((int)7)) + ((int)0));
					t_sample c_12744 = ((round((scale_12990 * ((t_sample)1))) * ((int)1)) + (round(((scale_12994 * ((int)8)) * ((t_sample)1))) * ((int)1)));
					int snare_patterns_dim = m_snare_patterns_31.dim;
					int snare_patterns_channels = m_snare_patterns_31.channels;
					bool index_ignore_156 = ((i_12745 >= snare_patterns_dim) || (i_12745 < 0));
					// samples snare_patterns channel 1;
					int chan_157 = c_12744;
					bool chan_ignore_158 = ((chan_157 < 0) || (chan_157 >= snare_patterns_channels));
					t_sample h = ((chan_ignore_158 || index_ignore_156) ? 0 : m_snare_patterns_31.read(i_12745, chan_157));
					int snare_hit_values_dim = m_snare_hit_values_58.dim;
					int snare_hit_values_channels = m_snare_hit_values_58.channels;
					bool index_ignore_159 = ((i_12745 >= snare_hit_values_dim) || (i_12745 < 0));
					// samples snare_hit_values channel 1;
					int chan_160 = c_12744;
					bool chan_ignore_161 = ((chan_160 < 0) || (chan_160 >= snare_hit_values_channels));
					t_sample v = ((chan_ignore_161 || index_ignore_159) ? 0 : m_snare_hit_values_58.read(i_12745, chan_160));
					int hit = ((int)0);
					if (((v < (((int)1) - m_knob5_snareDensity_54)) && (h == ((int)1)))) {
						hit = ((int)1);
						
					};
					bool index_ignore_162 = ((i_12745 >= snare_array_dim) || (i_12745 < 0));
					if ((!index_ignore_162)) {
						m_snare_array_35.write(hit, i_12745, 0);
						
					};
					bool chan_ignore_163 = ((((int)1) < 0) || (((int)1) >= snare_array_channels));
					bool index_ignore_164 = ((i_12745 >= snare_array_dim) || (i_12745 < 0));
					if ((!(chan_ignore_163 || index_ignore_164))) {
						m_snare_array_35.write(v, i_12745, ((int)1));
						
					};
					// for loop increment;
					i_12745 = (i_12745 + ((int)1));
					
				};
				// for loop initializer;
				i_12745 = ((int)0);
				// for loop condition;
				while ((i_12745 < hihat_array_dim)) {
					// abort processing if an infinite loop is suspected;
					if (((__loopcount--) <= 0)) {
						__exception = GENLIB_ERR_LOOP_OVERFLOW;
						break ;
						
					};
					t_sample sub_13001 = (m_knob2_X_44 - ((int)0));
					t_sample scale_12998 = ((safepow((sub_13001 * ((t_sample)1)), ((int)1)) * ((int)7)) + ((int)0));
					t_sample sub_13005 = (m_knob3_Y_41 - ((int)0));
					t_sample scale_13002 = ((safepow((sub_13005 * ((t_sample)1)), ((int)1)) * ((int)7)) + ((int)0));
					t_sample c_12744 = ((round((scale_12998 * ((t_sample)1))) * ((int)1)) + (round(((scale_13002 * ((int)8)) * ((t_sample)1))) * ((int)1)));
					int hihat_patterns_dim = m_hihat_patterns_43.dim;
					int hihat_patterns_channels = m_hihat_patterns_43.channels;
					bool index_ignore_165 = ((i_12745 >= hihat_patterns_dim) || (i_12745 < 0));
					// samples hihat_patterns channel 1;
					int chan_166 = c_12744;
					bool chan_ignore_167 = ((chan_166 < 0) || (chan_166 >= hihat_patterns_channels));
					t_sample h = ((chan_ignore_167 || index_ignore_165) ? 0 : m_hihat_patterns_43.read(i_12745, chan_166));
					int hihat_hit_values_dim = m_hihat_hit_values_55.dim;
					int hihat_hit_values_channels = m_hihat_hit_values_55.channels;
					bool index_ignore_168 = ((i_12745 >= hihat_hit_values_dim) || (i_12745 < 0));
					// samples hihat_hit_values channel 1;
					int chan_169 = c_12744;
					bool chan_ignore_170 = ((chan_169 < 0) || (chan_169 >= hihat_hit_values_channels));
					t_sample v = ((chan_ignore_170 || index_ignore_168) ? 0 : m_hihat_hit_values_55.read(i_12745, chan_169));
					int hit = ((int)0);
					if (((v < (((int)1) - m_knob6_hihatDensity_38)) && (h == ((int)1)))) {
						hit = ((int)1);
						
					};
					bool index_ignore_171 = ((i_12745 >= hihat_array_dim) || (i_12745 < 0));
					if ((!index_ignore_171)) {
						m_hihat_array_42.write(hit, i_12745, 0);
						
					};
					bool chan_ignore_172 = ((((int)1) < 0) || (((int)1) >= hihat_array_channels));
					bool index_ignore_173 = ((i_12745 >= hihat_array_dim) || (i_12745 < 0));
					if ((!(chan_ignore_172 || index_ignore_173))) {
						m_hihat_array_42.write(v, i_12745, ((int)1));
						
					};
					// for loop increment;
					i_12745 = (i_12745 + ((int)1));
					
				};
				
			};
			t_sample expr_12727 = m_hit_1_snare_21;
			t_sample expr_12728 = m_hit_2_snare_20;
			t_sample expr_12729 = m_hit_3_snare_19;
			t_sample expr_12730 = m_hit_4_snare_18;
			t_sample expr_12731 = m_hit_5_snare_17;
			t_sample expr_12732 = m_hit_6_snare_16;
			t_sample expr_12733 = m_hit_7_snare_15;
			t_sample expr_12734 = m_hit_8_snare_14;
			t_sample expr_12735 = m_hit_1_hihat_13;
			t_sample expr_12736 = m_hit_2_hihat_12;
			t_sample expr_12737 = m_hit_3_hihat_11;
			t_sample expr_12738 = m_hit_4_hihat_10;
			t_sample expr_12739 = m_hit_5_hihat_9;
			t_sample expr_12740 = m_hit_6_hihat_8;
			t_sample expr_12741 = m_hit_7_hihat_7;
			t_sample expr_12742 = m_hit_8_hihat_6;
			t_sample out15 = expr_12731;
			t_sample out22 = expr_12738;
			t_sample out25 = expr_12741;
			t_sample out12 = expr_12728;
			t_sample out24 = expr_12740;
			t_sample out20 = expr_12736;
			t_sample out16 = expr_12732;
			t_sample out23 = expr_12739;
			t_sample out17 = expr_12733;
			t_sample out18 = expr_12734;
			t_sample out11 = expr_12727;
			t_sample out14 = expr_12730;
			t_sample out21 = expr_12737;
			t_sample out19 = expr_12735;
			t_sample out13 = expr_12729;
			t_sample out26 = expr_12742;
			t_sample out27 = trigger_beat_12683;
			int trigger_beat_12580 = trigger_beat_12669;
			__m_latch_174 = ((trigger_beat_12580 != 0) ? floor_12707 : __m_latch_174);
			t_sample latch_12581 = __m_latch_174;
			int eq_12572 = (latch_12581 == ((int)7));
			t_sample out10 = (eq_12572 + expr_12724);
			int eq_12573 = (latch_12581 == ((int)6));
			t_sample out9 = (eq_12573 + expr_12723);
			int eq_12576 = (latch_12581 == ((int)3));
			t_sample out6 = (eq_12576 + expr_12720);
			int eq_12578 = (latch_12581 == ((int)1));
			t_sample out4 = (eq_12578 + expr_12718);
			int eq_12579 = (latch_12581 == ((int)0));
			t_sample out3 = (eq_12579 + expr_12717);
			int eq_12575 = (latch_12581 == ((int)4));
			t_sample out7 = (eq_12575 + expr_12721);
			int eq_12574 = (latch_12581 == ((int)5));
			t_sample out8 = (eq_12574 + expr_12722);
			int eq_12577 = (latch_12581 == ((int)2));
			t_sample out5 = (eq_12577 + expr_12719);
			int trigger_beat_12517 = trigger_beat_12669;
			int gt_12525 = (trigger_beat_12517 > ((int)0));
			int change_12524 = __m_change_175(gt_12525);
			int gt_12523 = (change_12524 > ((int)0));
			int plusequals_12522 = __m_pluseq_176.post(((int)1), gt_12523, 0);
			int lte_12521 = (plusequals_12522 <= max_12519);
			t_sample out34 = lte_12521;
			if ((((int)0) != 0)) {
				__m_phasor_177.phase = 0;
				
			};
			t_sample phasor_12547 = __m_phasor_177(((int)5000), samples_to_seconds);
			t_sample delta_12542 = __m_delta_178(phasor_12547);
			t_sample abs_12546 = fabs(delta_12542);
			int gt_12545 = (abs_12546 > ((t_sample)0.5));
			int change_12544 = __m_change_179(gt_12545);
			int gt_12543 = (change_12544 > ((int)0));
			__m_count_180 = (((int)0) ? 0 : (fixdenorm(__m_count_180 + gt_12543)));
			int carry_181 = 0;
			if ((((int)0) != 0)) {
				__m_count_180 = 0;
				__m_carry_182 = 0;
				
			} else if (((((int)63) > 0) && (__m_count_180 >= ((int)63)))) {
				int wraps_183 = (__m_count_180 / ((int)63));
				__m_carry_182 = (__m_carry_182 + wraps_183);
				__m_count_180 = (__m_count_180 - (wraps_183 * ((int)63)));
				carry_181 = 1;
				
			};
			int counter_12551 = __m_count_180;
			int counter_12552 = carry_181;
			int counter_12553 = __m_carry_182;
			bool index_ignore_184 = ((counter_12551 >= grid_matrix_noise_dim) || (counter_12551 < 0));
			// samples grid_matrix_noise channel 1;
			int chan_185 = ((int)0);
			bool chan_ignore_186 = ((chan_185 < 0) || (chan_185 >= grid_matrix_noise_channels));
			t_sample sample_grid_matrix_noise_12548 = ((chan_ignore_186 || index_ignore_184) ? 0 : m_grid_matrix_noise_37.read(counter_12551, chan_185));
			t_sample index_grid_matrix_noise_12549 = counter_12551;
			t_sample out32 = sample_grid_matrix_noise_12548;
			int add_12541 = (counter_12551 + ((int)1));
			t_sample out31 = add_12541;
			t_sample sub_12615 = (mix_12617 - mix_12638);
			if ((((int)0) != 0)) {
				__m_phasor_187.phase = 0;
				
			};
			t_sample phasor_12634 = __m_phasor_187(((int)330), samples_to_seconds);
			t_sample triangle_12633 = triangle(phasor_12634, ((t_sample)0.5));
			if ((((int)0) != 0)) {
				__m_phasor_188.phase = 0;
				
			};
			t_sample phasor_12632 = __m_phasor_188(((int)185), samples_to_seconds);
			t_sample triangle_12631 = triangle(phasor_12632, ((t_sample)0.5));
			int trigger_beat_12570 = trigger_beat_12669;
			t_sample delta_12664 = __m_delta_189(wrap_12464);
			t_sample abs_12668 = fabs(delta_12664);
			int gt_12667 = (abs_12668 > ((t_sample)0.5));
			int change_12666 = __m_change_190(gt_12667);
			int gt_12665 = (change_12666 > ((int)0));
			int trigger_master_12671 = gt_12665;
			__m_count_191 = (trigger_master_12671 ? 0 : (fixdenorm(__m_count_191 + gt_12660)));
			int counter_12674 = __m_count_191;
			int counter_12675 = ((int)0);
			int counter_12676 = ((int)0);
			bool index_ignore_192 = ((counter_12674 >= kick_array_dim) || (counter_12674 < 0));
			// samples kick_array channel 1;
			int chan_193 = ((int)0);
			bool chan_ignore_194 = ((chan_193 < 0) || (chan_193 >= kick_array_channels));
			t_sample sample_kick_array_12597 = ((chan_ignore_194 || index_ignore_192) ? 0 : m_kick_array_53.read(counter_12674, chan_193));
			t_sample index_kick_array_12598 = counter_12674;
			t_sample kick_boolean_12596 = sample_kick_array_12597;
			__m_latch_195 = ((kick_boolean_12596 != 0) ? trigger_beat_12570 : __m_latch_195);
			t_sample latch_12595 = __m_latch_195;
			t_sample delta_12610 = __m_delta_196(latch_12595);
			t_sample abs_12586 = fabs(delta_12610);
			int gt_12585 = (abs_12586 > ((t_sample)0.5));
			int change_12584 = __m_change_197(gt_12585);
			int gt_12583 = (change_12584 > ((int)0));
			t_sample plusequals_12588 = __m_pluseq_198.post(safediv(8, samplerate), gt_12583, 0);
			t_sample clamp_12587 = ((plusequals_12588 <= ((int)0)) ? ((int)0) : ((plusequals_12588 >= ((int)1)) ? ((int)1) : plusequals_12588));
			t_sample sub_13009 = (clamp_12587 - ((int)0));
			t_sample scale_13006 = ((safepow((sub_13009 * ((t_sample)1)), (1 * ((t_sample)0.25))) * ((int)-1)) + ((int)1));
			t_sample scale_12589 = scale_13006;
			t_sample sub_13013 = (scale_12589 - ((int)1));
			t_sample scale_13010 = ((safepow((sub_13013 * ((t_sample)-1)), ((int)1)) * ((int)-100)) + ((int)150));
			t_sample scale_12592 = scale_13010;
			t_sample sin_12593 = sin(scale_12592);
			t_sample mul_12594 = (scale_12589 * sin_12593);
			t_sample mix_13014 = (mul_12594 + (((t_sample)0.9) * (m_history_1 - mul_12594)));
			t_sample mix_12591 = mix_13014;
			bool index_ignore_199 = ((counter_12674 >= hihat_array_dim) || (counter_12674 < 0));
			// samples hihat_array channel 1;
			int chan_200 = ((int)0);
			bool chan_ignore_201 = ((chan_200 < 0) || (chan_200 >= hihat_array_channels));
			t_sample sample_hihat_array_12672 = ((chan_ignore_201 || index_ignore_199) ? 0 : m_hihat_array_42.read(counter_12674, chan_200));
			t_sample index_hihat_array_12673 = counter_12674;
			__m_latch_202 = ((sample_hihat_array_12672 != 0) ? trigger_beat_12669 : __m_latch_202);
			t_sample latch_12677 = __m_latch_202;
			t_sample delta_12642 = __m_delta_203(latch_12677);
			t_sample abs_12646 = fabs(delta_12642);
			int gt_12645 = (abs_12646 > ((t_sample)0.5));
			int change_12644 = __m_change_204(gt_12645);
			int gt_12643 = (change_12644 > ((int)0));
			t_sample plusequals_12652 = __m_pluseq_205.post(((t_sample)0.0003239390994493), gt_12643, 0);
			t_sample clamp_12651 = ((plusequals_12652 <= ((int)0)) ? ((int)0) : ((plusequals_12652 >= ((int)1)) ? ((int)1) : plusequals_12652));
			t_sample sub_13018 = (clamp_12651 - ((int)0));
			t_sample scale_13015 = ((safepow((sub_13018 * ((t_sample)1)), (1 * ((t_sample)0.25))) * ((int)-1)) + ((int)1));
			t_sample mul_12656 = (scale_13015 * sub_12653);
			bool index_ignore_206 = ((counter_12674 >= snare_array_dim) || (counter_12674 < 0));
			// samples snare_array channel 1;
			int chan_207 = ((int)0);
			bool chan_ignore_208 = ((chan_207 < 0) || (chan_207 >= snare_array_channels));
			t_sample sample_snare_array_12685 = ((chan_ignore_208 || index_ignore_206) ? 0 : m_snare_array_35.read(counter_12674, chan_207));
			t_sample index_snare_array_12686 = counter_12674;
			__m_latch_209 = ((sample_snare_array_12685 != 0) ? trigger_beat_12669 : __m_latch_209);
			t_sample latch_12681 = __m_latch_209;
			t_sample delta_12569 = __m_delta_210(latch_12681);
			t_sample abs_12614 = fabs(delta_12569);
			int gt_12613 = (abs_12614 > ((t_sample)0.5));
			int change_12612 = __m_change_211(gt_12613);
			int gt_12611 = (change_12612 > ((int)0));
			t_sample plusequals_12636 = __m_pluseq_212.post(safediv(13, samplerate), gt_12611, 0);
			t_sample clamp_12635 = ((plusequals_12636 <= ((int)0)) ? ((int)0) : ((plusequals_12636 >= ((int)1)) ? ((int)1) : plusequals_12636));
			t_sample sub_13022 = (clamp_12635 - ((int)0));
			t_sample scale_13019 = ((safepow((sub_13022 * ((t_sample)1)), (1 * ((t_sample)0.5))) * ((int)-1)) + ((int)1));
			t_sample mul_12639 = (scale_13019 * triangle_12633);
			t_sample plusequals_12621 = __m_pluseq_213.post(safediv(7, samplerate), gt_12611, 0);
			t_sample clamp_12619 = ((plusequals_12621 <= ((int)0)) ? ((int)0) : ((plusequals_12621 >= ((int)1)) ? ((int)1) : plusequals_12621));
			t_sample sub_13026 = (clamp_12619 - ((int)0));
			t_sample scale_13023 = ((safepow((sub_13026 * ((t_sample)1)), (1 * ((t_sample)0.5))) * ((t_sample)-0.5)) + ((t_sample)0.5));
			t_sample mul_12618 = (scale_13023 * sub_12615);
			t_sample plusequals_12629 = __m_pluseq_214.post(safediv(8, samplerate), gt_12611, 0);
			t_sample clamp_12625 = ((plusequals_12629 <= ((int)0)) ? ((int)0) : ((plusequals_12629 >= ((int)1)) ? ((int)1) : plusequals_12629));
			t_sample sub_13030 = (clamp_12625 - ((int)0));
			t_sample scale_13027 = ((safepow((sub_13030 * ((t_sample)1)), (1 * ((t_sample)0.5))) * ((t_sample)-0.7)) + ((t_sample)0.7));
			t_sample mul_12623 = (scale_13027 * mix_12617);
			t_sample plusequals_12630 = __m_pluseq_215.post(safediv(11, samplerate), gt_12611, 0);
			t_sample clamp_12627 = ((plusequals_12630 <= ((int)0)) ? ((int)0) : ((plusequals_12630 >= ((int)1)) ? ((int)1) : plusequals_12630));
			t_sample sub_13034 = (clamp_12627 - ((int)0));
			t_sample scale_13031 = ((safepow((sub_13034 * ((t_sample)1)), (1 * ((t_sample)0.5))) * ((int)-1)) + ((int)1));
			t_sample mul_12624 = (scale_13031 * triangle_12631);
			t_sample v_216 = (((mul_12624 + mul_12623) + mul_12618) + mul_12639);
			int min_217 = (-1);
			t_sample clamp_12622 = ((v_216 <= min_217) ? min_217 : ((v_216 >= ((int)1)) ? ((int)1) : v_216));
			t_sample add_12536 = (mul_12656 + clamp_12622);
			t_sample mul_12528 = (add_12536 * ((t_sample)0.5));
			t_sample add_12535 = (mul_12528 + mix_12591);
			t_sample mul_12527 = (add_12535 * ((t_sample)0.5));
			t_sample mix_13035 = (mul_12527 + (((t_sample)0.5) * (in1 - mul_12527)));
			t_sample out1 = mix_13035;
			t_sample add_12533 = (mul_12656 + clamp_12622);
			t_sample mul_12529 = (add_12533 * ((t_sample)0.5));
			t_sample add_12532 = (mul_12529 + mix_12591);
			t_sample mul_12526 = (add_12532 * ((t_sample)0.5));
			t_sample mix_13036 = (mul_12526 + (((t_sample)0.5) * (in2 - mul_12526)));
			t_sample out2 = mix_13036;
			t_sample history_12654_next_12746 = fixdenorm(mix_12655);
			t_sample history_12616_next_12747 = fixdenorm(mix_12617);
			t_sample history_12637_next_12748 = fixdenorm(mix_12638);
			t_sample history_12465_next_12749 = fixdenorm(wrap_12464);
			t_sample history_12590_next_12750 = fixdenorm(mix_12591);
			m_y_26 = y_next_12494;
			m_z_24 = z_next_12496;
			m_x_25 = x_next_12495;
			m_history_23 = history_12502_next_12509;
			m_history_22 = history_12505_next_12510;
			m_history_5 = history_12654_next_12746;
			m_history_4 = history_12616_next_12747;
			m_history_3 = history_12637_next_12748;
			m_history_2 = history_12465_next_12749;
			m_history_1 = history_12590_next_12750;
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
			(*(__out13++)) = out13;
			(*(__out14++)) = out14;
			(*(__out15++)) = out15;
			(*(__out16++)) = out16;
			(*(__out17++)) = out17;
			(*(__out18++)) = out18;
			(*(__out19++)) = out19;
			(*(__out20++)) = out20;
			(*(__out21++)) = out21;
			(*(__out22++)) = out22;
			(*(__out23++)) = out23;
			(*(__out24++)) = out24;
			(*(__out25++)) = out25;
			(*(__out26++)) = out26;
			(*(__out27++)) = out27;
			(*(__out28++)) = out28;
			(*(__out29++)) = out29;
			(*(__out30++)) = out30;
			(*(__out31++)) = out31;
			(*(__out32++)) = out32;
			(*(__out33++)) = out33;
			(*(__out34++)) = out34;
			
		};
		return __exception;
		
	};
	inline void set_mix(t_param _value) {
		m_mix_27 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_swing(t_param _value) {
		m_knob4_swing_28 = (_value < 1 ? 1 : (_value > 0 ? 0 : _value));
	};
	inline void set_sw2(t_param _value) {
		m_sw_29 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw6(t_param _value) {
		m_sw_30 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_snare_patterns(void * _value) {
		m_snare_patterns_31.setbuffer(_value);
	};
	inline void set_sw7(t_param _value) {
		m_sw_32 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw4(t_param _value) {
		m_sw_33 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_noise_array(void * _value) {
		m_noise_array_34.setbuffer(_value);
	};
	inline void set_snare_array(void * _value) {
		m_snare_array_35.setbuffer(_value);
	};
	inline void set_sw5(t_param _value) {
		m_sw_36 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_grid_matrix_noise(void * _value) {
		m_grid_matrix_noise_37.setbuffer(_value);
	};
	inline void set_knob6_hihatDensity(t_param _value) {
		m_knob6_hihatDensity_38 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw8(t_param _value) {
		m_sw_39 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw3(t_param _value) {
		m_sw_40 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_Y(t_param _value) {
		m_knob3_Y_41 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_hihat_array(void * _value) {
		m_hihat_array_42.setbuffer(_value);
	};
	inline void set_hihat_patterns(void * _value) {
		m_hihat_patterns_43.setbuffer(_value);
	};
	inline void set_knob2_X(t_param _value) {
		m_knob2_X_44 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_kick_array(void * _value) {
		m_kick_array_53.setbuffer(_value);
	};
	inline void set_knob5_snareDensity(t_param _value) {
		m_knob5_snareDensity_54 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_hihat_hit_values(void * _value) {
		m_hihat_hit_values_55.setbuffer(_value);
	};
	inline void set_knob1_bpm(t_param _value) {
		m_knob1_bpm_56 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_57 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_snare_hit_values(void * _value) {
		m_snare_hit_values_58.setbuffer(_value);
	};
	
} State;


///
///	Configuration for the genlib API
///

/// Number of signal inputs and outputs

int gen_kernel_numins = 2;
int gen_kernel_numouts = 34;

int num_inputs() { return gen_kernel_numins; }
int num_outputs() { return gen_kernel_numouts; }
int num_params() { return 24; }

/// Assistive lables for the signal inputs and outputs

const char *gen_kernel_innames[] = { "audio_l", "audio_r" };
const char *gen_kernel_outnames[] = { "sound_l", "sound_r", "led1", "led2", "led3", "led4", "led5", "led6", "led7", "led8", "sn1", "sn2", "sn3", "sn4", "sn5", "sn6", "sn7", "sn8", "hi1", "hi2", "hi3", "hi4", "hi5", "hi6", "hi7", "hi8", "trigger_b", "step_value", "x_pos", "y_pos", "out31", "out32", "cvout1", "cvout2" };

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
		case 0: self->set_grid_matrix_noise(ref); break;
		case 1: self->set_hihat_array(ref); break;
		case 2: self->set_hihat_hit_values(ref); break;
		case 3: self->set_hihat_patterns(ref); break;
		case 4: self->set_kick_array(ref); break;
		case 5: self->set_knob1_bpm(value); break;
		case 6: self->set_knob2_X(value); break;
		case 7: self->set_knob3_Y(value); break;
		case 8: self->set_knob4_swing(value); break;
		case 9: self->set_knob5_snareDensity(value); break;
		case 10: self->set_knob6_hihatDensity(value); break;
		case 11: self->set_mix(value); break;
		case 12: self->set_noise_array(ref); break;
		case 13: self->set_snare_array(ref); break;
		case 14: self->set_snare_hit_values(ref); break;
		case 15: self->set_snare_patterns(ref); break;
		case 16: self->set_sw1(value); break;
		case 17: self->set_sw2(value); break;
		case 18: self->set_sw3(value); break;
		case 19: self->set_sw4(value); break;
		case 20: self->set_sw5(value); break;
		case 21: self->set_sw6(value); break;
		case 22: self->set_sw7(value); break;
		case 23: self->set_sw8(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		
		
		
		
		
		case 5: *value = self->m_knob1_bpm_56; break;
		case 6: *value = self->m_knob2_X_44; break;
		case 7: *value = self->m_knob3_Y_41; break;
		case 8: *value = self->m_knob4_swing_28; break;
		case 9: *value = self->m_knob5_snareDensity_54; break;
		case 10: *value = self->m_knob6_hihatDensity_38; break;
		case 11: *value = self->m_mix_27; break;
		
		
		
		
		case 16: *value = self->m_sw_57; break;
		case 17: *value = self->m_sw_29; break;
		case 18: *value = self->m_sw_40; break;
		case 19: *value = self->m_sw_33; break;
		case 20: *value = self->m_sw_36; break;
		case 21: *value = self->m_sw_30; break;
		case 22: *value = self->m_sw_32; break;
		case 23: *value = self->m_sw_39; break;
		
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
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(24 * sizeof(ParamInfo));
	self->__commonstate.numparams = 24;
	// initialize parameter 0 ("m_grid_matrix_noise_37")
	pi = self->__commonstate.params + 0;
	pi->name = "grid_matrix_noise";
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
	// initialize parameter 1 ("m_hihat_array_42")
	pi = self->__commonstate.params + 1;
	pi->name = "hihat_array";
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
	// initialize parameter 2 ("m_hihat_hit_values_55")
	pi = self->__commonstate.params + 2;
	pi->name = "hihat_hit_values";
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
	// initialize parameter 3 ("m_hihat_patterns_43")
	pi = self->__commonstate.params + 3;
	pi->name = "hihat_patterns";
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
	// initialize parameter 4 ("m_kick_array_53")
	pi = self->__commonstate.params + 4;
	pi->name = "kick_array";
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
	// initialize parameter 5 ("m_knob1_bpm_56")
	pi = self->__commonstate.params + 5;
	pi->name = "knob1_bpm";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob1_bpm_56;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_knob2_X_44")
	pi = self->__commonstate.params + 6;
	pi->name = "knob2_X";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob2_X_44;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 7 ("m_knob3_Y_41")
	pi = self->__commonstate.params + 7;
	pi->name = "knob3_Y";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_Y_41;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 8 ("m_knob4_swing_28")
	pi = self->__commonstate.params + 8;
	pi->name = "knob4_swing";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_swing_28;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1;
	pi->outputmax = 0;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 9 ("m_knob5_snareDensity_54")
	pi = self->__commonstate.params + 9;
	pi->name = "knob5_snareDensity";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_snareDensity_54;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 10 ("m_knob6_hihatDensity_38")
	pi = self->__commonstate.params + 10;
	pi->name = "knob6_hihatDensity";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_hihatDensity_38;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 11 ("m_mix_27")
	pi = self->__commonstate.params + 11;
	pi->name = "mix";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_mix_27;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 12 ("m_noise_array_34")
	pi = self->__commonstate.params + 12;
	pi->name = "noise_array";
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
	// initialize parameter 13 ("m_snare_array_35")
	pi = self->__commonstate.params + 13;
	pi->name = "snare_array";
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
	// initialize parameter 14 ("m_snare_hit_values_58")
	pi = self->__commonstate.params + 14;
	pi->name = "snare_hit_values";
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
	// initialize parameter 15 ("m_snare_patterns_31")
	pi = self->__commonstate.params + 15;
	pi->name = "snare_patterns";
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
	// initialize parameter 16 ("m_sw_57")
	pi = self->__commonstate.params + 16;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_57;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 17 ("m_sw_29")
	pi = self->__commonstate.params + 17;
	pi->name = "sw2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_29;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 18 ("m_sw_40")
	pi = self->__commonstate.params + 18;
	pi->name = "sw3";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_40;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 19 ("m_sw_33")
	pi = self->__commonstate.params + 19;
	pi->name = "sw4";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_33;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 20 ("m_sw_36")
	pi = self->__commonstate.params + 20;
	pi->name = "sw5";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_36;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 21 ("m_sw_30")
	pi = self->__commonstate.params + 21;
	pi->name = "sw6";
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
	// initialize parameter 22 ("m_sw_32")
	pi = self->__commonstate.params + 22;
	pi->name = "sw7";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_32;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 23 ("m_sw_39")
	pi = self->__commonstate.params + 23;
	pi->name = "sw8";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_39;
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


} // KHAIROS::
