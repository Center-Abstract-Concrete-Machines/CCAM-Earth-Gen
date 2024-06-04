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
	Change __m_change_93;
	Change __m_change_62;
	Change __m_change_131;
	Change __m_change_61;
	Change __m_change_92;
	Change __m_change_63;
	Change __m_change_127;
	Change __m_change_64;
	Change __m_change_65;
	Change __m_change_60;
	Change __m_change_140;
	Change __m_change_59;
	Change __m_change_145;
	Change __m_change_155;
	Change __m_change_150;
	Change __m_change_66;
	Data m_hihat_patterns_28;
	Data m_snare_array_45;
	Data m_grid_matrix_noise_27;
	Data m_kick_array_53;
	Data m_snare_hit_values_54;
	Data m_hihat_hit_values_32;
	Data m_noise_array_58;
	Data m_snare_patterns_42;
	Data m_hihat_array_44;
	Delta __m_delta_91;
	Delta __m_delta_149;
	Delta __m_delta_154;
	Delta __m_delta_139;
	Delta __m_delta_144;
	Delta __m_delta_130;
	Phasor __m_phasor_129;
	Phasor __m_phasor_138;
	Phasor __m_phasor_137;
	PlusEquals __m_pluseq_158;
	PlusEquals __m_pluseq_157;
	PlusEquals __m_pluseq_156;
	PlusEquals __m_pluseq_151;
	PlusEquals __m_pluseq_146;
	PlusEquals __m_pluseq_128;
	PlusEquals __m_pluseq_159;
	int __loopcount;
	int __exception;
	int vectorsize;
	t_sample __m_count_132;
	t_sample m_sw_41;
	t_sample __m_carry_134;
	t_sample m_hit_2_hihat_12;
	t_sample m_hit_3_hihat_11;
	t_sample m_hit_1_hihat_13;
	t_sample m_hit_4_hihat_10;
	t_sample m_hit_8_snare_14;
	t_sample samples_to_seconds;
	t_sample __m_latch_126;
	t_sample m_hit_7_snare_15;
	t_sample m_hit_5_snare_17;
	t_sample m_hit_6_snare_16;
	t_sample m_hit_5_hihat_9;
	t_sample __m_count_141;
	t_sample __m_latch_143;
	t_sample __m_latch_153;
	t_sample m_history_3;
	t_sample m_history_2;
	t_sample samplerate;
	t_sample m_history_1;
	t_sample m_hit_4_snare_18;
	t_sample m_history_4;
	t_sample __m_latch_148;
	t_sample m_hit_6_hihat_8;
	t_sample m_history_5;
	t_sample m_hit_7_hihat_7;
	t_sample m_hit_8_hihat_6;
	t_sample m_led_40;
	t_sample m_hit_3_snare_19;
	t_sample m_hit_1_snare_21;
	t_sample m_led_36;
	t_sample m_knob5_snareDensity_48;
	t_sample m_knob4_swing_50;
	t_sample m_knob3_Y_52;
	t_sample m_mix_51;
	t_sample m_led_35;
	t_sample m_knob2_X_47;
	t_sample m_led_37;
	t_sample m_led_39;
	t_sample m_sw_46;
	t_sample m_sw_43;
	t_sample m_led_38;
	t_sample m_hit_2_snare_20;
	t_sample m_led_34;
	t_sample m_sw_56;
	t_sample m_z_24;
	t_sample m_x_25;
	t_sample m_history_23;
	t_sample elapsed;
	t_sample m_history_22;
	t_sample m_sw_55;
	t_sample m_y_26;
	t_sample m_sw_30;
	t_sample m_sw_57;
	t_sample m_sw_29;
	t_sample m_led_33;
	t_sample m_knob1_bpm_31;
	t_sample m_knob6_hihatDensity_49;
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
		m_grid_matrix_noise_27.reset("grid_matrix_noise", ((int)64), ((int)1));
		m_hihat_patterns_28.reset("hihat_patterns", ((int)8), ((int)64));
		m_sw_29 = ((int)0);
		m_sw_30 = ((int)0);
		m_knob1_bpm_31 = ((int)0);
		m_hihat_hit_values_32.reset("hihat_hit_values", ((int)8), ((int)64));
		m_led_33 = ((int)0);
		m_led_34 = ((int)0);
		m_led_35 = ((int)0);
		m_led_36 = ((int)0);
		m_led_37 = ((int)0);
		m_led_38 = ((int)0);
		m_led_39 = ((int)0);
		m_led_40 = ((int)0);
		m_sw_41 = ((int)0);
		m_snare_patterns_42.reset("snare_patterns", ((int)8), ((int)64));
		m_sw_43 = ((int)0);
		m_hihat_array_44.reset("hihat_array", ((int)8), ((int)2));
		m_snare_array_45.reset("snare_array", ((int)8), ((int)2));
		m_sw_46 = ((int)0);
		m_knob2_X_47 = ((int)0);
		m_knob5_snareDensity_48 = ((int)1);
		m_knob6_hihatDensity_49 = ((int)1);
		m_knob4_swing_50 = ((int)0);
		m_mix_51 = ((t_sample)0.5);
		m_knob3_Y_52 = ((int)0);
		m_kick_array_53.reset("kick_array", ((int)8), ((int)1));
		m_snare_hit_values_54.reset("snare_hit_values", ((int)8), ((int)64));
		m_sw_55 = ((int)0);
		m_sw_56 = ((int)0);
		m_sw_57 = ((int)0);
		m_noise_array_58.reset("noise_array", ((int)48000), ((int)1));
		__m_change_59.reset(0);
		__m_change_60.reset(0);
		__m_change_61.reset(0);
		__m_change_62.reset(0);
		__m_change_63.reset(0);
		__m_change_64.reset(0);
		__m_change_65.reset(0);
		__m_change_66.reset(0);
		elapsed = 0;
		__m_delta_91.reset(0);
		__m_change_92.reset(0);
		__m_change_93.reset(0);
		__m_latch_126 = 0;
		__m_change_127.reset(0);
		__m_pluseq_128.reset(0);
		samples_to_seconds = (1 / samplerate);
		__m_phasor_129.reset(0);
		__m_delta_130.reset(0);
		__m_change_131.reset(0);
		__m_count_132 = 0;
		__m_carry_134 = 0;
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
		t_sample sub_17176 = (m_knob2_X_47 - ((int)0));
		t_sample scale_17173 = ((safepow((sub_17176 * ((t_sample)1)), ((int)1)) * ((int)7)) + ((int)1));
		t_sample expr_16485 = round(scale_17173);
		t_sample sub_17180 = (m_knob3_Y_52 - ((int)0));
		t_sample scale_17177 = ((safepow((sub_17180 * ((t_sample)1)), ((int)1)) * ((int)7)) + ((int)1));
		t_sample expr_16486 = round(scale_17177);
		t_sample mstosamps_10065 = (((int)1) * (samplerate * 0.001));
		t_sample max_10066 = ((mstosamps_10065 < vectorsize) ? vectorsize : mstosamps_10065);
		int iftrue_90 = (-10000000000);
		t_sample sub_17197 = (m_knob1_bpm_31 - ((int)0));
		t_sample scale_17194 = ((safepow((sub_17197 * ((t_sample)1)), ((int)1)) * ((int)-460)) + ((int)500));
		t_sample scale_10156 = scale_17194;
		t_sample div_10257 = (scale_10156 * ((t_sample)0.016666666666667));
		t_sample div_10118 = (div_10257 * ((t_sample)0.125));
		t_sample div_10009 = safediv(div_10118, samplerate);
		samples_to_seconds = (1 / samplerate);
		int grid_matrix_noise_dim = m_grid_matrix_noise_27.dim;
		int grid_matrix_noise_channels = m_grid_matrix_noise_27.channels;
		int kick_array_dim = m_kick_array_53.dim;
		int kick_array_channels = m_kick_array_53.channels;
		int hihat_array_dim = m_hihat_array_44.dim;
		int hihat_array_channels = m_hihat_array_44.channels;
		int snare_array_dim = m_snare_array_45.dim;
		int snare_array_channels = m_snare_array_45.channels;
		int min_161 = (-1);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			int sw_1 = (__m_change_59((m_sw_55 > ((int)0))) > ((int)0));
			int sw_2 = (__m_change_60((m_sw_56 > ((int)0))) > ((int)0));
			int sw_3 = (__m_change_61((m_sw_30 > ((int)0))) > ((int)0));
			int sw_4 = (__m_change_62((m_sw_41 > ((int)0))) > ((int)0));
			int sw_5 = (__m_change_63((m_sw_29 > ((int)0))) > ((int)0));
			int sw_6 = (__m_change_64((m_sw_43 > ((int)0))) > ((int)0));
			int sw_7 = (__m_change_65((m_sw_46 > ((int)0))) > ((int)0));
			int sw_8 = (__m_change_66((m_sw_57 > ((int)0))) > ((int)0));
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
				m_led_40 = ((int)1);
				m_led_39 = ((int)1);
				m_led_38 = ((int)1);
				m_led_37 = ((int)1);
				m_led_36 = ((int)1);
				m_led_35 = ((int)1);
				m_led_34 = ((int)1);
				m_led_33 = ((int)1);
				
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
				t_sample a = m_kick_array_53.read(0, 0);
				m_kick_array_53.write((!a), 0, 0);
				m_led_40 = a;
				
			};
			if (sw_2) {
				int kick_array_dim = m_kick_array_53.dim;
				int kick_array_channels = m_kick_array_53.channels;
				bool index_ignore_68 = (((int)1) >= kick_array_dim);
				// samples kick_array channel 1;
				t_sample a = (index_ignore_68 ? 0 : m_kick_array_53.read(((int)1), 0));
				bool index_ignore_69 = (((int)1) >= kick_array_dim);
				if ((!index_ignore_69)) {
					m_kick_array_53.write((!a), ((int)1), 0);
					
				};
				m_led_39 = a;
				
			};
			if (sw_3) {
				int kick_array_dim = m_kick_array_53.dim;
				int kick_array_channels = m_kick_array_53.channels;
				bool index_ignore_70 = (((int)2) >= kick_array_dim);
				// samples kick_array channel 1;
				t_sample a = (index_ignore_70 ? 0 : m_kick_array_53.read(((int)2), 0));
				bool index_ignore_71 = (((int)2) >= kick_array_dim);
				if ((!index_ignore_71)) {
					m_kick_array_53.write((!a), ((int)2), 0);
					
				};
				m_led_38 = a;
				
			};
			if (sw_4) {
				int kick_array_dim = m_kick_array_53.dim;
				int kick_array_channels = m_kick_array_53.channels;
				bool index_ignore_72 = (((int)3) >= kick_array_dim);
				// samples kick_array channel 1;
				t_sample a = (index_ignore_72 ? 0 : m_kick_array_53.read(((int)3), 0));
				bool index_ignore_73 = (((int)3) >= kick_array_dim);
				if ((!index_ignore_73)) {
					m_kick_array_53.write((!a), ((int)3), 0);
					
				};
				m_led_37 = a;
				
			};
			if (sw_5) {
				int kick_array_dim = m_kick_array_53.dim;
				int kick_array_channels = m_kick_array_53.channels;
				bool index_ignore_74 = (((int)4) >= kick_array_dim);
				// samples kick_array channel 1;
				t_sample a = (index_ignore_74 ? 0 : m_kick_array_53.read(((int)4), 0));
				bool index_ignore_75 = (((int)4) >= kick_array_dim);
				if ((!index_ignore_75)) {
					m_kick_array_53.write((!a), ((int)4), 0);
					
				};
				m_led_36 = a;
				
			};
			if (sw_6) {
				int kick_array_dim = m_kick_array_53.dim;
				int kick_array_channels = m_kick_array_53.channels;
				bool index_ignore_76 = (((int)5) >= kick_array_dim);
				// samples kick_array channel 1;
				t_sample a = (index_ignore_76 ? 0 : m_kick_array_53.read(((int)5), 0));
				bool index_ignore_77 = (((int)5) >= kick_array_dim);
				if ((!index_ignore_77)) {
					m_kick_array_53.write((!a), ((int)5), 0);
					
				};
				m_led_35 = a;
				
			};
			if (sw_7) {
				int kick_array_dim = m_kick_array_53.dim;
				int kick_array_channels = m_kick_array_53.channels;
				bool index_ignore_78 = (((int)6) >= kick_array_dim);
				// samples kick_array channel 1;
				t_sample a = (index_ignore_78 ? 0 : m_kick_array_53.read(((int)6), 0));
				bool index_ignore_79 = (((int)6) >= kick_array_dim);
				if ((!index_ignore_79)) {
					m_kick_array_53.write((!a), ((int)6), 0);
					
				};
				m_led_34 = a;
				
			};
			if (sw_8) {
				int kick_array_dim = m_kick_array_53.dim;
				int kick_array_channels = m_kick_array_53.channels;
				bool index_ignore_80 = (((int)7) >= kick_array_dim);
				// samples kick_array channel 1;
				t_sample a = (index_ignore_80 ? 0 : m_kick_array_53.read(((int)7), 0));
				bool index_ignore_81 = (((int)7) >= kick_array_dim);
				if ((!index_ignore_81)) {
					m_kick_array_53.write((!a), ((int)7), 0);
					
				};
				m_led_33 = a;
				
			};
			t_sample expr_16488 = m_led_40;
			t_sample expr_16489 = m_led_39;
			t_sample expr_16490 = m_led_38;
			t_sample expr_16491 = m_led_37;
			t_sample expr_16492 = m_led_36;
			t_sample expr_16493 = m_led_35;
			t_sample expr_16494 = m_led_34;
			t_sample expr_16495 = m_led_33;
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
					int i_16514 = ((int)0);
					// for loop condition;
					while ((i_16514 < ((int)8))) {
						// abort processing if an infinite loop is suspected;
						if (((__loopcount--) <= 0)) {
							__exception = GENLIB_ERR_LOOP_OVERFLOW;
							break ;
							
						};
						t_sample noise_17154 = noise();
						t_sample sub_17157 = (noise_17154 - (-1));
						t_sample scale_17153 = ((safepow((sub_17157 * ((t_sample)0.5)), ((int)1)) * ((t_sample)0.85)) + ((t_sample)0.1));
						t_sample noise_17164 = noise();
						t_sample sub_17167 = (noise_17164 - (-1));
						t_sample scale_17163 = ((safepow((sub_17167 * ((t_sample)0.5)), ((int)1)) * ((t_sample)0.85)) + ((t_sample)0.1));
						int snare_patterns_dim = m_snare_patterns_42.dim;
						int snare_patterns_channels = m_snare_patterns_42.channels;
						bool chan_ignore_82 = ((c < 0) || (c >= snare_patterns_channels));
						bool index_ignore_83 = ((i_16514 >= snare_patterns_dim) || (i_16514 < 0));
						if ((!(chan_ignore_82 || index_ignore_83))) {
							m_snare_patterns_42.write(((int)1), i_16514, c);
							
						};
						int snare_hit_values_dim = m_snare_hit_values_54.dim;
						int snare_hit_values_channels = m_snare_hit_values_54.channels;
						bool chan_ignore_84 = ((c < 0) || (c >= snare_hit_values_channels));
						bool index_ignore_85 = ((i_16514 >= snare_hit_values_dim) || (i_16514 < 0));
						if ((!(chan_ignore_84 || index_ignore_85))) {
							m_snare_hit_values_54.write(scale_17153, i_16514, c);
							
						};
						int hihat_patterns_dim = m_hihat_patterns_28.dim;
						int hihat_patterns_channels = m_hihat_patterns_28.channels;
						bool chan_ignore_86 = ((c < 0) || (c >= hihat_patterns_channels));
						bool index_ignore_87 = ((i_16514 >= hihat_patterns_dim) || (i_16514 < 0));
						if ((!(chan_ignore_86 || index_ignore_87))) {
							m_hihat_patterns_28.write(((int)1), i_16514, c);
							
						};
						int hihat_hit_values_dim = m_hihat_hit_values_32.dim;
						int hihat_hit_values_channels = m_hihat_hit_values_32.channels;
						bool chan_ignore_88 = ((c < 0) || (c >= hihat_hit_values_channels));
						bool index_ignore_89 = ((i_16514 >= hihat_hit_values_dim) || (i_16514 < 0));
						if ((!(chan_ignore_88 || index_ignore_89))) {
							m_hihat_hit_values_32.write(scale_17163, i_16514, c);
							
						};
						// for loop increment;
						i_16514 = (i_16514 + ((int)1));
						
					};
					// for loop increment;
					c = (c + ((int)1));
					
				};
				
			};
			t_sample out29 = expr_16485;
			t_sample out30 = expr_16486;
			t_sample noise_10187 = noise();
			t_sample mix_17187 = (noise_10187 + (((t_sample)0.5) * (m_history_5 - noise_10187)));
			t_sample mix_10164 = mix_17187;
			t_sample mix_17188 = (mix_10164 + (((t_sample)0.6) * (m_history_4 - mix_10164)));
			t_sample mix_10185 = mix_17188;
			t_sample noise_10204 = noise();
			t_sample mix_17189 = (noise_10204 + (((t_sample)0.7) * (m_history_3 - noise_10204)));
			t_sample mix_10202 = mix_17189;
			int or_10016 = (((int)0) || (elapsed == ((int)0)));
			t_sample switch_10018 = (or_10016 ? ((t_sample)0.41) : m_y_26);
			t_sample mul_10031 = (switch_10018 * ((int)1));
			t_sample switch_10019 = (or_10016 ? ((t_sample)0.31) : m_z_24);
			t_sample mul_10036 = (switch_10019 * ((int)1));
			t_sample switch_10017 = (or_10016 ? ((t_sample)0.1) : m_x_25);
			t_sample mul_10039 = (mul_10036 * ((t_sample)0.0002));
			t_sample add_10033 = (switch_10018 + mul_10039);
			t_sample fixnan_10022 = fixnan(add_10033);
			t_sample gen_10045 = fixnan_10022;
			t_sample mul_10040 = (mul_10031 * ((t_sample)0.0002));
			t_sample add_10034 = (switch_10017 + mul_10040);
			t_sample fixnan_10020 = fixnan(add_10034);
			t_sample mul_10028 = (switch_10019 * (-0.45));
			t_sample pow_10026 = safepow(switch_10017, ((int)3));
			t_sample mul_10027 = (pow_10026 * (-1));
			t_sample mul_10030 = (switch_10017 * ((t_sample)0.8));
			t_sample mul_10029 = (switch_10018 * (-1.1));
			t_sample add_10025 = (mul_10030 + mul_10029);
			t_sample add_10024 = (add_10025 + mul_10028);
			t_sample add_10023 = (add_10024 + mul_10027);
			t_sample mul_10038 = (add_10023 * ((t_sample)0.0002));
			t_sample add_10032 = (switch_10019 + mul_10038);
			t_sample fixnan_10021 = fixnan(add_10032);
			t_sample y_next_10041 = fixdenorm(fixnan_10022);
			t_sample x_next_10042 = fixdenorm(fixnan_10020);
			t_sample z_next_10043 = fixdenorm(fixnan_10021);
			t_sample elapsed_10048 = elapsed;
			int eq_10047 = (elapsed_10048 == ((int)0));
			int or_10055 = (eq_10047 || ((int)0));
			t_sample switch_10051 = (or_10055 ? ((int)10000000000) : m_history_23);
			t_sample min_10054 = ((switch_10051 < gen_10045) ? switch_10051 : gen_10045);
			t_sample gen_10058 = min_10054;
			t_sample switch_10050 = (or_10055 ? iftrue_90 : m_history_22);
			t_sample max_10053 = ((gen_10045 < switch_10050) ? switch_10050 : gen_10045);
			t_sample gen_10059 = max_10053;
			t_sample history_10049_next_10056 = fixdenorm(min_10054);
			t_sample history_10052_next_10057 = fixdenorm(max_10053);
			t_sample irange_17191 = (gen_10059 - gen_10058);
			t_sample sub_17193 = (gen_10045 - gen_10058);
			t_sample scale_17190 = ((safepow(safediv(sub_17193, irange_17191), ((int)1)) * ((int)2)) + ((int)-1));
			t_sample scale_10060 = scale_17190;
			t_sample gen_10061 = scale_10060;
			t_sample mul_10007 = (m_knob4_swing_50 * gen_10061);
			t_sample out33 = mul_10007;
			t_sample sub_10200 = (noise_10204 - mix_10202);
			t_sample mul_10014 = (div_10009 * mul_10007);
			t_sample add_10008 = (div_10009 + mul_10014);
			t_sample add_10012 = (m_history_2 + add_10008);
			t_sample wrap_10010 = wrap(add_10012, ((int)0), ((int)1));
			t_sample mul_10255 = (wrap_10010 * ((int)8));
			t_sample floor_10254 = floor(mul_10255);
			t_sample out28 = floor_10254;
			t_sample wrap_10231 = wrap(mul_10255, ((int)0), ((int)1));
			t_sample delta_10206 = __m_delta_91(wrap_10231);
			t_sample abs_10210 = fabs(delta_10206);
			int gt_10209 = (abs_10210 > ((t_sample)0.5));
			int change_10208 = __m_change_92(gt_10209);
			int gt_10207 = (change_10208 > ((int)0));
			int trigger_beat_10064 = gt_10207;
			int trigger_beat_10230 = trigger_beat_10064;
			t_sample out27 = trigger_beat_10230;
			int trig = (__m_change_93((trigger_beat_10230 > ((int)0))) > ((int)0));
			if (trig) {
				int snare_array_dim = m_snare_array_45.dim;
				int snare_array_channels = m_snare_array_45.channels;
				// samples snare_array channel 1;
				m_hit_1_snare_21 = m_snare_array_45.read(0, 0);
				bool index_ignore_94 = (((int)1) >= snare_array_dim);
				// samples snare_array channel 1;
				m_hit_2_snare_20 = (index_ignore_94 ? 0 : m_snare_array_45.read(((int)1), 0));
				bool index_ignore_95 = (((int)2) >= snare_array_dim);
				// samples snare_array channel 1;
				m_hit_3_snare_19 = (index_ignore_95 ? 0 : m_snare_array_45.read(((int)2), 0));
				bool index_ignore_96 = (((int)3) >= snare_array_dim);
				// samples snare_array channel 1;
				m_hit_4_snare_18 = (index_ignore_96 ? 0 : m_snare_array_45.read(((int)3), 0));
				bool index_ignore_97 = (((int)4) >= snare_array_dim);
				// samples snare_array channel 1;
				m_hit_5_snare_17 = (index_ignore_97 ? 0 : m_snare_array_45.read(((int)4), 0));
				bool index_ignore_98 = (((int)5) >= snare_array_dim);
				// samples snare_array channel 1;
				m_hit_6_snare_16 = (index_ignore_98 ? 0 : m_snare_array_45.read(((int)5), 0));
				bool index_ignore_99 = (((int)6) >= snare_array_dim);
				// samples snare_array channel 1;
				m_hit_7_snare_15 = (index_ignore_99 ? 0 : m_snare_array_45.read(((int)6), 0));
				bool index_ignore_100 = (((int)7) >= snare_array_dim);
				// samples snare_array channel 1;
				m_hit_8_snare_14 = (index_ignore_100 ? 0 : m_snare_array_45.read(((int)7), 0));
				int hihat_array_dim = m_hihat_array_44.dim;
				int hihat_array_channels = m_hihat_array_44.channels;
				// samples hihat_array channel 1;
				m_hit_1_hihat_13 = m_hihat_array_44.read(0, 0);
				bool index_ignore_101 = (((int)1) >= hihat_array_dim);
				// samples hihat_array channel 1;
				m_hit_2_hihat_12 = (index_ignore_101 ? 0 : m_hihat_array_44.read(((int)1), 0));
				bool index_ignore_102 = (((int)2) >= hihat_array_dim);
				// samples hihat_array channel 1;
				m_hit_3_hihat_11 = (index_ignore_102 ? 0 : m_hihat_array_44.read(((int)2), 0));
				bool index_ignore_103 = (((int)3) >= hihat_array_dim);
				// samples hihat_array channel 1;
				m_hit_4_hihat_10 = (index_ignore_103 ? 0 : m_hihat_array_44.read(((int)3), 0));
				bool index_ignore_104 = (((int)4) >= hihat_array_dim);
				// samples hihat_array channel 1;
				m_hit_5_hihat_9 = (index_ignore_104 ? 0 : m_hihat_array_44.read(((int)4), 0));
				bool index_ignore_105 = (((int)5) >= hihat_array_dim);
				// samples hihat_array channel 1;
				m_hit_6_hihat_8 = (index_ignore_105 ? 0 : m_hihat_array_44.read(((int)5), 0));
				bool index_ignore_106 = (((int)6) >= hihat_array_dim);
				// samples hihat_array channel 1;
				m_hit_7_hihat_7 = (index_ignore_106 ? 0 : m_hihat_array_44.read(((int)6), 0));
				bool index_ignore_107 = (((int)7) >= hihat_array_dim);
				// samples hihat_array channel 1;
				m_hit_8_hihat_6 = (index_ignore_107 ? 0 : m_hihat_array_44.read(((int)7), 0));
				// for loop initializer;
				int i_16515 = ((int)0);
				// for loop condition;
				while ((i_16515 < snare_array_dim)) {
					// abort processing if an infinite loop is suspected;
					if (((__loopcount--) <= 0)) {
						__exception = GENLIB_ERR_LOOP_OVERFLOW;
						break ;
						
					};
					t_sample sub_17201 = (m_knob2_X_47 - ((int)0));
					t_sample scale_17198 = ((safepow((sub_17201 * ((t_sample)1)), ((int)1)) * ((int)7)) + ((int)0));
					t_sample sub_17205 = (m_knob3_Y_52 - ((int)0));
					t_sample scale_17202 = ((safepow((sub_17205 * ((t_sample)1)), ((int)1)) * ((int)7)) + ((int)0));
					t_sample c_16516 = (round(scale_17198) + round((scale_17202 * ((int)8))));
					int snare_patterns_dim = m_snare_patterns_42.dim;
					int snare_patterns_channels = m_snare_patterns_42.channels;
					bool index_ignore_108 = ((i_16515 >= snare_patterns_dim) || (i_16515 < 0));
					// samples snare_patterns channel 1;
					int chan_109 = c_16516;
					bool chan_ignore_110 = ((chan_109 < 0) || (chan_109 >= snare_patterns_channels));
					t_sample h = ((chan_ignore_110 || index_ignore_108) ? 0 : m_snare_patterns_42.read(i_16515, chan_109));
					int snare_hit_values_dim = m_snare_hit_values_54.dim;
					int snare_hit_values_channels = m_snare_hit_values_54.channels;
					bool index_ignore_111 = ((i_16515 >= snare_hit_values_dim) || (i_16515 < 0));
					// samples snare_hit_values channel 1;
					int chan_112 = c_16516;
					bool chan_ignore_113 = ((chan_112 < 0) || (chan_112 >= snare_hit_values_channels));
					t_sample v = ((chan_ignore_113 || index_ignore_111) ? 0 : m_snare_hit_values_54.read(i_16515, chan_112));
					int hit = ((int)0);
					if (((v < (((int)1) - m_knob5_snareDensity_48)) && (h == ((int)1)))) {
						hit = ((int)1);
						
					};
					bool index_ignore_114 = ((i_16515 >= snare_array_dim) || (i_16515 < 0));
					if ((!index_ignore_114)) {
						m_snare_array_45.write(hit, i_16515, 0);
						
					};
					bool chan_ignore_115 = ((((int)1) < 0) || (((int)1) >= snare_array_channels));
					bool index_ignore_116 = ((i_16515 >= snare_array_dim) || (i_16515 < 0));
					if ((!(chan_ignore_115 || index_ignore_116))) {
						m_snare_array_45.write(v, i_16515, ((int)1));
						
					};
					// for loop increment;
					i_16515 = (i_16515 + ((int)1));
					
				};
				// for loop initializer;
				i_16515 = ((int)0);
				// for loop condition;
				while ((i_16515 < hihat_array_dim)) {
					// abort processing if an infinite loop is suspected;
					if (((__loopcount--) <= 0)) {
						__exception = GENLIB_ERR_LOOP_OVERFLOW;
						break ;
						
					};
					t_sample sub_17209 = (m_knob2_X_47 - ((int)0));
					t_sample scale_17206 = ((safepow((sub_17209 * ((t_sample)1)), ((int)1)) * ((int)7)) + ((int)0));
					t_sample sub_17213 = (m_knob3_Y_52 - ((int)0));
					t_sample scale_17210 = ((safepow((sub_17213 * ((t_sample)1)), ((int)1)) * ((int)7)) + ((int)0));
					t_sample c_16516 = (round(scale_17206) + round((scale_17210 * ((int)8))));
					int hihat_patterns_dim = m_hihat_patterns_28.dim;
					int hihat_patterns_channels = m_hihat_patterns_28.channels;
					bool index_ignore_117 = ((i_16515 >= hihat_patterns_dim) || (i_16515 < 0));
					// samples hihat_patterns channel 1;
					int chan_118 = c_16516;
					bool chan_ignore_119 = ((chan_118 < 0) || (chan_118 >= hihat_patterns_channels));
					t_sample h = ((chan_ignore_119 || index_ignore_117) ? 0 : m_hihat_patterns_28.read(i_16515, chan_118));
					int hihat_hit_values_dim = m_hihat_hit_values_32.dim;
					int hihat_hit_values_channels = m_hihat_hit_values_32.channels;
					bool index_ignore_120 = ((i_16515 >= hihat_hit_values_dim) || (i_16515 < 0));
					// samples hihat_hit_values channel 1;
					int chan_121 = c_16516;
					bool chan_ignore_122 = ((chan_121 < 0) || (chan_121 >= hihat_hit_values_channels));
					t_sample v = ((chan_ignore_122 || index_ignore_120) ? 0 : m_hihat_hit_values_32.read(i_16515, chan_121));
					int hit = ((int)0);
					if (((v < (((int)1) - m_knob6_hihatDensity_49)) && (h == ((int)1)))) {
						hit = ((int)1);
						
					};
					bool index_ignore_123 = ((i_16515 >= hihat_array_dim) || (i_16515 < 0));
					if ((!index_ignore_123)) {
						m_hihat_array_44.write(hit, i_16515, 0);
						
					};
					bool chan_ignore_124 = ((((int)1) < 0) || (((int)1) >= hihat_array_channels));
					bool index_ignore_125 = ((i_16515 >= hihat_array_dim) || (i_16515 < 0));
					if ((!(chan_ignore_124 || index_ignore_125))) {
						m_hihat_array_44.write(v, i_16515, ((int)1));
						
					};
					// for loop increment;
					i_16515 = (i_16515 + ((int)1));
					
				};
				
			};
			t_sample expr_16498 = m_hit_1_snare_21;
			t_sample expr_16499 = m_hit_2_snare_20;
			t_sample expr_16500 = m_hit_3_snare_19;
			t_sample expr_16501 = m_hit_4_snare_18;
			t_sample expr_16502 = m_hit_5_snare_17;
			t_sample expr_16503 = m_hit_6_snare_16;
			t_sample expr_16504 = m_hit_7_snare_15;
			t_sample expr_16505 = m_hit_8_snare_14;
			t_sample expr_16506 = m_hit_1_hihat_13;
			t_sample expr_16507 = m_hit_2_hihat_12;
			t_sample expr_16508 = m_hit_3_hihat_11;
			t_sample expr_16509 = m_hit_4_hihat_10;
			t_sample expr_16510 = m_hit_5_hihat_9;
			t_sample expr_16511 = m_hit_6_hihat_8;
			t_sample expr_16512 = m_hit_7_hihat_7;
			t_sample expr_16513 = m_hit_8_hihat_6;
			t_sample out11 = expr_16498;
			t_sample out26 = expr_16513;
			t_sample out16 = expr_16503;
			t_sample out25 = expr_16512;
			t_sample out21 = expr_16508;
			t_sample out14 = expr_16501;
			t_sample out19 = expr_16506;
			t_sample out18 = expr_16505;
			t_sample out22 = expr_16509;
			t_sample out13 = expr_16500;
			t_sample out23 = expr_16510;
			t_sample out12 = expr_16499;
			t_sample out15 = expr_16502;
			t_sample out17 = expr_16504;
			t_sample out24 = expr_16511;
			t_sample out20 = expr_16507;
			int trigger_beat_10127 = trigger_beat_10064;
			__m_latch_126 = ((trigger_beat_10127 != 0) ? floor_10254 : __m_latch_126);
			t_sample latch_10128 = __m_latch_126;
			int eq_10119 = (latch_10128 == ((int)7));
			t_sample out10 = (eq_10119 + expr_16495);
			int eq_10124 = (latch_10128 == ((int)2));
			t_sample out5 = (eq_10124 + expr_16490);
			int eq_10121 = (latch_10128 == ((int)5));
			t_sample out8 = (eq_10121 + expr_16493);
			int eq_10126 = (latch_10128 == ((int)0));
			t_sample out3 = (eq_10126 + expr_16488);
			int eq_10125 = (latch_10128 == ((int)1));
			t_sample out4 = (eq_10125 + expr_16489);
			int eq_10123 = (latch_10128 == ((int)3));
			t_sample out6 = (eq_10123 + expr_16491);
			int eq_10122 = (latch_10128 == ((int)4));
			t_sample out7 = (eq_10122 + expr_16492);
			int eq_10120 = (latch_10128 == ((int)6));
			t_sample out9 = (eq_10120 + expr_16494);
			int gt_10072 = (trigger_beat_10064 > ((int)0));
			int change_10071 = __m_change_127(gt_10072);
			int gt_10070 = (change_10071 > ((int)0));
			int plusequals_10069 = __m_pluseq_128.post(((int)1), gt_10070, 0);
			int lte_10068 = (plusequals_10069 <= max_10066);
			t_sample out34 = lte_10068;
			t_sample sub_10162 = (mix_10164 - mix_10185);
			t_sample phasor_10094 = __m_phasor_129(((int)5000), samples_to_seconds);
			t_sample delta_10089 = __m_delta_130(phasor_10094);
			t_sample abs_10093 = fabs(delta_10089);
			int gt_10092 = (abs_10093 > ((t_sample)0.5));
			int change_10091 = __m_change_131(gt_10092);
			int gt_10090 = (change_10091 > ((int)0));
			__m_count_132 = (((int)0) ? 0 : (fixdenorm(__m_count_132 + gt_10090)));
			int carry_133 = 0;
			if ((((int)0) != 0)) {
				__m_count_132 = 0;
				__m_carry_134 = 0;
				
			} else if (((((int)63) > 0) && (__m_count_132 >= ((int)63)))) {
				int wraps_135 = (__m_count_132 / ((int)63));
				__m_carry_134 = (__m_carry_134 + wraps_135);
				__m_count_132 = (__m_count_132 - (wraps_135 * ((int)63)));
				carry_133 = 1;
				
			};
			int counter_10098 = __m_count_132;
			int counter_10099 = carry_133;
			int counter_10100 = __m_carry_134;
			int add_10088 = (counter_10098 + ((int)1));
			t_sample out31 = add_10088;
			bool index_ignore_136 = ((counter_10098 >= grid_matrix_noise_dim) || (counter_10098 < 0));
			// samples grid_matrix_noise channel 1;
			t_sample sample_grid_matrix_noise_10095 = (index_ignore_136 ? 0 : m_grid_matrix_noise_27.read(counter_10098, 0));
			t_sample index_grid_matrix_noise_10096 = counter_10098;
			t_sample out32 = sample_grid_matrix_noise_10095;
			t_sample phasor_10181 = __m_phasor_137(((int)330), samples_to_seconds);
			t_sample triangle_10180 = triangle(phasor_10181, ((t_sample)0.5));
			t_sample phasor_10179 = __m_phasor_138(((int)185), samples_to_seconds);
			t_sample triangle_10178 = triangle(phasor_10179, ((t_sample)0.5));
			int trigger_beat_10117 = trigger_beat_10064;
			t_sample delta_10211 = __m_delta_139(wrap_10010);
			t_sample abs_10215 = fabs(delta_10211);
			int gt_10214 = (abs_10215 > ((t_sample)0.5));
			int change_10213 = __m_change_140(gt_10214);
			int gt_10212 = (change_10213 > ((int)0));
			int trigger_master_10218 = gt_10212;
			__m_count_141 = (trigger_master_10218 ? 0 : (fixdenorm(__m_count_141 + gt_10207)));
			int counter_10221 = __m_count_141;
			int counter_10222 = ((int)0);
			int counter_10223 = ((int)0);
			bool index_ignore_142 = ((counter_10221 >= kick_array_dim) || (counter_10221 < 0));
			// samples kick_array channel 1;
			t_sample sample_kick_array_10144 = (index_ignore_142 ? 0 : m_kick_array_53.read(counter_10221, 0));
			t_sample index_kick_array_10145 = counter_10221;
			t_sample kick_boolean_10143 = sample_kick_array_10144;
			__m_latch_143 = ((kick_boolean_10143 != 0) ? trigger_beat_10117 : __m_latch_143);
			t_sample latch_10142 = __m_latch_143;
			t_sample delta_10157 = __m_delta_144(latch_10142);
			t_sample abs_10133 = fabs(delta_10157);
			int gt_10132 = (abs_10133 > ((t_sample)0.5));
			int change_10131 = __m_change_145(gt_10132);
			int gt_10130 = (change_10131 > ((int)0));
			t_sample plusequals_10135 = __m_pluseq_146.post(safediv(8, samplerate), gt_10130, 0);
			t_sample clamp_10134 = ((plusequals_10135 <= ((int)0)) ? ((int)0) : ((plusequals_10135 >= ((int)1)) ? ((int)1) : plusequals_10135));
			t_sample sub_17217 = (clamp_10134 - ((int)0));
			t_sample scale_17214 = ((safepow((sub_17217 * ((t_sample)1)), (1 * ((t_sample)0.25))) * ((int)-1)) + ((int)1));
			t_sample scale_10136 = scale_17214;
			t_sample sub_17221 = (scale_10136 - ((int)1));
			t_sample scale_17218 = ((safepow((sub_17221 * ((t_sample)-1)), ((int)1)) * ((int)-100)) + ((int)150));
			t_sample scale_10139 = scale_17218;
			t_sample sin_10140 = sin(scale_10139);
			t_sample mul_10141 = (scale_10136 * sin_10140);
			t_sample mix_17222 = (mul_10141 + (((t_sample)0.9) * (m_history_1 - mul_10141)));
			t_sample mix_10138 = mix_17222;
			bool index_ignore_147 = ((counter_10221 >= hihat_array_dim) || (counter_10221 < 0));
			// samples hihat_array channel 1;
			t_sample sample_hihat_array_10219 = (index_ignore_147 ? 0 : m_hihat_array_44.read(counter_10221, 0));
			t_sample index_hihat_array_10220 = counter_10221;
			__m_latch_148 = ((sample_hihat_array_10219 != 0) ? trigger_beat_10064 : __m_latch_148);
			t_sample latch_10224 = __m_latch_148;
			t_sample delta_10189 = __m_delta_149(latch_10224);
			t_sample abs_10193 = fabs(delta_10189);
			int gt_10192 = (abs_10193 > ((t_sample)0.5));
			int change_10191 = __m_change_150(gt_10192);
			int gt_10190 = (change_10191 > ((int)0));
			t_sample plusequals_10199 = __m_pluseq_151.post(((t_sample)0.0003239390994493), gt_10190, 0);
			t_sample clamp_10198 = ((plusequals_10199 <= ((int)0)) ? ((int)0) : ((plusequals_10199 >= ((int)1)) ? ((int)1) : plusequals_10199));
			t_sample sub_17226 = (clamp_10198 - ((int)0));
			t_sample scale_17223 = ((safepow((sub_17226 * ((t_sample)1)), (1 * ((t_sample)0.25))) * ((int)-1)) + ((int)1));
			t_sample mul_10203 = (scale_17223 * sub_10200);
			bool index_ignore_152 = ((counter_10221 >= snare_array_dim) || (counter_10221 < 0));
			// samples snare_array channel 1;
			t_sample sample_snare_array_10232 = (index_ignore_152 ? 0 : m_snare_array_45.read(counter_10221, 0));
			t_sample index_snare_array_10233 = counter_10221;
			__m_latch_153 = ((sample_snare_array_10232 != 0) ? trigger_beat_10064 : __m_latch_153);
			t_sample latch_10228 = __m_latch_153;
			t_sample delta_10116 = __m_delta_154(latch_10228);
			t_sample abs_10161 = fabs(delta_10116);
			int gt_10160 = (abs_10161 > ((t_sample)0.5));
			int change_10159 = __m_change_155(gt_10160);
			int gt_10158 = (change_10159 > ((int)0));
			t_sample plusequals_10183 = __m_pluseq_156.post(safediv(13, samplerate), gt_10158, 0);
			t_sample clamp_10182 = ((plusequals_10183 <= ((int)0)) ? ((int)0) : ((plusequals_10183 >= ((int)1)) ? ((int)1) : plusequals_10183));
			t_sample sub_17230 = (clamp_10182 - ((int)0));
			t_sample scale_17227 = ((safepow((sub_17230 * ((t_sample)1)), (1 * ((t_sample)0.5))) * ((int)-1)) + ((int)1));
			t_sample mul_10186 = (scale_17227 * triangle_10180);
			t_sample plusequals_10168 = __m_pluseq_157.post(safediv(7, samplerate), gt_10158, 0);
			t_sample clamp_10166 = ((plusequals_10168 <= ((int)0)) ? ((int)0) : ((plusequals_10168 >= ((int)1)) ? ((int)1) : plusequals_10168));
			t_sample sub_17234 = (clamp_10166 - ((int)0));
			t_sample scale_17231 = ((safepow((sub_17234 * ((t_sample)1)), (1 * ((t_sample)0.5))) * ((t_sample)-0.5)) + ((t_sample)0.5));
			t_sample mul_10165 = (scale_17231 * sub_10162);
			t_sample plusequals_10176 = __m_pluseq_158.post(safediv(8, samplerate), gt_10158, 0);
			t_sample clamp_10172 = ((plusequals_10176 <= ((int)0)) ? ((int)0) : ((plusequals_10176 >= ((int)1)) ? ((int)1) : plusequals_10176));
			t_sample sub_17238 = (clamp_10172 - ((int)0));
			t_sample scale_17235 = ((safepow((sub_17238 * ((t_sample)1)), (1 * ((t_sample)0.5))) * ((t_sample)-0.7)) + ((t_sample)0.7));
			t_sample mul_10170 = (scale_17235 * mix_10164);
			t_sample plusequals_10177 = __m_pluseq_159.post(safediv(11, samplerate), gt_10158, 0);
			t_sample clamp_10174 = ((plusequals_10177 <= ((int)0)) ? ((int)0) : ((plusequals_10177 >= ((int)1)) ? ((int)1) : plusequals_10177));
			t_sample sub_17242 = (clamp_10174 - ((int)0));
			t_sample scale_17239 = ((safepow((sub_17242 * ((t_sample)1)), (1 * ((t_sample)0.5))) * ((int)-1)) + ((int)1));
			t_sample mul_10171 = (scale_17239 * triangle_10178);
			t_sample v_160 = (((mul_10171 + mul_10170) + mul_10165) + mul_10186);
			t_sample clamp_10169 = ((v_160 <= min_161) ? min_161 : ((v_160 >= ((int)1)) ? ((int)1) : v_160));
			t_sample add_10080 = (mul_10203 + clamp_10169);
			t_sample mul_10076 = (add_10080 * ((t_sample)0.5));
			t_sample add_10079 = (mul_10076 + mix_10138);
			t_sample mul_10073 = (add_10079 * ((t_sample)0.5));
			t_sample mix_17243 = (mul_10073 + (((t_sample)0.5) * (in2 - mul_10073)));
			t_sample out2 = mix_17243;
			t_sample add_10083 = (mul_10203 + clamp_10169);
			t_sample mul_10075 = (add_10083 * ((t_sample)0.5));
			t_sample add_10082 = (mul_10075 + mix_10138);
			t_sample mul_10074 = (add_10082 * ((t_sample)0.5));
			t_sample mix_17244 = (mul_10074 + (((t_sample)0.5) * (in1 - mul_10074)));
			t_sample out1 = mix_17244;
			t_sample history_10163_next_16517 = fixdenorm(mix_10164);
			t_sample history_10184_next_16518 = fixdenorm(mix_10185);
			t_sample history_10201_next_16519 = fixdenorm(mix_10202);
			t_sample history_10011_next_16520 = fixdenorm(wrap_10010);
			t_sample history_10137_next_16521 = fixdenorm(mix_10138);
			m_y_26 = y_next_10041;
			m_z_24 = z_next_10043;
			m_x_25 = x_next_10042;
			m_history_23 = history_10049_next_10056;
			m_history_22 = history_10052_next_10057;
			m_history_5 = history_10163_next_16517;
			m_history_4 = history_10184_next_16518;
			m_history_3 = history_10201_next_16519;
			m_history_2 = history_10011_next_16520;
			m_history_1 = history_10137_next_16521;
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
	inline void set_grid_matrix_noise(void * _value) {
		m_grid_matrix_noise_27.setbuffer(_value);
	};
	inline void set_hihat_patterns(void * _value) {
		m_hihat_patterns_28.setbuffer(_value);
	};
	inline void set_sw5(t_param _value) {
		m_sw_29 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw3(t_param _value) {
		m_sw_30 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob1_bpm(t_param _value) {
		m_knob1_bpm_31 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_hihat_hit_values(void * _value) {
		m_hihat_hit_values_32.setbuffer(_value);
	};
	inline void set_sw4(t_param _value) {
		m_sw_41 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_snare_patterns(void * _value) {
		m_snare_patterns_42.setbuffer(_value);
	};
	inline void set_sw6(t_param _value) {
		m_sw_43 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_hihat_array(void * _value) {
		m_hihat_array_44.setbuffer(_value);
	};
	inline void set_snare_array(void * _value) {
		m_snare_array_45.setbuffer(_value);
	};
	inline void set_sw7(t_param _value) {
		m_sw_46 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob2_X(t_param _value) {
		m_knob2_X_47 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob5_snareDensity(t_param _value) {
		m_knob5_snareDensity_48 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob6_hihatDensity(t_param _value) {
		m_knob6_hihatDensity_49 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob4_swing(t_param _value) {
		m_knob4_swing_50 = (_value < 1 ? 1 : (_value > 0 ? 0 : _value));
	};
	inline void set_mix(t_param _value) {
		m_mix_51 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_knob3_Y(t_param _value) {
		m_knob3_Y_52 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_kick_array(void * _value) {
		m_kick_array_53.setbuffer(_value);
	};
	inline void set_snare_hit_values(void * _value) {
		m_snare_hit_values_54.setbuffer(_value);
	};
	inline void set_sw1(t_param _value) {
		m_sw_55 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw2(t_param _value) {
		m_sw_56 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw8(t_param _value) {
		m_sw_57 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_noise_array(void * _value) {
		m_noise_array_58.setbuffer(_value);
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
		
		
		
		
		
		case 5: *value = self->m_knob1_bpm_31; break;
		case 6: *value = self->m_knob2_X_47; break;
		case 7: *value = self->m_knob3_Y_52; break;
		case 8: *value = self->m_knob4_swing_50; break;
		case 9: *value = self->m_knob5_snareDensity_48; break;
		case 10: *value = self->m_knob6_hihatDensity_49; break;
		case 11: *value = self->m_mix_51; break;
		
		
		
		
		case 16: *value = self->m_sw_55; break;
		case 17: *value = self->m_sw_56; break;
		case 18: *value = self->m_sw_30; break;
		case 19: *value = self->m_sw_41; break;
		case 20: *value = self->m_sw_29; break;
		case 21: *value = self->m_sw_43; break;
		case 22: *value = self->m_sw_46; break;
		case 23: *value = self->m_sw_57; break;
		
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
	// initialize parameter 0 ("m_grid_matrix_noise_27")
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
	// initialize parameter 1 ("m_hihat_array_44")
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
	// initialize parameter 2 ("m_hihat_hit_values_32")
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
	// initialize parameter 3 ("m_hihat_patterns_28")
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
	// initialize parameter 5 ("m_knob1_bpm_31")
	pi = self->__commonstate.params + 5;
	pi->name = "knob1_bpm";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob1_bpm_31;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_knob2_X_47")
	pi = self->__commonstate.params + 6;
	pi->name = "knob2_X";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob2_X_47;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 7 ("m_knob3_Y_52")
	pi = self->__commonstate.params + 7;
	pi->name = "knob3_Y";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob3_Y_52;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 8 ("m_knob4_swing_50")
	pi = self->__commonstate.params + 8;
	pi->name = "knob4_swing";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob4_swing_50;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1;
	pi->outputmax = 0;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 9 ("m_knob5_snareDensity_48")
	pi = self->__commonstate.params + 9;
	pi->name = "knob5_snareDensity";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob5_snareDensity_48;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 10 ("m_knob6_hihatDensity_49")
	pi = self->__commonstate.params + 10;
	pi->name = "knob6_hihatDensity";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_knob6_hihatDensity_49;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 11 ("m_mix_51")
	pi = self->__commonstate.params + 11;
	pi->name = "mix";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_mix_51;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 12 ("m_noise_array_58")
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
	// initialize parameter 13 ("m_snare_array_45")
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
	// initialize parameter 14 ("m_snare_hit_values_54")
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
	// initialize parameter 15 ("m_snare_patterns_42")
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
	// initialize parameter 17 ("m_sw_56")
	pi = self->__commonstate.params + 17;
	pi->name = "sw2";
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
	// initialize parameter 18 ("m_sw_30")
	pi = self->__commonstate.params + 18;
	pi->name = "sw3";
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
	// initialize parameter 19 ("m_sw_41")
	pi = self->__commonstate.params + 19;
	pi->name = "sw4";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_41;
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
	// initialize parameter 21 ("m_sw_43")
	pi = self->__commonstate.params + 21;
	pi->name = "sw6";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_43;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 22 ("m_sw_46")
	pi = self->__commonstate.params + 22;
	pi->name = "sw7";
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
	// initialize parameter 23 ("m_sw_57")
	pi = self->__commonstate.params + 23;
	pi->name = "sw8";
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
	
	return self;
}

/// Release all resources and memory used by a State object:

void destroy(CommonState *cself) {
	State *self = (State *)cself;
	genlib_sysmem_freeptr(cself->params);
		
	delete self;
}


} // KHAIROS::
