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
	Change __m_change_74;
	Change __m_change_71;
	Change __m_change_70;
	Change __m_change_69;
	Change __m_change_68;
	Change __m_change_135;
	Change __m_change_100;
	Change __m_change_101;
	Change __m_change_93;
	Change __m_change_72;
	Change __m_change_73;
	Change __m_change_140;
	Change __m_change_145;
	Change __m_change_150;
	Change __m_change_155;
	Change __m_change_67;
	Data m_hihat_hit_values_48;
	Data m_noise_array_47;
	Data m_snare_hit_values_51;
	Data m_snare_array_52;
	Data m_snare_patterns_28;
	Data m_hihat_patterns_58;
	Data m_grid_matrix_noise_49;
	Data m_kick_array_40;
	Data m_hihat_array_45;
	Delta __m_delta_92;
	Delta __m_delta_149;
	Delta __m_delta_154;
	Delta __m_delta_144;
	Delta __m_delta_139;
	Delta __m_delta_99;
	Phasor __m_phasor_91;
	Phasor __m_phasor_137;
	Phasor __m_phasor_138;
	PlusEquals __m_pluseq_156;
	PlusEquals __m_pluseq_157;
	PlusEquals __m_pluseq_158;
	PlusEquals __m_pluseq_151;
	PlusEquals __m_pluseq_136;
	PlusEquals __m_pluseq_146;
	PlusEquals __m_pluseq_159;
	int __exception;
	int vectorsize;
	int __loopcount;
	t_sample m_hit_8_snare_14;
	t_sample m_hit_1_hihat_13;
	t_sample m_hit_2_hihat_12;
	t_sample m_hit_3_hihat_11;
	t_sample __m_latch_134;
	t_sample m_hit_7_snare_15;
	t_sample m_hit_6_snare_16;
	t_sample m_hit_4_snare_18;
	t_sample m_hit_4_hihat_10;
	t_sample __m_count_94;
	t_sample m_hit_5_snare_17;
	t_sample __m_carry_96;
	t_sample m_hit_3_snare_19;
	t_sample m_hit_5_hihat_9;
	t_sample __m_latch_143;
	t_sample __m_latch_153;
	t_sample m_history_3;
	t_sample m_history_2;
	t_sample samplerate;
	t_sample m_history_1;
	t_sample __m_count_141;
	t_sample m_history_4;
	t_sample __m_latch_148;
	t_sample m_hit_6_hihat_8;
	t_sample m_history_5;
	t_sample m_hit_7_hihat_7;
	t_sample m_hit_8_hihat_6;
	t_sample m_hit_2_snare_20;
	t_sample samples_to_seconds;
	t_sample m_hit_1_snare_21;
	t_sample m_led_34;
	t_sample m_led_35;
	t_sample m_led_33;
	t_sample m_led_32;
	t_sample m_sw_50;
	t_sample m_sw_31;
	t_sample m_sw_46;
	t_sample m_knob2_X_44;
	t_sample m_led_37;
	t_sample m_led_36;
	t_sample m_knob4_swing_41;
	t_sample m_knob3_Y_43;
	t_sample m_knob6_hihatDensity_42;
	t_sample m_led_38;
	t_sample m_knob1_bpm_53;
	t_sample m_sw_55;
	t_sample m_x_25;
	t_sample m_y_26;
	t_sample m_z_24;
	t_sample m_history_22;
	t_sample m_history_23;
	t_sample m_knob5_snareDensity_54;
	t_sample m_mix_27;
	t_sample elapsed;
	t_sample m_sw_56;
	t_sample m_sw_29;
	t_sample m_sw_57;
	t_sample m_sw_30;
	t_sample m_led_39;
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
		m_snare_patterns_28.reset("snare_patterns", ((int)8), ((int)64));
		m_sw_29 = ((int)0);
		m_sw_30 = ((int)0);
		m_sw_31 = ((int)0);
		m_led_32 = ((int)0);
		m_led_33 = ((int)0);
		m_led_34 = ((int)0);
		m_led_35 = ((int)0);
		m_led_36 = ((int)0);
		m_led_37 = ((int)0);
		m_led_38 = ((int)0);
		m_led_39 = ((int)0);
		m_kick_array_40.reset("kick_array", ((int)8), ((int)1));
		m_knob4_swing_41 = ((int)0);
		m_knob6_hihatDensity_42 = ((int)1);
		m_knob3_Y_43 = ((int)0);
		m_knob2_X_44 = ((int)0);
		m_hihat_array_45.reset("hihat_array", ((int)8), ((int)2));
		m_sw_46 = ((int)0);
		m_noise_array_47.reset("noise_array", ((int)48000), ((int)1));
		m_hihat_hit_values_48.reset("hihat_hit_values", ((int)8), ((int)64));
		m_grid_matrix_noise_49.reset("grid_matrix_noise", ((int)64), ((int)1));
		m_sw_50 = ((int)0);
		m_snare_hit_values_51.reset("snare_hit_values", ((int)8), ((int)64));
		m_snare_array_52.reset("snare_array", ((int)8), ((int)2));
		m_knob1_bpm_53 = ((int)0);
		m_knob5_snareDensity_54 = ((int)1);
		m_sw_55 = ((int)0);
		m_sw_56 = ((int)0);
		m_sw_57 = ((int)0);
		m_hihat_patterns_58.reset("hihat_patterns", ((int)8), ((int)64));
		elapsed = 0;
		__m_change_67.reset(0);
		__m_change_68.reset(0);
		__m_change_69.reset(0);
		__m_change_70.reset(0);
		__m_change_71.reset(0);
		__m_change_72.reset(0);
		__m_change_73.reset(0);
		__m_change_74.reset(0);
		samples_to_seconds = (1 / samplerate);
		__m_phasor_91.reset(0);
		__m_delta_92.reset(0);
		__m_change_93.reset(0);
		__m_count_94 = 0;
		__m_carry_96 = 0;
		__m_delta_99.reset(0);
		__m_change_100.reset(0);
		__m_change_101.reset(0);
		__m_latch_134 = 0;
		__m_change_135.reset(0);
		__m_pluseq_136.reset(0);
		__m_phasor_137.reset(0);
		__m_phasor_138.reset(0);
		__m_delta_139.reset(0);
		__m_change_140.reset(0);
		__m_count_141 = 0;
		__m_latch_143 = 0;
		__m_delta_144.reset(0);
		__m_change_145.reset(0);
		__m_pluseq_146.reset(0);
		__m_latch_148 = 0;
		__m_delta_149.reset(0);
		__m_change_150.reset(0);
		__m_pluseq_151.reset(0);
		__m_latch_153 = 0;
		__m_delta_154.reset(0);
		__m_change_155.reset(0);
		__m_pluseq_156.reset(0);
		__m_pluseq_157.reset(0);
		__m_pluseq_158.reset(0);
		__m_pluseq_159.reset(0);
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
		t_sample sub_2481 = (m_knob2_X_44 - ((int)0));
		t_sample scale_2478 = ((safepow((sub_2481 * ((t_sample)1)), ((int)1)) * ((int)7)) + ((int)1));
		t_sample expr_1380 = round(scale_2478);
		t_sample sub_2485 = (m_knob3_Y_43 - ((int)0));
		t_sample scale_2482 = ((safepow((sub_2485 * ((t_sample)1)), ((int)1)) * ((int)7)) + ((int)1));
		t_sample expr_1381 = round(scale_2482);
		int iftrue_90 = (-10000000000);
		t_sample mstosamps_1144 = (((int)1) * (samplerate * 0.001));
		t_sample max_1145 = ((mstosamps_1144 < vectorsize) ? vectorsize : mstosamps_1144);
		t_sample sub_2502 = (m_knob1_bpm_53 - ((int)0));
		t_sample scale_2499 = ((safepow((sub_2502 * ((t_sample)1)), ((int)1)) * ((int)-460)) + ((int)500));
		t_sample scale_1235 = scale_2499;
		t_sample div_1336 = (scale_1235 * ((t_sample)0.016666666666667));
		t_sample div_1197 = (div_1336 * ((t_sample)0.125));
		t_sample div_1076 = safediv(div_1197, samplerate);
		samples_to_seconds = (1 / samplerate);
		int grid_matrix_noise_dim = m_grid_matrix_noise_49.dim;
		int grid_matrix_noise_channels = m_grid_matrix_noise_49.channels;
		int kick_array_dim = m_kick_array_40.dim;
		int kick_array_channels = m_kick_array_40.channels;
		int hihat_array_dim = m_hihat_array_45.dim;
		int hihat_array_channels = m_hihat_array_45.channels;
		int snare_array_dim = m_snare_array_52.dim;
		int snare_array_channels = m_snare_array_52.channels;
		int min_161 = (-1);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
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
					int i = ((int)0);
					// for loop condition;
					while ((i < ((int)8))) {
						// abort processing if an infinite loop is suspected;
						if (((__loopcount--) <= 0)) {
							__exception = GENLIB_ERR_LOOP_OVERFLOW;
							break ;
							
						};
						t_sample noise_2459 = noise();
						t_sample sub_2462 = (noise_2459 - (-1));
						t_sample scale_2458 = ((safepow((sub_2462 * ((t_sample)0.5)), ((int)1)) * ((t_sample)0.85)) + ((t_sample)0.1));
						t_sample noise_2469 = noise();
						t_sample sub_2472 = (noise_2469 - (-1));
						t_sample scale_2468 = ((safepow((sub_2472 * ((t_sample)0.5)), ((int)1)) * ((t_sample)0.85)) + ((t_sample)0.1));
						int snare_patterns_dim = m_snare_patterns_28.dim;
						int snare_patterns_channels = m_snare_patterns_28.channels;
						bool chan_ignore_59 = ((c < 0) || (c >= snare_patterns_channels));
						bool index_ignore_60 = ((i >= snare_patterns_dim) || (i < 0));
						if ((!(chan_ignore_59 || index_ignore_60))) {
							m_snare_patterns_28.write(((int)1), i, c);
							
						};
						int snare_hit_values_dim = m_snare_hit_values_51.dim;
						int snare_hit_values_channels = m_snare_hit_values_51.channels;
						bool chan_ignore_61 = ((c < 0) || (c >= snare_hit_values_channels));
						bool index_ignore_62 = ((i >= snare_hit_values_dim) || (i < 0));
						if ((!(chan_ignore_61 || index_ignore_62))) {
							m_snare_hit_values_51.write(scale_2458, i, c);
							
						};
						int hihat_patterns_dim = m_hihat_patterns_58.dim;
						int hihat_patterns_channels = m_hihat_patterns_58.channels;
						bool chan_ignore_63 = ((c < 0) || (c >= hihat_patterns_channels));
						bool index_ignore_64 = ((i >= hihat_patterns_dim) || (i < 0));
						if ((!(chan_ignore_63 || index_ignore_64))) {
							m_hihat_patterns_58.write(((int)1), i, c);
							
						};
						int hihat_hit_values_dim = m_hihat_hit_values_48.dim;
						int hihat_hit_values_channels = m_hihat_hit_values_48.channels;
						bool chan_ignore_65 = ((c < 0) || (c >= hihat_hit_values_channels));
						bool index_ignore_66 = ((i >= hihat_hit_values_dim) || (i < 0));
						if ((!(chan_ignore_65 || index_ignore_66))) {
							m_hihat_hit_values_48.write(scale_2468, i, c);
							
						};
						// for loop increment;
						i = (i + ((int)1));
						
					};
					// for loop increment;
					c = (c + ((int)1));
					
				};
				
			};
			// abort processing if an infinite loop is suspected;
			if (((__loopcount--) <= 0)) {
				__exception = GENLIB_ERR_LOOP_OVERFLOW;
				break ;
				
			};
			t_sample out29 = expr_1380;
			int sw_1 = (__m_change_67((m_sw_55 > ((int)0))) > ((int)0));
			int sw_2 = (__m_change_68((m_sw_31 > ((int)0))) > ((int)0));
			int sw_3 = (__m_change_69((m_sw_46 > ((int)0))) > ((int)0));
			int sw_4 = (__m_change_70((m_sw_30 > ((int)0))) > ((int)0));
			int sw_5 = (__m_change_71((m_sw_29 > ((int)0))) > ((int)0));
			int sw_6 = (__m_change_72((m_sw_57 > ((int)0))) > ((int)0));
			int sw_7 = (__m_change_73((m_sw_56 > ((int)0))) > ((int)0));
			int sw_8 = (__m_change_74((m_sw_50 > ((int)0))) > ((int)0));
			if ((elapsed == ((int)0))) {
				// for loop initializer;
				int i_1409 = ((int)0);
				// for loop condition;
				int kick_array_dim = m_kick_array_40.dim;
				int kick_array_channels = m_kick_array_40.channels;
				while ((i_1409 < kick_array_dim)) {
					// abort processing if an infinite loop is suspected;
					if (((__loopcount--) <= 0)) {
						__exception = GENLIB_ERR_LOOP_OVERFLOW;
						break ;
						
					};
					bool index_ignore_75 = ((i_1409 >= kick_array_dim) || (i_1409 < 0));
					if ((!index_ignore_75)) {
						m_kick_array_40.write(((int)0), i_1409, 0);
						
					};
					// for loop increment;
					i_1409 = (i_1409 + ((int)1));
					
				};
				m_led_39 = ((int)1);
				m_led_38 = ((int)1);
				m_led_37 = ((int)1);
				m_led_36 = ((int)1);
				m_led_35 = ((int)1);
				m_led_34 = ((int)1);
				m_led_33 = ((int)1);
				m_led_32 = ((int)1);
				
			};
			if (sw_1) {
				int kick_array_dim = m_kick_array_40.dim;
				int kick_array_channels = m_kick_array_40.channels;
				// samples kick_array channel 1;
				t_sample a = m_kick_array_40.read(0, 0);
				m_kick_array_40.write((!a), 0, 0);
				m_led_39 = a;
				
			};
			if (sw_2) {
				int kick_array_dim = m_kick_array_40.dim;
				int kick_array_channels = m_kick_array_40.channels;
				bool index_ignore_76 = (((int)1) >= kick_array_dim);
				// samples kick_array channel 1;
				t_sample a = (index_ignore_76 ? 0 : m_kick_array_40.read(((int)1), 0));
				bool index_ignore_77 = (((int)1) >= kick_array_dim);
				if ((!index_ignore_77)) {
					m_kick_array_40.write((!a), ((int)1), 0);
					
				};
				m_led_38 = a;
				
			};
			if (sw_3) {
				int kick_array_dim = m_kick_array_40.dim;
				int kick_array_channels = m_kick_array_40.channels;
				bool index_ignore_78 = (((int)2) >= kick_array_dim);
				// samples kick_array channel 1;
				t_sample a = (index_ignore_78 ? 0 : m_kick_array_40.read(((int)2), 0));
				bool index_ignore_79 = (((int)2) >= kick_array_dim);
				if ((!index_ignore_79)) {
					m_kick_array_40.write((!a), ((int)2), 0);
					
				};
				m_led_37 = a;
				
			};
			if (sw_4) {
				int kick_array_dim = m_kick_array_40.dim;
				int kick_array_channels = m_kick_array_40.channels;
				bool index_ignore_80 = (((int)3) >= kick_array_dim);
				// samples kick_array channel 1;
				t_sample a = (index_ignore_80 ? 0 : m_kick_array_40.read(((int)3), 0));
				bool index_ignore_81 = (((int)3) >= kick_array_dim);
				if ((!index_ignore_81)) {
					m_kick_array_40.write((!a), ((int)3), 0);
					
				};
				m_led_36 = a;
				
			};
			if (sw_5) {
				int kick_array_dim = m_kick_array_40.dim;
				int kick_array_channels = m_kick_array_40.channels;
				bool index_ignore_82 = (((int)4) >= kick_array_dim);
				// samples kick_array channel 1;
				t_sample a = (index_ignore_82 ? 0 : m_kick_array_40.read(((int)4), 0));
				bool index_ignore_83 = (((int)4) >= kick_array_dim);
				if ((!index_ignore_83)) {
					m_kick_array_40.write((!a), ((int)4), 0);
					
				};
				m_led_35 = a;
				
			};
			if (sw_6) {
				int kick_array_dim = m_kick_array_40.dim;
				int kick_array_channels = m_kick_array_40.channels;
				bool index_ignore_84 = (((int)5) >= kick_array_dim);
				// samples kick_array channel 1;
				t_sample a = (index_ignore_84 ? 0 : m_kick_array_40.read(((int)5), 0));
				bool index_ignore_85 = (((int)5) >= kick_array_dim);
				if ((!index_ignore_85)) {
					m_kick_array_40.write((!a), ((int)5), 0);
					
				};
				m_led_34 = a;
				
			};
			if (sw_7) {
				int kick_array_dim = m_kick_array_40.dim;
				int kick_array_channels = m_kick_array_40.channels;
				bool index_ignore_86 = (((int)6) >= kick_array_dim);
				// samples kick_array channel 1;
				t_sample a = (index_ignore_86 ? 0 : m_kick_array_40.read(((int)6), 0));
				bool index_ignore_87 = (((int)6) >= kick_array_dim);
				if ((!index_ignore_87)) {
					m_kick_array_40.write((!a), ((int)6), 0);
					
				};
				m_led_33 = a;
				
			};
			if (sw_8) {
				int kick_array_dim = m_kick_array_40.dim;
				int kick_array_channels = m_kick_array_40.channels;
				bool index_ignore_88 = (((int)7) >= kick_array_dim);
				// samples kick_array channel 1;
				t_sample a = (index_ignore_88 ? 0 : m_kick_array_40.read(((int)7), 0));
				bool index_ignore_89 = (((int)7) >= kick_array_dim);
				if ((!index_ignore_89)) {
					m_kick_array_40.write((!a), ((int)7), 0);
					
				};
				m_led_32 = a;
				
			};
			t_sample expr_1383 = m_led_39;
			t_sample expr_1384 = m_led_38;
			t_sample expr_1385 = m_led_37;
			t_sample expr_1386 = m_led_36;
			t_sample expr_1387 = m_led_35;
			t_sample expr_1388 = m_led_34;
			t_sample expr_1389 = m_led_33;
			t_sample expr_1390 = m_led_32;
			t_sample out30 = expr_1381;
			t_sample noise_1283 = noise();
			t_sample mix_2492 = (noise_1283 + (((t_sample)0.7) * (m_history_5 - noise_1283)));
			t_sample mix_1281 = mix_2492;
			t_sample noise_1266 = noise();
			t_sample mix_2493 = (noise_1266 + (((t_sample)0.5) * (m_history_4 - noise_1266)));
			t_sample mix_1243 = mix_2493;
			t_sample mix_2494 = (mix_1243 + (((t_sample)0.6) * (m_history_3 - mix_1243)));
			t_sample mix_1264 = mix_2494;
			int or_1082 = (((int)0) || (elapsed == ((int)0)));
			t_sample switch_1084 = (or_1082 ? ((t_sample)0.41) : m_y_26);
			t_sample mul_1097 = (switch_1084 * ((int)1));
			t_sample switch_1083 = (or_1082 ? ((t_sample)0.1) : m_x_25);
			t_sample switch_1085 = (or_1082 ? ((t_sample)0.31) : m_z_24);
			t_sample mul_1102 = (switch_1085 * ((int)1));
			t_sample mul_1105 = (mul_1102 * ((t_sample)0.0002));
			t_sample add_1099 = (switch_1084 + mul_1105);
			t_sample fixnan_1088 = fixnan(add_1099);
			t_sample gen_1117 = fixnan_1088;
			t_sample mul_1106 = (mul_1097 * ((t_sample)0.0002));
			t_sample add_1100 = (switch_1083 + mul_1106);
			t_sample fixnan_1086 = fixnan(add_1100);
			t_sample mul_1094 = (switch_1085 * (-0.45));
			t_sample pow_1092 = safepow(switch_1083, ((int)3));
			t_sample mul_1093 = (pow_1092 * (-1));
			t_sample mul_1096 = (switch_1083 * ((t_sample)0.8));
			t_sample mul_1095 = (switch_1084 * (-1.1));
			t_sample add_1091 = (mul_1096 + mul_1095);
			t_sample add_1090 = (add_1091 + mul_1094);
			t_sample add_1089 = (add_1090 + mul_1093);
			t_sample mul_1104 = (add_1089 * ((t_sample)0.0002));
			t_sample add_1098 = (switch_1085 + mul_1104);
			t_sample fixnan_1087 = fixnan(add_1098);
			t_sample y_next_1113 = fixdenorm(fixnan_1088);
			t_sample x_next_1114 = fixdenorm(fixnan_1086);
			t_sample z_next_1115 = fixdenorm(fixnan_1087);
			t_sample elapsed_1120 = elapsed;
			int eq_1119 = (elapsed_1120 == ((int)0));
			int or_1127 = (eq_1119 || ((int)0));
			t_sample switch_1122 = (or_1127 ? iftrue_90 : m_history_23);
			t_sample max_1125 = ((gen_1117 < switch_1122) ? switch_1122 : gen_1117);
			t_sample gen_1135 = max_1125;
			t_sample switch_1123 = (or_1127 ? ((int)10000000000) : m_history_22);
			t_sample min_1126 = ((switch_1123 < gen_1117) ? switch_1123 : gen_1117);
			t_sample gen_1134 = min_1126;
			t_sample history_1124_next_1132 = fixdenorm(max_1125);
			t_sample history_1121_next_1133 = fixdenorm(min_1126);
			t_sample irange_2496 = (gen_1135 - gen_1134);
			t_sample sub_2498 = (gen_1117 - gen_1134);
			t_sample scale_2495 = ((safepow(safediv(sub_2498, irange_2496), ((int)1)) * ((int)2)) + ((int)-1));
			t_sample scale_1136 = scale_2495;
			t_sample gen_1140 = scale_1136;
			t_sample mul_1074 = (m_knob4_swing_41 * gen_1140);
			t_sample out33 = mul_1074;
			t_sample sub_1279 = (noise_1283 - mix_1281);
			t_sample mul_1080 = (div_1076 * mul_1074);
			t_sample add_1075 = (div_1076 + mul_1080);
			t_sample add_1079 = (m_history_2 + add_1075);
			t_sample wrap_1077 = wrap(add_1079, ((int)0), ((int)1));
			t_sample mul_1334 = (wrap_1077 * ((int)8));
			t_sample floor_1333 = floor(mul_1334);
			t_sample out28 = floor_1333;
			t_sample phasor_1173 = __m_phasor_91(((int)5000), samples_to_seconds);
			t_sample delta_1168 = __m_delta_92(phasor_1173);
			t_sample abs_1172 = fabs(delta_1168);
			int gt_1171 = (abs_1172 > ((t_sample)0.5));
			int change_1170 = __m_change_93(gt_1171);
			int gt_1169 = (change_1170 > ((int)0));
			__m_count_94 = (((int)0) ? 0 : (fixdenorm(__m_count_94 + gt_1169)));
			int carry_95 = 0;
			if ((((int)0) != 0)) {
				__m_count_94 = 0;
				__m_carry_96 = 0;
				
			} else if (((((int)63) > 0) && (__m_count_94 >= ((int)63)))) {
				int wraps_97 = (__m_count_94 / ((int)63));
				__m_carry_96 = (__m_carry_96 + wraps_97);
				__m_count_94 = (__m_count_94 - (wraps_97 * ((int)63)));
				carry_95 = 1;
				
			};
			int counter_1177 = __m_count_94;
			int counter_1178 = carry_95;
			int counter_1179 = __m_carry_96;
			bool index_ignore_98 = ((counter_1177 >= grid_matrix_noise_dim) || (counter_1177 < 0));
			// samples grid_matrix_noise channel 1;
			t_sample sample_grid_matrix_noise_1174 = (index_ignore_98 ? 0 : m_grid_matrix_noise_49.read(counter_1177, 0));
			t_sample index_grid_matrix_noise_1175 = counter_1177;
			t_sample out32 = sample_grid_matrix_noise_1174;
			int add_1167 = (counter_1177 + ((int)1));
			t_sample out31 = add_1167;
			t_sample sub_1241 = (mix_1243 - mix_1264);
			t_sample wrap_1310 = wrap(mul_1334, ((int)0), ((int)1));
			t_sample delta_1285 = __m_delta_99(wrap_1310);
			t_sample abs_1289 = fabs(delta_1285);
			int gt_1288 = (abs_1289 > ((t_sample)0.5));
			int change_1287 = __m_change_100(gt_1288);
			int gt_1286 = (change_1287 > ((int)0));
			int trigger_beat_1295 = gt_1286;
			int trigger_beat_1309 = trigger_beat_1295;
			t_sample out27 = trigger_beat_1309;
			int trig = (__m_change_101((trigger_beat_1309 > ((int)0))) > ((int)0));
			if (trig) {
				int snare_array_dim = m_snare_array_52.dim;
				int snare_array_channels = m_snare_array_52.channels;
				// samples snare_array channel 1;
				m_hit_1_snare_21 = m_snare_array_52.read(0, 0);
				bool index_ignore_102 = (((int)1) >= snare_array_dim);
				// samples snare_array channel 1;
				m_hit_2_snare_20 = (index_ignore_102 ? 0 : m_snare_array_52.read(((int)1), 0));
				bool index_ignore_103 = (((int)2) >= snare_array_dim);
				// samples snare_array channel 1;
				m_hit_3_snare_19 = (index_ignore_103 ? 0 : m_snare_array_52.read(((int)2), 0));
				bool index_ignore_104 = (((int)3) >= snare_array_dim);
				// samples snare_array channel 1;
				m_hit_4_snare_18 = (index_ignore_104 ? 0 : m_snare_array_52.read(((int)3), 0));
				bool index_ignore_105 = (((int)4) >= snare_array_dim);
				// samples snare_array channel 1;
				m_hit_5_snare_17 = (index_ignore_105 ? 0 : m_snare_array_52.read(((int)4), 0));
				bool index_ignore_106 = (((int)5) >= snare_array_dim);
				// samples snare_array channel 1;
				m_hit_6_snare_16 = (index_ignore_106 ? 0 : m_snare_array_52.read(((int)5), 0));
				bool index_ignore_107 = (((int)6) >= snare_array_dim);
				// samples snare_array channel 1;
				m_hit_7_snare_15 = (index_ignore_107 ? 0 : m_snare_array_52.read(((int)6), 0));
				bool index_ignore_108 = (((int)7) >= snare_array_dim);
				// samples snare_array channel 1;
				m_hit_8_snare_14 = (index_ignore_108 ? 0 : m_snare_array_52.read(((int)7), 0));
				int hihat_array_dim = m_hihat_array_45.dim;
				int hihat_array_channels = m_hihat_array_45.channels;
				// samples hihat_array channel 1;
				m_hit_1_hihat_13 = m_hihat_array_45.read(0, 0);
				bool index_ignore_109 = (((int)1) >= hihat_array_dim);
				// samples hihat_array channel 1;
				m_hit_2_hihat_12 = (index_ignore_109 ? 0 : m_hihat_array_45.read(((int)1), 0));
				bool index_ignore_110 = (((int)2) >= hihat_array_dim);
				// samples hihat_array channel 1;
				m_hit_3_hihat_11 = (index_ignore_110 ? 0 : m_hihat_array_45.read(((int)2), 0));
				bool index_ignore_111 = (((int)3) >= hihat_array_dim);
				// samples hihat_array channel 1;
				m_hit_4_hihat_10 = (index_ignore_111 ? 0 : m_hihat_array_45.read(((int)3), 0));
				bool index_ignore_112 = (((int)4) >= hihat_array_dim);
				// samples hihat_array channel 1;
				m_hit_5_hihat_9 = (index_ignore_112 ? 0 : m_hihat_array_45.read(((int)4), 0));
				bool index_ignore_113 = (((int)5) >= hihat_array_dim);
				// samples hihat_array channel 1;
				m_hit_6_hihat_8 = (index_ignore_113 ? 0 : m_hihat_array_45.read(((int)5), 0));
				bool index_ignore_114 = (((int)6) >= hihat_array_dim);
				// samples hihat_array channel 1;
				m_hit_7_hihat_7 = (index_ignore_114 ? 0 : m_hihat_array_45.read(((int)6), 0));
				bool index_ignore_115 = (((int)7) >= hihat_array_dim);
				// samples hihat_array channel 1;
				m_hit_8_hihat_6 = (index_ignore_115 ? 0 : m_hihat_array_45.read(((int)7), 0));
				// for loop initializer;
				int i_1410 = ((int)0);
				// for loop condition;
				while ((i_1410 < snare_array_dim)) {
					// abort processing if an infinite loop is suspected;
					if (((__loopcount--) <= 0)) {
						__exception = GENLIB_ERR_LOOP_OVERFLOW;
						break ;
						
					};
					t_sample sub_2506 = (m_knob2_X_44 - ((int)0));
					t_sample scale_2503 = ((safepow((sub_2506 * ((t_sample)1)), ((int)1)) * ((int)7)) + ((int)0));
					t_sample sub_2510 = (m_knob3_Y_43 - ((int)0));
					t_sample scale_2507 = ((safepow((sub_2510 * ((t_sample)1)), ((int)1)) * ((int)7)) + ((int)0));
					t_sample c_1411 = (round(scale_2503) + round((scale_2507 * ((int)8))));
					int snare_patterns_dim = m_snare_patterns_28.dim;
					int snare_patterns_channels = m_snare_patterns_28.channels;
					bool index_ignore_116 = ((i_1410 >= snare_patterns_dim) || (i_1410 < 0));
					// samples snare_patterns channel 1;
					int chan_117 = c_1411;
					bool chan_ignore_118 = ((chan_117 < 0) || (chan_117 >= snare_patterns_channels));
					t_sample h = ((chan_ignore_118 || index_ignore_116) ? 0 : m_snare_patterns_28.read(i_1410, chan_117));
					int snare_hit_values_dim = m_snare_hit_values_51.dim;
					int snare_hit_values_channels = m_snare_hit_values_51.channels;
					bool index_ignore_119 = ((i_1410 >= snare_hit_values_dim) || (i_1410 < 0));
					// samples snare_hit_values channel 1;
					int chan_120 = c_1411;
					bool chan_ignore_121 = ((chan_120 < 0) || (chan_120 >= snare_hit_values_channels));
					t_sample v = ((chan_ignore_121 || index_ignore_119) ? 0 : m_snare_hit_values_51.read(i_1410, chan_120));
					int hit = ((int)0);
					if (((v < (((int)1) - m_knob5_snareDensity_54)) && (h == ((int)1)))) {
						hit = ((int)1);
						
					};
					bool index_ignore_122 = ((i_1410 >= snare_array_dim) || (i_1410 < 0));
					if ((!index_ignore_122)) {
						m_snare_array_52.write(hit, i_1410, 0);
						
					};
					bool chan_ignore_123 = ((((int)1) < 0) || (((int)1) >= snare_array_channels));
					bool index_ignore_124 = ((i_1410 >= snare_array_dim) || (i_1410 < 0));
					if ((!(chan_ignore_123 || index_ignore_124))) {
						m_snare_array_52.write(v, i_1410, ((int)1));
						
					};
					// for loop increment;
					i_1410 = (i_1410 + ((int)1));
					
				};
				// for loop initializer;
				i_1410 = ((int)0);
				// for loop condition;
				while ((i_1410 < hihat_array_dim)) {
					// abort processing if an infinite loop is suspected;
					if (((__loopcount--) <= 0)) {
						__exception = GENLIB_ERR_LOOP_OVERFLOW;
						break ;
						
					};
					t_sample sub_2514 = (m_knob2_X_44 - ((int)0));
					t_sample scale_2511 = ((safepow((sub_2514 * ((t_sample)1)), ((int)1)) * ((int)7)) + ((int)0));
					t_sample sub_2518 = (m_knob3_Y_43 - ((int)0));
					t_sample scale_2515 = ((safepow((sub_2518 * ((t_sample)1)), ((int)1)) * ((int)7)) + ((int)0));
					t_sample c_1411 = (round(scale_2511) + round((scale_2515 * ((int)8))));
					int hihat_patterns_dim = m_hihat_patterns_58.dim;
					int hihat_patterns_channels = m_hihat_patterns_58.channels;
					bool index_ignore_125 = ((i_1410 >= hihat_patterns_dim) || (i_1410 < 0));
					// samples hihat_patterns channel 1;
					int chan_126 = c_1411;
					bool chan_ignore_127 = ((chan_126 < 0) || (chan_126 >= hihat_patterns_channels));
					t_sample h = ((chan_ignore_127 || index_ignore_125) ? 0 : m_hihat_patterns_58.read(i_1410, chan_126));
					int hihat_hit_values_dim = m_hihat_hit_values_48.dim;
					int hihat_hit_values_channels = m_hihat_hit_values_48.channels;
					bool index_ignore_128 = ((i_1410 >= hihat_hit_values_dim) || (i_1410 < 0));
					// samples hihat_hit_values channel 1;
					int chan_129 = c_1411;
					bool chan_ignore_130 = ((chan_129 < 0) || (chan_129 >= hihat_hit_values_channels));
					t_sample v = ((chan_ignore_130 || index_ignore_128) ? 0 : m_hihat_hit_values_48.read(i_1410, chan_129));
					int hit = ((int)0);
					if (((v < (((int)1) - m_knob6_hihatDensity_42)) && (h == ((int)1)))) {
						hit = ((int)1);
						
					};
					bool index_ignore_131 = ((i_1410 >= hihat_array_dim) || (i_1410 < 0));
					if ((!index_ignore_131)) {
						m_hihat_array_45.write(hit, i_1410, 0);
						
					};
					bool chan_ignore_132 = ((((int)1) < 0) || (((int)1) >= hihat_array_channels));
					bool index_ignore_133 = ((i_1410 >= hihat_array_dim) || (i_1410 < 0));
					if ((!(chan_ignore_132 || index_ignore_133))) {
						m_hihat_array_45.write(v, i_1410, ((int)1));
						
					};
					// for loop increment;
					i_1410 = (i_1410 + ((int)1));
					
				};
				
			};
			t_sample expr_1393 = m_hit_1_snare_21;
			t_sample expr_1394 = m_hit_2_snare_20;
			t_sample expr_1395 = m_hit_3_snare_19;
			t_sample expr_1396 = m_hit_4_snare_18;
			t_sample expr_1397 = m_hit_5_snare_17;
			t_sample expr_1398 = m_hit_6_snare_16;
			t_sample expr_1399 = m_hit_7_snare_15;
			t_sample expr_1400 = m_hit_8_snare_14;
			t_sample expr_1401 = m_hit_1_hihat_13;
			t_sample expr_1402 = m_hit_2_hihat_12;
			t_sample expr_1403 = m_hit_3_hihat_11;
			t_sample expr_1404 = m_hit_4_hihat_10;
			t_sample expr_1405 = m_hit_5_hihat_9;
			t_sample expr_1406 = m_hit_6_hihat_8;
			t_sample expr_1407 = m_hit_7_hihat_7;
			t_sample expr_1408 = m_hit_8_hihat_6;
			t_sample out13 = expr_1395;
			t_sample out19 = expr_1401;
			t_sample out24 = expr_1406;
			t_sample out20 = expr_1402;
			t_sample out14 = expr_1396;
			t_sample out18 = expr_1400;
			t_sample out12 = expr_1394;
			t_sample out23 = expr_1405;
			t_sample out22 = expr_1404;
			t_sample out26 = expr_1408;
			t_sample out15 = expr_1397;
			t_sample out16 = expr_1398;
			t_sample out21 = expr_1403;
			t_sample out25 = expr_1407;
			t_sample out11 = expr_1393;
			t_sample out17 = expr_1399;
			int trigger_beat_1206 = trigger_beat_1295;
			__m_latch_134 = ((trigger_beat_1206 != 0) ? floor_1333 : __m_latch_134);
			t_sample latch_1207 = __m_latch_134;
			int eq_1199 = (latch_1207 == ((int)6));
			t_sample out9 = (eq_1199 + expr_1389);
			int eq_1204 = (latch_1207 == ((int)1));
			t_sample out4 = (eq_1204 + expr_1384);
			int eq_1201 = (latch_1207 == ((int)4));
			t_sample out7 = (eq_1201 + expr_1387);
			int eq_1200 = (latch_1207 == ((int)5));
			t_sample out8 = (eq_1200 + expr_1388);
			int eq_1205 = (latch_1207 == ((int)0));
			t_sample out3 = (eq_1205 + expr_1383);
			int eq_1203 = (latch_1207 == ((int)2));
			t_sample out5 = (eq_1203 + expr_1385);
			int eq_1202 = (latch_1207 == ((int)3));
			t_sample out6 = (eq_1202 + expr_1386);
			int eq_1198 = (latch_1207 == ((int)7));
			t_sample out10 = (eq_1198 + expr_1390);
			int trigger_beat_1143 = trigger_beat_1295;
			int gt_1151 = (trigger_beat_1143 > ((int)0));
			int change_1150 = __m_change_135(gt_1151);
			int gt_1149 = (change_1150 > ((int)0));
			int plusequals_1148 = __m_pluseq_136.post(((int)1), gt_1149, 0);
			int lte_1147 = (plusequals_1148 <= max_1145);
			t_sample out34 = lte_1147;
			t_sample phasor_1260 = __m_phasor_137(((int)330), samples_to_seconds);
			t_sample triangle_1259 = triangle(phasor_1260, ((t_sample)0.5));
			t_sample phasor_1258 = __m_phasor_138(((int)185), samples_to_seconds);
			t_sample triangle_1257 = triangle(phasor_1258, ((t_sample)0.5));
			int trigger_beat_1196 = trigger_beat_1295;
			t_sample delta_1290 = __m_delta_139(wrap_1077);
			t_sample abs_1294 = fabs(delta_1290);
			int gt_1293 = (abs_1294 > ((t_sample)0.5));
			int change_1292 = __m_change_140(gt_1293);
			int gt_1291 = (change_1292 > ((int)0));
			int trigger_master_1297 = gt_1291;
			__m_count_141 = (trigger_master_1297 ? 0 : (fixdenorm(__m_count_141 + gt_1286)));
			int counter_1300 = __m_count_141;
			int counter_1301 = ((int)0);
			int counter_1302 = ((int)0);
			bool index_ignore_142 = ((counter_1300 >= kick_array_dim) || (counter_1300 < 0));
			// samples kick_array channel 1;
			t_sample sample_kick_array_1223 = (index_ignore_142 ? 0 : m_kick_array_40.read(counter_1300, 0));
			t_sample index_kick_array_1224 = counter_1300;
			t_sample kick_boolean_1222 = sample_kick_array_1223;
			__m_latch_143 = ((kick_boolean_1222 != 0) ? trigger_beat_1196 : __m_latch_143);
			t_sample latch_1221 = __m_latch_143;
			t_sample delta_1236 = __m_delta_144(latch_1221);
			t_sample abs_1212 = fabs(delta_1236);
			int gt_1211 = (abs_1212 > ((t_sample)0.5));
			int change_1210 = __m_change_145(gt_1211);
			int gt_1209 = (change_1210 > ((int)0));
			t_sample plusequals_1214 = __m_pluseq_146.post(safediv(8, samplerate), gt_1209, 0);
			t_sample clamp_1213 = ((plusequals_1214 <= ((int)0)) ? ((int)0) : ((plusequals_1214 >= ((int)1)) ? ((int)1) : plusequals_1214));
			t_sample sub_2522 = (clamp_1213 - ((int)0));
			t_sample scale_2519 = ((safepow((sub_2522 * ((t_sample)1)), (1 * ((t_sample)0.25))) * ((int)-1)) + ((int)1));
			t_sample scale_1215 = scale_2519;
			t_sample sub_2526 = (scale_1215 - ((int)1));
			t_sample scale_2523 = ((safepow((sub_2526 * ((t_sample)-1)), ((int)1)) * ((int)-100)) + ((int)150));
			t_sample scale_1218 = scale_2523;
			t_sample sin_1219 = sin(scale_1218);
			t_sample mul_1220 = (scale_1215 * sin_1219);
			t_sample mix_2527 = (mul_1220 + (((t_sample)0.9) * (m_history_1 - mul_1220)));
			t_sample mix_1217 = mix_2527;
			bool index_ignore_147 = ((counter_1300 >= hihat_array_dim) || (counter_1300 < 0));
			// samples hihat_array channel 1;
			t_sample sample_hihat_array_1298 = (index_ignore_147 ? 0 : m_hihat_array_45.read(counter_1300, 0));
			t_sample index_hihat_array_1299 = counter_1300;
			__m_latch_148 = ((sample_hihat_array_1298 != 0) ? trigger_beat_1295 : __m_latch_148);
			t_sample latch_1303 = __m_latch_148;
			t_sample delta_1268 = __m_delta_149(latch_1303);
			t_sample abs_1272 = fabs(delta_1268);
			int gt_1271 = (abs_1272 > ((t_sample)0.5));
			int change_1270 = __m_change_150(gt_1271);
			int gt_1269 = (change_1270 > ((int)0));
			t_sample plusequals_1278 = __m_pluseq_151.post(((t_sample)0.0003239390994493), gt_1269, 0);
			t_sample clamp_1277 = ((plusequals_1278 <= ((int)0)) ? ((int)0) : ((plusequals_1278 >= ((int)1)) ? ((int)1) : plusequals_1278));
			t_sample sub_2531 = (clamp_1277 - ((int)0));
			t_sample scale_2528 = ((safepow((sub_2531 * ((t_sample)1)), (1 * ((t_sample)0.25))) * ((int)-1)) + ((int)1));
			t_sample mul_1282 = (scale_2528 * sub_1279);
			bool index_ignore_152 = ((counter_1300 >= snare_array_dim) || (counter_1300 < 0));
			// samples snare_array channel 1;
			t_sample sample_snare_array_1311 = (index_ignore_152 ? 0 : m_snare_array_52.read(counter_1300, 0));
			t_sample index_snare_array_1312 = counter_1300;
			__m_latch_153 = ((sample_snare_array_1311 != 0) ? trigger_beat_1295 : __m_latch_153);
			t_sample latch_1307 = __m_latch_153;
			t_sample delta_1195 = __m_delta_154(latch_1307);
			t_sample abs_1240 = fabs(delta_1195);
			int gt_1239 = (abs_1240 > ((t_sample)0.5));
			int change_1238 = __m_change_155(gt_1239);
			int gt_1237 = (change_1238 > ((int)0));
			t_sample plusequals_1262 = __m_pluseq_156.post(safediv(13, samplerate), gt_1237, 0);
			t_sample clamp_1261 = ((plusequals_1262 <= ((int)0)) ? ((int)0) : ((plusequals_1262 >= ((int)1)) ? ((int)1) : plusequals_1262));
			t_sample sub_2535 = (clamp_1261 - ((int)0));
			t_sample scale_2532 = ((safepow((sub_2535 * ((t_sample)1)), (1 * ((t_sample)0.5))) * ((int)-1)) + ((int)1));
			t_sample mul_1265 = (scale_2532 * triangle_1259);
			t_sample plusequals_1247 = __m_pluseq_157.post(safediv(7, samplerate), gt_1237, 0);
			t_sample clamp_1245 = ((plusequals_1247 <= ((int)0)) ? ((int)0) : ((plusequals_1247 >= ((int)1)) ? ((int)1) : plusequals_1247));
			t_sample sub_2539 = (clamp_1245 - ((int)0));
			t_sample scale_2536 = ((safepow((sub_2539 * ((t_sample)1)), (1 * ((t_sample)0.5))) * ((t_sample)-0.5)) + ((t_sample)0.5));
			t_sample mul_1244 = (scale_2536 * sub_1241);
			t_sample plusequals_1255 = __m_pluseq_158.post(safediv(8, samplerate), gt_1237, 0);
			t_sample clamp_1251 = ((plusequals_1255 <= ((int)0)) ? ((int)0) : ((plusequals_1255 >= ((int)1)) ? ((int)1) : plusequals_1255));
			t_sample sub_2543 = (clamp_1251 - ((int)0));
			t_sample scale_2540 = ((safepow((sub_2543 * ((t_sample)1)), (1 * ((t_sample)0.5))) * ((t_sample)-0.7)) + ((t_sample)0.7));
			t_sample mul_1249 = (scale_2540 * mix_1243);
			t_sample plusequals_1256 = __m_pluseq_159.post(safediv(11, samplerate), gt_1237, 0);
			t_sample clamp_1253 = ((plusequals_1256 <= ((int)0)) ? ((int)0) : ((plusequals_1256 >= ((int)1)) ? ((int)1) : plusequals_1256));
			t_sample sub_2547 = (clamp_1253 - ((int)0));
			t_sample scale_2544 = ((safepow((sub_2547 * ((t_sample)1)), (1 * ((t_sample)0.5))) * ((int)-1)) + ((int)1));
			t_sample mul_1250 = (scale_2544 * triangle_1257);
			t_sample v_160 = (((mul_1250 + mul_1249) + mul_1244) + mul_1265);
			t_sample clamp_1248 = ((v_160 <= min_161) ? min_161 : ((v_160 >= ((int)1)) ? ((int)1) : v_160));
			t_sample add_1159 = (mul_1282 + clamp_1248);
			t_sample mul_1155 = (add_1159 * ((t_sample)0.5));
			t_sample add_1158 = (mul_1155 + mix_1217);
			t_sample mul_1152 = (add_1158 * ((t_sample)0.5));
			t_sample mix_2548 = (mul_1152 + (((t_sample)0.5) * (in2 - mul_1152)));
			t_sample out2 = mix_2548;
			t_sample add_1162 = (mul_1282 + clamp_1248);
			t_sample mul_1154 = (add_1162 * ((t_sample)0.5));
			t_sample add_1161 = (mul_1154 + mix_1217);
			t_sample mul_1153 = (add_1161 * ((t_sample)0.5));
			t_sample mix_2549 = (mul_1153 + (((t_sample)0.5) * (in1 - mul_1153)));
			t_sample out1 = mix_2549;
			t_sample history_1280_next_1412 = fixdenorm(mix_1281);
			t_sample history_1242_next_1413 = fixdenorm(mix_1243);
			t_sample history_1263_next_1414 = fixdenorm(mix_1264);
			t_sample history_1078_next_1415 = fixdenorm(wrap_1077);
			t_sample history_1216_next_1416 = fixdenorm(mix_1217);
			m_y_26 = y_next_1113;
			m_z_24 = z_next_1115;
			m_x_25 = x_next_1114;
			m_history_23 = history_1124_next_1132;
			m_history_22 = history_1121_next_1133;
			m_history_5 = history_1280_next_1412;
			m_history_4 = history_1242_next_1413;
			m_history_3 = history_1263_next_1414;
			m_history_2 = history_1078_next_1415;
			m_history_1 = history_1216_next_1416;
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
	inline void set_snare_patterns(void * _value) {
		m_snare_patterns_28.setbuffer(_value);
	};
	inline void set_sw5(t_param _value) {
		m_sw_29 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw4(t_param _value) {
		m_sw_30 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw2(t_param _value) {
		m_sw_31 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_kick_array(void * _value) {
		m_kick_array_40.setbuffer(_value);
	};
	inline void set_knob4_swing(t_param _value) {
		m_knob4_swing_41 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6_hihatDensity(t_param _value) {
		m_knob6_hihatDensity_42 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_Y(t_param _value) {
		m_knob3_Y_43 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob2_X(t_param _value) {
		m_knob2_X_44 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_hihat_array(void * _value) {
		m_hihat_array_45.setbuffer(_value);
	};
	inline void set_sw3(t_param _value) {
		m_sw_46 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_noise_array(void * _value) {
		m_noise_array_47.setbuffer(_value);
	};
	inline void set_hihat_hit_values(void * _value) {
		m_hihat_hit_values_48.setbuffer(_value);
	};
	inline void set_grid_matrix_noise(void * _value) {
		m_grid_matrix_noise_49.setbuffer(_value);
	};
	inline void set_sw8(t_param _value) {
		m_sw_50 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_snare_hit_values(void * _value) {
		m_snare_hit_values_51.setbuffer(_value);
	};
	inline void set_snare_array(void * _value) {
		m_snare_array_52.setbuffer(_value);
	};
	inline void set_knob1_bpm(t_param _value) {
		m_knob1_bpm_53 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5_snareDensity(t_param _value) {
		m_knob5_snareDensity_54 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_55 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw7(t_param _value) {
		m_sw_56 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw6(t_param _value) {
		m_sw_57 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_hihat_patterns(void * _value) {
		m_hihat_patterns_58.setbuffer(_value);
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
const char *gen_kernel_outnames[] = { "sound_l", "sound_r", "led1", "led2", "led3", "led4", "led5", "led6", "led7", "led8", "sn1", "sn2", "sn3", "sn4", "sn5", "sn6", "sn7", "sn8", "hi1", "hi2", "hi3", "hi4", "hi5", "hi6", "hi7", "hi8", "trigger_b", "step_value", "x_pos", "y_pos", "out31", "out32", "cvout2", "gateout1" };

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
		
		
		
		
		
		case 5: *value = self->m_knob1_bpm_53; break;
		case 6: *value = self->m_knob2_X_44; break;
		case 7: *value = self->m_knob3_Y_43; break;
		case 8: *value = self->m_knob4_swing_41; break;
		case 9: *value = self->m_knob5_snareDensity_54; break;
		case 10: *value = self->m_knob6_hihatDensity_42; break;
		case 11: *value = self->m_mix_27; break;
		
		
		
		
		case 16: *value = self->m_sw_55; break;
		case 17: *value = self->m_sw_31; break;
		case 18: *value = self->m_sw_46; break;
		case 19: *value = self->m_sw_30; break;
		case 20: *value = self->m_sw_29; break;
		case 21: *value = self->m_sw_57; break;
		case 22: *value = self->m_sw_56; break;
		case 23: *value = self->m_sw_50; break;
		
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
	// initialize parameter 0 ("m_grid_matrix_noise_49")
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
	// initialize parameter 1 ("m_hihat_array_45")
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
	// initialize parameter 2 ("m_hihat_hit_values_48")
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
	// initialize parameter 3 ("m_hihat_patterns_58")
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
	// initialize parameter 4 ("m_kick_array_40")
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
	// initialize parameter 5 ("m_knob1_bpm_53")
	pi = self->__commonstate.params + 5;
	pi->name = "knob1_bpm";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob1_bpm_53;
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
	// initialize parameter 7 ("m_knob3_Y_43")
	pi = self->__commonstate.params + 7;
	pi->name = "knob3_Y";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_Y_43;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 8 ("m_knob4_swing_41")
	pi = self->__commonstate.params + 8;
	pi->name = "knob4_swing";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_swing_41;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
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
	// initialize parameter 10 ("m_knob6_hihatDensity_42")
	pi = self->__commonstate.params + 10;
	pi->name = "knob6_hihatDensity";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_hihatDensity_42;
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
	// initialize parameter 12 ("m_noise_array_47")
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
	// initialize parameter 13 ("m_snare_array_52")
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
	// initialize parameter 14 ("m_snare_hit_values_51")
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
	// initialize parameter 15 ("m_snare_patterns_28")
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
	// initialize parameter 16 ("m_sw_55")
	pi = self->__commonstate.params + 16;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_55;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 17 ("m_sw_31")
	pi = self->__commonstate.params + 17;
	pi->name = "sw2";
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
	// initialize parameter 18 ("m_sw_46")
	pi = self->__commonstate.params + 18;
	pi->name = "sw3";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_46;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 19 ("m_sw_30")
	pi = self->__commonstate.params + 19;
	pi->name = "sw4";
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
	// initialize parameter 20 ("m_sw_29")
	pi = self->__commonstate.params + 20;
	pi->name = "sw5";
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
	// initialize parameter 21 ("m_sw_57")
	pi = self->__commonstate.params + 21;
	pi->name = "sw6";
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
	// initialize parameter 22 ("m_sw_56")
	pi = self->__commonstate.params + 22;
	pi->name = "sw7";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_56;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 23 ("m_sw_50")
	pi = self->__commonstate.params + 23;
	pi->name = "sw8";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_50;
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
