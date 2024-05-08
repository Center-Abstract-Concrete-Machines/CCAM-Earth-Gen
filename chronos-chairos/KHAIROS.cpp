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
	Change __m_change_89;
	Change __m_change_69;
	Change __m_change_132;
	Change __m_change_139;
	Change __m_change_68;
	Change __m_change_73;
	Change __m_change_70;
	Change __m_change_95;
	Change __m_change_96;
	Change __m_change_72;
	Change __m_change_71;
	Change __m_change_67;
	Change __m_change_141;
	Change __m_change_66;
	Change __m_change_153;
	Change __m_change_143;
	Change __m_change_158;
	Change __m_change_148;
	Data m_hihat_hit_values_47;
	Data m_hihat_patterns_44;
	Data m_hihat_array_48;
	Data m_kick_array_28;
	Data m_snare_hit_values_53;
	Data m_snare_array_38;
	Data m_noise_array_57;
	Data m_grid_matrix_noise_56;
	Data m_snare_patterns_43;
	Delta __m_delta_94;
	Delta __m_delta_157;
	Delta __m_delta_147;
	Delta __m_delta_152;
	Delta __m_delta_131;
	Delta __m_delta_142;
	Phasor __m_phasor_92;
	Phasor __m_phasor_93;
	Phasor __m_phasor_138;
	Phasor __m_phasor_91;
	Phasor __m_phasor_130;
	PlusEquals __m_pluseq_159;
	PlusEquals __m_pluseq_161;
	PlusEquals __m_pluseq_160;
	PlusEquals __m_pluseq_162;
	PlusEquals __m_pluseq_149;
	PlusEquals __m_pluseq_154;
	PlusEquals __m_pluseq_140;
	int __loopcount;
	int __exception;
	int vectorsize;
	t_sample m_hit_1_hihat_14;
	t_sample m_gatein_45;
	t_sample m_hit_2_hihat_13;
	t_sample m_hit_3_hihat_12;
	t_sample m_hit_4_hihat_11;
	t_sample __m_carry_135;
	t_sample m_hit_5_hihat_10;
	t_sample __m_count_133;
	t_sample m_hit_7_snare_16;
	t_sample m_hit_5_snare_18;
	t_sample m_hit_8_snare_15;
	t_sample __m_latch_129;
	t_sample m_hit_6_snare_17;
	t_sample m_hit_6_hihat_9;
	t_sample __m_count_144;
	t_sample __m_latch_146;
	t_sample __m_latch_156;
	t_sample m_history_3;
	t_sample m_history_2;
	t_sample samplerate;
	t_sample m_history_1;
	t_sample m_hit_4_snare_19;
	t_sample m_history_4;
	t_sample __m_latch_151;
	t_sample m_hit_7_hihat_8;
	t_sample m_history_5;
	t_sample m_hit_8_hihat_7;
	t_sample m_history_6;
	t_sample m_mix_42;
	t_sample m_hit_3_snare_20;
	t_sample m_hit_1_snare_22;
	t_sample m_sw_37;
	t_sample m_sw_52;
	t_sample m_Y_54;
	t_sample m_led_36;
	t_sample m_bpm_55;
	t_sample m_led_35;
	t_sample m_sw_39;
	t_sample m_sw_49;
	t_sample m_density_hihat_46;
	t_sample m_swing_50;
	t_sample m_sw_41;
	t_sample m_density_snare_40;
	t_sample m_hit_2_snare_21;
	t_sample elapsed;
	t_sample m_led_33;
	t_sample m_sw_24;
	t_sample m_sw_25;
	t_sample __m_latch_90;
	t_sample m_history_23;
	t_sample samples_to_seconds;
	t_sample m_led_34;
	t_sample m_sw_26;
	t_sample m_led_29;
	t_sample m_led_32;
	t_sample m_cv_27;
	t_sample m_led_31;
	t_sample m_led_30;
	t_sample m_X_51;
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
		m_hit_8_hihat_7 = ((int)0);
		m_hit_7_hihat_8 = ((int)0);
		m_hit_6_hihat_9 = ((int)0);
		m_hit_5_hihat_10 = ((int)0);
		m_hit_4_hihat_11 = ((int)0);
		m_hit_3_hihat_12 = ((int)0);
		m_hit_2_hihat_13 = ((int)0);
		m_hit_1_hihat_14 = ((int)0);
		m_hit_8_snare_15 = ((int)0);
		m_hit_7_snare_16 = ((int)0);
		m_hit_6_snare_17 = ((int)0);
		m_hit_5_snare_18 = ((int)0);
		m_hit_4_snare_19 = ((int)0);
		m_hit_3_snare_20 = ((int)0);
		m_hit_2_snare_21 = ((int)0);
		m_hit_1_snare_22 = ((int)0);
		m_history_23 = ((int)0);
		m_sw_24 = ((int)0);
		m_sw_25 = ((int)0);
		m_sw_26 = ((int)0);
		m_cv_27 = ((int)0);
		m_kick_array_28.reset("kick_array", ((int)8), ((int)1));
		m_led_29 = ((int)0);
		m_led_30 = ((int)0);
		m_led_31 = ((int)0);
		m_led_32 = ((int)0);
		m_led_33 = ((int)0);
		m_led_34 = ((int)0);
		m_led_35 = ((int)0);
		m_led_36 = ((int)0);
		m_sw_37 = ((int)0);
		m_snare_array_38.reset("snare_array", ((int)8), ((int)2));
		m_sw_39 = ((int)0);
		m_density_snare_40 = ((int)1);
		m_sw_41 = ((int)0);
		m_mix_42 = ((int)0);
		m_snare_patterns_43.reset("snare_patterns", ((int)8), ((int)64));
		m_hihat_patterns_44.reset("hihat_patterns", ((int)8), ((int)64));
		m_gatein_45 = ((int)0);
		m_density_hihat_46 = ((int)1);
		m_hihat_hit_values_47.reset("hihat_hit_values", ((int)8), ((int)64));
		m_hihat_array_48.reset("hihat_array", ((int)8), ((int)2));
		m_sw_49 = ((int)0);
		m_swing_50 = ((int)0);
		m_X_51 = ((int)0);
		m_sw_52 = ((int)0);
		m_snare_hit_values_53.reset("snare_hit_values", ((int)8), ((int)64));
		m_Y_54 = ((int)0);
		m_bpm_55 = ((int)0);
		m_grid_matrix_noise_56.reset("grid_matrix_noise", ((int)64), ((int)1));
		m_noise_array_57.reset("noise_array", ((int)48000), ((int)1));
		elapsed = 0;
		__m_change_66.reset(0);
		__m_change_67.reset(0);
		__m_change_68.reset(0);
		__m_change_69.reset(0);
		__m_change_70.reset(0);
		__m_change_71.reset(0);
		__m_change_72.reset(0);
		__m_change_73.reset(0);
		__m_change_89.reset(0);
		__m_latch_90 = 11025;
		samples_to_seconds = (1 / samplerate);
		__m_phasor_91.reset(0);
		__m_phasor_92.reset(0);
		__m_phasor_93.reset(0);
		__m_delta_94.reset(0);
		__m_change_95.reset(0);
		__m_change_96.reset(0);
		__m_latch_129 = 0;
		__m_phasor_130.reset(0);
		__m_delta_131.reset(0);
		__m_change_132.reset(0);
		__m_count_133 = 0;
		__m_carry_135 = 0;
		__m_phasor_138.reset(0);
		__m_change_139.reset(0);
		__m_pluseq_140.reset(0);
		__m_change_141.reset(0);
		__m_delta_142.reset(0);
		__m_change_143.reset(0);
		__m_count_144 = 0;
		__m_latch_146 = 0;
		__m_delta_147.reset(0);
		__m_change_148.reset(0);
		__m_pluseq_149.reset(0);
		__m_latch_151 = 0;
		__m_delta_152.reset(0);
		__m_change_153.reset(0);
		__m_pluseq_154.reset(0);
		__m_latch_156 = 0;
		__m_delta_157.reset(0);
		__m_change_158.reset(0);
		__m_pluseq_159.reset(0);
		__m_pluseq_160.reset(0);
		__m_pluseq_161.reset(0);
		__m_pluseq_162.reset(0);
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
		t_sample * __out35 = __outs[34];
		t_sample * __out36 = __outs[35];
		t_sample * __out37 = __outs[36];
		if (__exception) {
			return __exception;
			
		} else if (( (__in1 == 0) || (__in2 == 0) || (__out1 == 0) || (__out2 == 0) || (__out3 == 0) || (__out4 == 0) || (__out5 == 0) || (__out6 == 0) || (__out7 == 0) || (__out8 == 0) || (__out9 == 0) || (__out10 == 0) || (__out11 == 0) || (__out12 == 0) || (__out13 == 0) || (__out14 == 0) || (__out15 == 0) || (__out16 == 0) || (__out17 == 0) || (__out18 == 0) || (__out19 == 0) || (__out20 == 0) || (__out21 == 0) || (__out22 == 0) || (__out23 == 0) || (__out24 == 0) || (__out25 == 0) || (__out26 == 0) || (__out27 == 0) || (__out28 == 0) || (__out29 == 0) || (__out30 == 0) || (__out31 == 0) || (__out32 == 0) || (__out33 == 0) || (__out34 == 0) || (__out35 == 0) || (__out36 == 0) || (__out37 == 0) )) {
			__exception = GENLIB_ERR_NULL_BUFFER;
			return __exception;
			
		};
		__loopcount = (__n * GENLIB_LOOPCOUNT_BAIL);
		t_sample sub_48403 = (m_X_51 - ((int)0));
		t_sample scale_48400 = ((safepow((sub_48403 * ((t_sample)1)), ((int)1)) * ((int)7)) + ((int)1));
		t_sample expr_47951 = round(scale_48400);
		t_sample sub_48407 = (m_Y_54 - ((int)0));
		t_sample scale_48404 = ((safepow((sub_48407 * ((t_sample)1)), ((int)1)) * ((int)7)) + ((int)1));
		t_sample expr_47952 = round(scale_48404);
		int gt_47722 = (m_gatein_45 > ((int)0));
		samples_to_seconds = (1 / samplerate);
		t_sample sub_48414 = (m_swing_50 - ((int)0));
		t_sample scale_48411 = ((safepow((sub_48414 * ((t_sample)1)), ((int)1)) * ((t_sample)0.25)) + ((t_sample)0.5));
		t_sample scale_47760 = scale_48411;
		int gt_47712 = (m_bpm_55 > ((t_sample)0.01));
		t_sample sub_48418 = (m_bpm_55 - ((int)0));
		t_sample scale_48415 = ((safepow((sub_48418 * ((t_sample)1)), ((int)1)) * ((int)460)) + ((int)40));
		t_sample scale_47846 = scale_48415;
		t_sample clamp_47772 = ((scale_47760 <= ((int)0)) ? ((int)0) : ((scale_47760 >= ((int)1)) ? ((int)1) : scale_47760));
		t_sample rsub_47769 = (((int)1) - clamp_47772);
		t_sample irange_48421 = (rsub_47769 - ((int)0));
		t_sample irange_48425 = (((int)1) - rsub_47769);
		int grid_matrix_noise_dim = m_grid_matrix_noise_56.dim;
		int grid_matrix_noise_channels = m_grid_matrix_noise_56.channels;
		t_sample mstosamps_47734 = (((int)1) * (samplerate * 0.001));
		t_sample max_47735 = ((mstosamps_47734 < vectorsize) ? vectorsize : mstosamps_47734);
		int hihat_array_dim = m_hihat_array_48.dim;
		int hihat_array_channels = m_hihat_array_48.channels;
		int kick_array_dim = m_kick_array_28.dim;
		int kick_array_channels = m_kick_array_28.channels;
		int snare_array_dim = m_snare_array_38.dim;
		int snare_array_channels = m_snare_array_38.channels;
		int min_164 = (-1);
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
						t_sample noise_48381 = noise();
						t_sample sub_48384 = (noise_48381 - (-1));
						t_sample scale_48380 = ((safepow((sub_48384 * ((t_sample)0.5)), ((int)1)) * ((t_sample)0.85)) + ((t_sample)0.1));
						t_sample noise_48391 = noise();
						t_sample sub_48394 = (noise_48391 - (-1));
						t_sample scale_48390 = ((safepow((sub_48394 * ((t_sample)0.5)), ((int)1)) * ((t_sample)0.85)) + ((t_sample)0.1));
						int snare_patterns_dim = m_snare_patterns_43.dim;
						int snare_patterns_channels = m_snare_patterns_43.channels;
						bool chan_ignore_58 = ((c < 0) || (c >= snare_patterns_channels));
						bool index_ignore_59 = ((i >= snare_patterns_dim) || (i < 0));
						if ((!(chan_ignore_58 || index_ignore_59))) {
							m_snare_patterns_43.write(((int)1), i, c);
							
						};
						int snare_hit_values_dim = m_snare_hit_values_53.dim;
						int snare_hit_values_channels = m_snare_hit_values_53.channels;
						bool chan_ignore_60 = ((c < 0) || (c >= snare_hit_values_channels));
						bool index_ignore_61 = ((i >= snare_hit_values_dim) || (i < 0));
						if ((!(chan_ignore_60 || index_ignore_61))) {
							m_snare_hit_values_53.write(scale_48380, i, c);
							
						};
						int hihat_patterns_dim = m_hihat_patterns_44.dim;
						int hihat_patterns_channels = m_hihat_patterns_44.channels;
						bool chan_ignore_62 = ((c < 0) || (c >= hihat_patterns_channels));
						bool index_ignore_63 = ((i >= hihat_patterns_dim) || (i < 0));
						if ((!(chan_ignore_62 || index_ignore_63))) {
							m_hihat_patterns_44.write(((int)1), i, c);
							
						};
						int hihat_hit_values_dim = m_hihat_hit_values_47.dim;
						int hihat_hit_values_channels = m_hihat_hit_values_47.channels;
						bool chan_ignore_64 = ((c < 0) || (c >= hihat_hit_values_channels));
						bool index_ignore_65 = ((i >= hihat_hit_values_dim) || (i < 0));
						if ((!(chan_ignore_64 || index_ignore_65))) {
							m_hihat_hit_values_47.write(scale_48390, i, c);
							
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
			t_sample out29 = expr_47951;
			int sw_1 = (__m_change_66((m_sw_41 > ((int)0))) > ((int)0));
			int sw_2 = (__m_change_67((m_sw_52 > ((int)0))) > ((int)0));
			int sw_3 = (__m_change_68((m_sw_37 > ((int)0))) > ((int)0));
			int sw_4 = (__m_change_69((m_sw_39 > ((int)0))) > ((int)0));
			int sw_5 = (__m_change_70((m_sw_26 > ((int)0))) > ((int)0));
			int sw_6 = (__m_change_71((m_sw_24 > ((int)0))) > ((int)0));
			int sw_7 = (__m_change_72((m_sw_49 > ((int)0))) > ((int)0));
			int sw_8 = (__m_change_73((m_sw_25 > ((int)0))) > ((int)0));
			if ((elapsed == ((int)0))) {
				// for loop initializer;
				int i_47979 = ((int)0);
				// for loop condition;
				int kick_array_dim = m_kick_array_28.dim;
				int kick_array_channels = m_kick_array_28.channels;
				while ((i_47979 < kick_array_dim)) {
					// abort processing if an infinite loop is suspected;
					if (((__loopcount--) <= 0)) {
						__exception = GENLIB_ERR_LOOP_OVERFLOW;
						break ;
						
					};
					bool index_ignore_74 = ((i_47979 >= kick_array_dim) || (i_47979 < 0));
					if ((!index_ignore_74)) {
						m_kick_array_28.write(((int)0), i_47979, 0);
						
					};
					// for loop increment;
					i_47979 = (i_47979 + ((int)1));
					
				};
				m_led_36 = ((int)1);
				m_led_35 = ((int)1);
				m_led_34 = ((int)1);
				m_led_33 = ((int)1);
				m_led_32 = ((int)1);
				m_led_31 = ((int)1);
				m_led_30 = ((int)1);
				m_led_29 = ((int)1);
				
			};
			if (sw_1) {
				int kick_array_dim = m_kick_array_28.dim;
				int kick_array_channels = m_kick_array_28.channels;
				// samples kick_array channel 1;
				t_sample a = m_kick_array_28.read(0, 0);
				m_kick_array_28.write((!a), 0, 0);
				m_led_36 = a;
				
			};
			if (sw_2) {
				int kick_array_dim = m_kick_array_28.dim;
				int kick_array_channels = m_kick_array_28.channels;
				bool index_ignore_75 = (((int)1) >= kick_array_dim);
				// samples kick_array channel 1;
				t_sample a = (index_ignore_75 ? 0 : m_kick_array_28.read(((int)1), 0));
				bool index_ignore_76 = (((int)1) >= kick_array_dim);
				if ((!index_ignore_76)) {
					m_kick_array_28.write((!a), ((int)1), 0);
					
				};
				m_led_35 = a;
				
			};
			if (sw_3) {
				int kick_array_dim = m_kick_array_28.dim;
				int kick_array_channels = m_kick_array_28.channels;
				bool index_ignore_77 = (((int)2) >= kick_array_dim);
				// samples kick_array channel 1;
				t_sample a = (index_ignore_77 ? 0 : m_kick_array_28.read(((int)2), 0));
				bool index_ignore_78 = (((int)2) >= kick_array_dim);
				if ((!index_ignore_78)) {
					m_kick_array_28.write((!a), ((int)2), 0);
					
				};
				m_led_34 = a;
				
			};
			if (sw_4) {
				int kick_array_dim = m_kick_array_28.dim;
				int kick_array_channels = m_kick_array_28.channels;
				bool index_ignore_79 = (((int)3) >= kick_array_dim);
				// samples kick_array channel 1;
				t_sample a = (index_ignore_79 ? 0 : m_kick_array_28.read(((int)3), 0));
				bool index_ignore_80 = (((int)3) >= kick_array_dim);
				if ((!index_ignore_80)) {
					m_kick_array_28.write((!a), ((int)3), 0);
					
				};
				m_led_33 = a;
				
			};
			if (sw_5) {
				int kick_array_dim = m_kick_array_28.dim;
				int kick_array_channels = m_kick_array_28.channels;
				bool index_ignore_81 = (((int)4) >= kick_array_dim);
				// samples kick_array channel 1;
				t_sample a = (index_ignore_81 ? 0 : m_kick_array_28.read(((int)4), 0));
				bool index_ignore_82 = (((int)4) >= kick_array_dim);
				if ((!index_ignore_82)) {
					m_kick_array_28.write((!a), ((int)4), 0);
					
				};
				m_led_32 = a;
				
			};
			if (sw_6) {
				int kick_array_dim = m_kick_array_28.dim;
				int kick_array_channels = m_kick_array_28.channels;
				bool index_ignore_83 = (((int)5) >= kick_array_dim);
				// samples kick_array channel 1;
				t_sample a = (index_ignore_83 ? 0 : m_kick_array_28.read(((int)5), 0));
				bool index_ignore_84 = (((int)5) >= kick_array_dim);
				if ((!index_ignore_84)) {
					m_kick_array_28.write((!a), ((int)5), 0);
					
				};
				m_led_31 = a;
				
			};
			if (sw_7) {
				int kick_array_dim = m_kick_array_28.dim;
				int kick_array_channels = m_kick_array_28.channels;
				bool index_ignore_85 = (((int)6) >= kick_array_dim);
				// samples kick_array channel 1;
				t_sample a = (index_ignore_85 ? 0 : m_kick_array_28.read(((int)6), 0));
				bool index_ignore_86 = (((int)6) >= kick_array_dim);
				if ((!index_ignore_86)) {
					m_kick_array_28.write((!a), ((int)6), 0);
					
				};
				m_led_30 = a;
				
			};
			if (sw_8) {
				int kick_array_dim = m_kick_array_28.dim;
				int kick_array_channels = m_kick_array_28.channels;
				bool index_ignore_87 = (((int)7) >= kick_array_dim);
				// samples kick_array channel 1;
				t_sample a = (index_ignore_87 ? 0 : m_kick_array_28.read(((int)7), 0));
				bool index_ignore_88 = (((int)7) >= kick_array_dim);
				if ((!index_ignore_88)) {
					m_kick_array_28.write((!a), ((int)7), 0);
					
				};
				m_led_29 = a;
				
			};
			t_sample expr_47953 = m_led_36;
			t_sample expr_47954 = m_led_35;
			t_sample expr_47955 = m_led_34;
			t_sample expr_47956 = m_led_33;
			t_sample expr_47957 = m_led_32;
			t_sample expr_47958 = m_led_31;
			t_sample expr_47959 = m_led_30;
			t_sample expr_47960 = m_led_29;
			t_sample out30 = expr_47952;
			int change_47721 = __m_change_89(gt_47722);
			int gt_47720 = (change_47721 > ((int)0));
			int gen_47723 = gt_47720;
			t_sample out37 = gen_47723;
			t_sample noise_47894 = noise();
			t_sample mix_48408 = (noise_47894 + (((t_sample)0.7) * (m_history_6 - noise_47894)));
			t_sample mix_47892 = mix_48408;
			t_sample sub_47890 = (noise_47894 - mix_47892);
			t_sample add_47746 = (m_history_2 + ((int)1));
			t_sample noise_47877 = noise();
			t_sample mix_48409 = (noise_47877 + (((t_sample)0.5) * (m_history_5 - noise_47877)));
			t_sample mix_47854 = mix_48409;
			t_sample mix_48410 = (mix_47854 + (((t_sample)0.6) * (m_history_4 - mix_47854)));
			t_sample mix_47875 = mix_48410;
			t_sample add_47728 = (m_history_23 + ((int)1));
			t_sample switch_47725 = (gen_47723 ? ((int)0) : add_47728);
			__m_latch_90 = ((gen_47723 != 0) ? add_47728 : __m_latch_90);
			t_sample latch_47727 = __m_latch_90;
			t_sample gen_47730 = latch_47727;
			t_sample history_47726_next_47729 = fixdenorm(switch_47725);
			t_sample rdiv_47724 = safediv(samplerate, gen_47730);
			t_sample mul_47711 = (rdiv_47724 * ((int)60));
			t_sample out36 = mul_47711;
			t_sample sub_47852 = (mix_47854 - mix_47875);
			t_sample phasor_47871 = __m_phasor_91(((int)330), samples_to_seconds);
			t_sample triangle_47870 = triangle(phasor_47871, ((t_sample)0.5));
			t_sample phasor_47869 = __m_phasor_92(((int)185), samples_to_seconds);
			t_sample triangle_47868 = triangle(phasor_47869, ((t_sample)0.5));
			t_sample rdiv_47717 = safediv(((int)1), gen_47730);
			t_sample add_47719 = (m_history_3 + rdiv_47717);
			t_sample switch_47716 = (gen_47723 ? ((int)0) : add_47719);
			t_sample wrap_47718 = wrap(switch_47716, ((int)0), ((int)1));
			t_sample switch_47713 = (gt_47712 ? scale_47846 : mul_47711);
			t_sample div_47947 = (switch_47713 * ((t_sample)0.016666666666667));
			t_sample div_47808 = (div_47947 * ((t_sample)0.125));
			t_sample phasor_47946 = __m_phasor_93(div_47808, samples_to_seconds);
			t_sample phasor_measure_47758 = phasor_47946;
			t_sample out33 = phasor_measure_47758;
			t_sample mul_47757 = (phasor_measure_47758 * ((int)8));
			t_sample wrap_47755 = wrap(mul_47757, ((int)3), ((int)0));
			t_sample div_47753 = (wrap_47755 * ((t_sample)0.33333333333333));
			t_sample out34 = div_47753;
			t_sample mix_48419 = (div_47753 + (m_mix_42 * (phasor_measure_47758 - div_47753)));
			t_sample out35 = mix_48419;
			t_sample clamp_47764 = ((phasor_47946 <= ((int)0)) ? ((int)0) : ((phasor_47946 >= ((int)1)) ? ((int)1) : phasor_47946));
			int lt_47768 = (clamp_47764 < rsub_47769);
			t_sample sub_48423 = (clamp_47764 - ((int)0));
			t_sample scale_48420 = ((safepow(safediv(sub_48423, irange_48421), ((int)1)) * ((t_sample)0.5)) + ((int)0));
			t_sample scale_47773 = scale_48420;
			t_sample sub_48427 = (clamp_47764 - rsub_47769);
			t_sample scale_48424 = ((safepow(safediv(sub_48427, irange_48425), ((int)1)) * ((t_sample)0.5)) + ((t_sample)0.5));
			t_sample scale_47771 = scale_48424;
			t_sample switch_47767 = (lt_47768 ? scale_47773 : scale_47771);
			t_sample gen_47774 = switch_47767;
			t_sample mul_47945 = (gen_47774 * ((int)8));
			t_sample floor_47944 = floor(mul_47945);
			t_sample out28 = floor_47944;
			t_sample wrap_47921 = wrap(mul_47945, ((int)0), ((int)1));
			t_sample delta_47896 = __m_delta_94(wrap_47921);
			t_sample abs_47900 = fabs(delta_47896);
			int gt_47899 = (abs_47900 > ((t_sample)0.5));
			int change_47898 = __m_change_95(gt_47899);
			int gt_47897 = (change_47898 > ((int)0));
			int trigger_beat_47817 = gt_47897;
			int trigger_beat_47920 = trigger_beat_47817;
			int trig = (__m_change_96((trigger_beat_47920 > ((int)0))) > ((int)0));
			if (trig) {
				int snare_array_dim = m_snare_array_38.dim;
				int snare_array_channels = m_snare_array_38.channels;
				// samples snare_array channel 1;
				m_hit_1_snare_22 = m_snare_array_38.read(0, 0);
				bool index_ignore_97 = (((int)1) >= snare_array_dim);
				// samples snare_array channel 1;
				m_hit_2_snare_21 = (index_ignore_97 ? 0 : m_snare_array_38.read(((int)1), 0));
				bool index_ignore_98 = (((int)2) >= snare_array_dim);
				// samples snare_array channel 1;
				m_hit_3_snare_20 = (index_ignore_98 ? 0 : m_snare_array_38.read(((int)2), 0));
				bool index_ignore_99 = (((int)3) >= snare_array_dim);
				// samples snare_array channel 1;
				m_hit_4_snare_19 = (index_ignore_99 ? 0 : m_snare_array_38.read(((int)3), 0));
				bool index_ignore_100 = (((int)4) >= snare_array_dim);
				// samples snare_array channel 1;
				m_hit_5_snare_18 = (index_ignore_100 ? 0 : m_snare_array_38.read(((int)4), 0));
				bool index_ignore_101 = (((int)5) >= snare_array_dim);
				// samples snare_array channel 1;
				m_hit_6_snare_17 = (index_ignore_101 ? 0 : m_snare_array_38.read(((int)5), 0));
				bool index_ignore_102 = (((int)6) >= snare_array_dim);
				// samples snare_array channel 1;
				m_hit_7_snare_16 = (index_ignore_102 ? 0 : m_snare_array_38.read(((int)6), 0));
				bool index_ignore_103 = (((int)7) >= snare_array_dim);
				// samples snare_array channel 1;
				m_hit_8_snare_15 = (index_ignore_103 ? 0 : m_snare_array_38.read(((int)7), 0));
				int hihat_array_dim = m_hihat_array_48.dim;
				int hihat_array_channels = m_hihat_array_48.channels;
				// samples hihat_array channel 1;
				m_hit_1_hihat_14 = m_hihat_array_48.read(0, 0);
				bool index_ignore_104 = (((int)1) >= hihat_array_dim);
				// samples hihat_array channel 1;
				m_hit_2_hihat_13 = (index_ignore_104 ? 0 : m_hihat_array_48.read(((int)1), 0));
				bool index_ignore_105 = (((int)2) >= hihat_array_dim);
				// samples hihat_array channel 1;
				m_hit_3_hihat_12 = (index_ignore_105 ? 0 : m_hihat_array_48.read(((int)2), 0));
				bool index_ignore_106 = (((int)3) >= hihat_array_dim);
				// samples hihat_array channel 1;
				m_hit_4_hihat_11 = (index_ignore_106 ? 0 : m_hihat_array_48.read(((int)3), 0));
				bool index_ignore_107 = (((int)4) >= hihat_array_dim);
				// samples hihat_array channel 1;
				m_hit_5_hihat_10 = (index_ignore_107 ? 0 : m_hihat_array_48.read(((int)4), 0));
				bool index_ignore_108 = (((int)5) >= hihat_array_dim);
				// samples hihat_array channel 1;
				m_hit_6_hihat_9 = (index_ignore_108 ? 0 : m_hihat_array_48.read(((int)5), 0));
				bool index_ignore_109 = (((int)6) >= hihat_array_dim);
				// samples hihat_array channel 1;
				m_hit_7_hihat_8 = (index_ignore_109 ? 0 : m_hihat_array_48.read(((int)6), 0));
				bool index_ignore_110 = (((int)7) >= hihat_array_dim);
				// samples hihat_array channel 1;
				m_hit_8_hihat_7 = (index_ignore_110 ? 0 : m_hihat_array_48.read(((int)7), 0));
				// for loop initializer;
				int i_47981 = ((int)0);
				// for loop condition;
				while ((i_47981 < snare_array_dim)) {
					// abort processing if an infinite loop is suspected;
					if (((__loopcount--) <= 0)) {
						__exception = GENLIB_ERR_LOOP_OVERFLOW;
						break ;
						
					};
					t_sample sub_48431 = (m_X_51 - ((int)0));
					t_sample scale_48428 = ((safepow((sub_48431 * ((t_sample)1)), ((int)1)) * ((int)7)) + ((int)0));
					t_sample sub_48435 = (m_Y_54 - ((int)0));
					t_sample scale_48432 = ((safepow((sub_48435 * ((t_sample)1)), ((int)1)) * ((int)7)) + ((int)0));
					t_sample c_47980 = (round(scale_48428) + round((scale_48432 * ((int)8))));
					int snare_patterns_dim = m_snare_patterns_43.dim;
					int snare_patterns_channels = m_snare_patterns_43.channels;
					bool index_ignore_111 = ((i_47981 >= snare_patterns_dim) || (i_47981 < 0));
					// samples snare_patterns channel 1;
					int chan_112 = c_47980;
					bool chan_ignore_113 = ((chan_112 < 0) || (chan_112 >= snare_patterns_channels));
					t_sample h = ((chan_ignore_113 || index_ignore_111) ? 0 : m_snare_patterns_43.read(i_47981, chan_112));
					int snare_hit_values_dim = m_snare_hit_values_53.dim;
					int snare_hit_values_channels = m_snare_hit_values_53.channels;
					bool index_ignore_114 = ((i_47981 >= snare_hit_values_dim) || (i_47981 < 0));
					// samples snare_hit_values channel 1;
					int chan_115 = c_47980;
					bool chan_ignore_116 = ((chan_115 < 0) || (chan_115 >= snare_hit_values_channels));
					t_sample v = ((chan_ignore_116 || index_ignore_114) ? 0 : m_snare_hit_values_53.read(i_47981, chan_115));
					int hit = ((int)0);
					if (((v < (((int)1) - m_density_snare_40)) && (h == ((int)1)))) {
						hit = ((int)1);
						
					};
					bool index_ignore_117 = ((i_47981 >= snare_array_dim) || (i_47981 < 0));
					if ((!index_ignore_117)) {
						m_snare_array_38.write(hit, i_47981, 0);
						
					};
					bool chan_ignore_118 = ((((int)1) < 0) || (((int)1) >= snare_array_channels));
					bool index_ignore_119 = ((i_47981 >= snare_array_dim) || (i_47981 < 0));
					if ((!(chan_ignore_118 || index_ignore_119))) {
						m_snare_array_38.write(v, i_47981, ((int)1));
						
					};
					// for loop increment;
					i_47981 = (i_47981 + ((int)1));
					
				};
				// for loop initializer;
				i_47981 = ((int)0);
				// for loop condition;
				while ((i_47981 < hihat_array_dim)) {
					// abort processing if an infinite loop is suspected;
					if (((__loopcount--) <= 0)) {
						__exception = GENLIB_ERR_LOOP_OVERFLOW;
						break ;
						
					};
					t_sample sub_48439 = (m_X_51 - ((int)0));
					t_sample scale_48436 = ((safepow((sub_48439 * ((t_sample)1)), ((int)1)) * ((int)7)) + ((int)0));
					t_sample sub_48443 = (m_Y_54 - ((int)0));
					t_sample scale_48440 = ((safepow((sub_48443 * ((t_sample)1)), ((int)1)) * ((int)7)) + ((int)0));
					t_sample c_47980 = (round(scale_48436) + round((scale_48440 * ((int)8))));
					int hihat_patterns_dim = m_hihat_patterns_44.dim;
					int hihat_patterns_channels = m_hihat_patterns_44.channels;
					bool index_ignore_120 = ((i_47981 >= hihat_patterns_dim) || (i_47981 < 0));
					// samples hihat_patterns channel 1;
					int chan_121 = c_47980;
					bool chan_ignore_122 = ((chan_121 < 0) || (chan_121 >= hihat_patterns_channels));
					t_sample h = ((chan_ignore_122 || index_ignore_120) ? 0 : m_hihat_patterns_44.read(i_47981, chan_121));
					int hihat_hit_values_dim = m_hihat_hit_values_47.dim;
					int hihat_hit_values_channels = m_hihat_hit_values_47.channels;
					bool index_ignore_123 = ((i_47981 >= hihat_hit_values_dim) || (i_47981 < 0));
					// samples hihat_hit_values channel 1;
					int chan_124 = c_47980;
					bool chan_ignore_125 = ((chan_124 < 0) || (chan_124 >= hihat_hit_values_channels));
					t_sample v = ((chan_ignore_125 || index_ignore_123) ? 0 : m_hihat_hit_values_47.read(i_47981, chan_124));
					int hit = ((int)0);
					if (((v < (((int)1) - m_density_hihat_46)) && (h == ((int)1)))) {
						hit = ((int)1);
						
					};
					bool index_ignore_126 = ((i_47981 >= hihat_array_dim) || (i_47981 < 0));
					if ((!index_ignore_126)) {
						m_hihat_array_48.write(hit, i_47981, 0);
						
					};
					bool chan_ignore_127 = ((((int)1) < 0) || (((int)1) >= hihat_array_channels));
					bool index_ignore_128 = ((i_47981 >= hihat_array_dim) || (i_47981 < 0));
					if ((!(chan_ignore_127 || index_ignore_128))) {
						m_hihat_array_48.write(v, i_47981, ((int)1));
						
					};
					// for loop increment;
					i_47981 = (i_47981 + ((int)1));
					
				};
				
			};
			t_sample expr_47963 = m_hit_1_snare_22;
			t_sample expr_47964 = m_hit_2_snare_21;
			t_sample expr_47965 = m_hit_3_snare_20;
			t_sample expr_47966 = m_hit_4_snare_19;
			t_sample expr_47967 = m_hit_5_snare_18;
			t_sample expr_47968 = m_hit_6_snare_17;
			t_sample expr_47969 = m_hit_7_snare_16;
			t_sample expr_47970 = m_hit_8_snare_15;
			t_sample expr_47971 = m_hit_1_hihat_14;
			t_sample expr_47972 = m_hit_2_hihat_13;
			t_sample expr_47973 = m_hit_3_hihat_12;
			t_sample expr_47974 = m_hit_4_hihat_11;
			t_sample expr_47975 = m_hit_5_hihat_10;
			t_sample expr_47976 = m_hit_6_hihat_9;
			t_sample expr_47977 = m_hit_7_hihat_8;
			t_sample expr_47978 = m_hit_8_hihat_7;
			t_sample out26 = expr_47978;
			t_sample out19 = expr_47971;
			t_sample out20 = expr_47972;
			t_sample out21 = expr_47973;
			t_sample out13 = expr_47965;
			t_sample out22 = expr_47974;
			t_sample out25 = expr_47977;
			t_sample out23 = expr_47975;
			t_sample out12 = expr_47964;
			t_sample out24 = expr_47976;
			t_sample out11 = expr_47963;
			t_sample out17 = expr_47969;
			t_sample out14 = expr_47966;
			t_sample out15 = expr_47967;
			t_sample out16 = expr_47968;
			t_sample out18 = expr_47970;
			t_sample out27 = trigger_beat_47920;
			__m_latch_129 = ((trigger_beat_47817 != 0) ? floor_47944 : __m_latch_129);
			t_sample latch_47818 = __m_latch_129;
			int eq_47812 = (latch_47818 == ((int)4));
			t_sample out7 = (eq_47812 + expr_47957);
			int eq_47810 = (latch_47818 == ((int)6));
			t_sample out9 = (eq_47810 + expr_47959);
			int eq_47813 = (latch_47818 == ((int)3));
			t_sample out6 = (eq_47813 + expr_47956);
			int eq_47814 = (latch_47818 == ((int)2));
			t_sample out5 = (eq_47814 + expr_47955);
			int eq_47811 = (latch_47818 == ((int)5));
			t_sample out8 = (eq_47811 + expr_47958);
			int eq_47816 = (latch_47818 == ((int)0));
			t_sample out3 = (eq_47816 + expr_47953);
			int eq_47815 = (latch_47818 == ((int)1));
			t_sample out4 = (eq_47815 + expr_47954);
			int eq_47809 = (latch_47818 == ((int)7));
			t_sample out10 = (eq_47809 + expr_47960);
			t_sample phasor_47785 = __m_phasor_130(((int)5000), samples_to_seconds);
			t_sample delta_47780 = __m_delta_131(phasor_47785);
			t_sample abs_47784 = fabs(delta_47780);
			int gt_47783 = (abs_47784 > ((t_sample)0.5));
			int change_47782 = __m_change_132(gt_47783);
			int gt_47781 = (change_47782 > ((int)0));
			__m_count_133 = (((int)0) ? 0 : (fixdenorm(__m_count_133 + gt_47781)));
			int carry_134 = 0;
			if ((((int)0) != 0)) {
				__m_count_133 = 0;
				__m_carry_135 = 0;
				
			} else if (((((int)63) > 0) && (__m_count_133 >= ((int)63)))) {
				int wraps_136 = (__m_count_133 / ((int)63));
				__m_carry_135 = (__m_carry_135 + wraps_136);
				__m_count_133 = (__m_count_133 - (wraps_136 * ((int)63)));
				carry_134 = 1;
				
			};
			int counter_47789 = __m_count_133;
			int counter_47790 = carry_134;
			int counter_47791 = __m_carry_135;
			bool index_ignore_137 = ((counter_47789 >= grid_matrix_noise_dim) || (counter_47789 < 0));
			// samples grid_matrix_noise channel 1;
			t_sample sample_grid_matrix_noise_47786 = (index_ignore_137 ? 0 : m_grid_matrix_noise_56.read(counter_47789, 0));
			t_sample index_grid_matrix_noise_47787 = counter_47789;
			t_sample out32 = sample_grid_matrix_noise_47786;
			int add_47779 = (counter_47789 + ((int)1));
			t_sample out31 = add_47779;
			t_sample phasor_47742 = __m_phasor_138(((int)2), samples_to_seconds);
			int gt_47741 = (phasor_47742 > ((int)0));
			int change_47740 = __m_change_139(gt_47741);
			int gt_47739 = (change_47740 > ((int)0));
			int plusequals_47738 = __m_pluseq_140.post(((int)1), gt_47739, 0);
			int lte_47737 = (plusequals_47738 <= max_47735);
			int gt_47749 = (lte_47737 > ((int)0));
			int change_47748 = __m_change_141(gt_47749);
			int gt_47747 = (change_47748 > ((int)0));
			t_sample switch_47743 = (gt_47747 ? ((int)0) : add_47746);
			int trigger_beat_47906 = trigger_beat_47817;
			int trigger_beat_47807 = trigger_beat_47817;
			t_sample delta_47901 = __m_delta_142(phasor_47946);
			t_sample abs_47905 = fabs(delta_47901);
			int gt_47904 = (abs_47905 > ((t_sample)0.5));
			int change_47903 = __m_change_143(gt_47904);
			int gt_47902 = (change_47903 > ((int)0));
			int trigger_master_47908 = gt_47902;
			__m_count_144 = (trigger_master_47908 ? 0 : (fixdenorm(__m_count_144 + gt_47897)));
			int counter_47911 = __m_count_144;
			int counter_47912 = ((int)0);
			int counter_47913 = ((int)0);
			bool index_ignore_145 = ((counter_47911 >= hihat_array_dim) || (counter_47911 < 0));
			// samples hihat_array channel 1;
			t_sample sample_hihat_array_47909 = (index_ignore_145 ? 0 : m_hihat_array_48.read(counter_47911, 0));
			t_sample index_hihat_array_47910 = counter_47911;
			__m_latch_146 = ((sample_hihat_array_47909 != 0) ? trigger_beat_47906 : __m_latch_146);
			t_sample latch_47914 = __m_latch_146;
			t_sample delta_47879 = __m_delta_147(latch_47914);
			t_sample abs_47883 = fabs(delta_47879);
			int gt_47882 = (abs_47883 > ((t_sample)0.5));
			int change_47881 = __m_change_148(gt_47882);
			int gt_47880 = (change_47881 > ((int)0));
			t_sample plusequals_47889 = __m_pluseq_149.post(((t_sample)0.0003239390994493), gt_47880, 0);
			t_sample clamp_47888 = ((plusequals_47889 <= ((int)0)) ? ((int)0) : ((plusequals_47889 >= ((int)1)) ? ((int)1) : plusequals_47889));
			t_sample sub_48447 = (clamp_47888 - ((int)0));
			t_sample scale_48444 = ((safepow((sub_48447 * ((t_sample)1)), (1 * ((t_sample)0.25))) * ((int)-1)) + ((int)1));
			t_sample mul_47893 = (scale_48444 * sub_47890);
			bool index_ignore_150 = ((counter_47911 >= kick_array_dim) || (counter_47911 < 0));
			// samples kick_array channel 1;
			t_sample sample_kick_array_47834 = (index_ignore_150 ? 0 : m_kick_array_28.read(counter_47911, 0));
			t_sample index_kick_array_47835 = counter_47911;
			t_sample kick_boolean_47833 = sample_kick_array_47834;
			__m_latch_151 = ((kick_boolean_47833 != 0) ? trigger_beat_47807 : __m_latch_151);
			t_sample latch_47832 = __m_latch_151;
			t_sample delta_47847 = __m_delta_152(latch_47832);
			t_sample abs_47823 = fabs(delta_47847);
			int gt_47822 = (abs_47823 > ((t_sample)0.5));
			int change_47821 = __m_change_153(gt_47822);
			int gt_47820 = (change_47821 > ((int)0));
			t_sample plusequals_47825 = __m_pluseq_154.post(safediv(8, samplerate), gt_47820, 0);
			t_sample clamp_47824 = ((plusequals_47825 <= ((int)0)) ? ((int)0) : ((plusequals_47825 >= ((int)1)) ? ((int)1) : plusequals_47825));
			t_sample sub_48451 = (clamp_47824 - ((int)0));
			t_sample scale_48448 = ((safepow((sub_48451 * ((t_sample)1)), (1 * ((t_sample)0.25))) * ((int)-1)) + ((int)1));
			t_sample scale_47826 = scale_48448;
			t_sample sub_48455 = (scale_47826 - ((int)1));
			t_sample scale_48452 = ((safepow((sub_48455 * ((t_sample)-1)), ((int)1)) * ((int)-100)) + ((int)150));
			t_sample scale_47829 = scale_48452;
			t_sample sin_47830 = sin(scale_47829);
			t_sample mul_47831 = (scale_47826 * sin_47830);
			t_sample mix_48456 = (mul_47831 + (((t_sample)0.9) * (m_history_1 - mul_47831)));
			t_sample mix_47828 = mix_48456;
			bool index_ignore_155 = ((counter_47911 >= snare_array_dim) || (counter_47911 < 0));
			// samples snare_array channel 1;
			t_sample sample_snare_array_47922 = (index_ignore_155 ? 0 : m_snare_array_38.read(counter_47911, 0));
			t_sample index_snare_array_47923 = counter_47911;
			__m_latch_156 = ((sample_snare_array_47922 != 0) ? trigger_beat_47817 : __m_latch_156);
			t_sample latch_47918 = __m_latch_156;
			t_sample delta_47806 = __m_delta_157(latch_47918);
			t_sample abs_47851 = fabs(delta_47806);
			int gt_47850 = (abs_47851 > ((t_sample)0.5));
			int change_47849 = __m_change_158(gt_47850);
			int gt_47848 = (change_47849 > ((int)0));
			t_sample plusequals_47873 = __m_pluseq_159.post(safediv(13, samplerate), gt_47848, 0);
			t_sample clamp_47872 = ((plusequals_47873 <= ((int)0)) ? ((int)0) : ((plusequals_47873 >= ((int)1)) ? ((int)1) : plusequals_47873));
			t_sample sub_48460 = (clamp_47872 - ((int)0));
			t_sample scale_48457 = ((safepow((sub_48460 * ((t_sample)1)), (1 * ((t_sample)0.5))) * ((int)-1)) + ((int)1));
			t_sample mul_47876 = (scale_48457 * triangle_47870);
			t_sample plusequals_47858 = __m_pluseq_160.post(safediv(7, samplerate), gt_47848, 0);
			t_sample clamp_47856 = ((plusequals_47858 <= ((int)0)) ? ((int)0) : ((plusequals_47858 >= ((int)1)) ? ((int)1) : plusequals_47858));
			t_sample sub_48464 = (clamp_47856 - ((int)0));
			t_sample scale_48461 = ((safepow((sub_48464 * ((t_sample)1)), (1 * ((t_sample)0.5))) * ((t_sample)-0.5)) + ((t_sample)0.5));
			t_sample mul_47855 = (scale_48461 * sub_47852);
			t_sample plusequals_47866 = __m_pluseq_161.post(safediv(8, samplerate), gt_47848, 0);
			t_sample clamp_47862 = ((plusequals_47866 <= ((int)0)) ? ((int)0) : ((plusequals_47866 >= ((int)1)) ? ((int)1) : plusequals_47866));
			t_sample sub_48468 = (clamp_47862 - ((int)0));
			t_sample scale_48465 = ((safepow((sub_48468 * ((t_sample)1)), (1 * ((t_sample)0.5))) * ((t_sample)-0.7)) + ((t_sample)0.7));
			t_sample mul_47860 = (scale_48465 * mix_47854);
			t_sample plusequals_47867 = __m_pluseq_162.post(safediv(11, samplerate), gt_47848, 0);
			t_sample clamp_47864 = ((plusequals_47867 <= ((int)0)) ? ((int)0) : ((plusequals_47867 >= ((int)1)) ? ((int)1) : plusequals_47867));
			t_sample sub_48472 = (clamp_47864 - ((int)0));
			t_sample scale_48469 = ((safepow((sub_48472 * ((t_sample)1)), (1 * ((t_sample)0.5))) * ((int)-1)) + ((int)1));
			t_sample mul_47861 = (scale_48469 * triangle_47868);
			t_sample v_163 = (((mul_47861 + mul_47860) + mul_47855) + mul_47876);
			t_sample clamp_47859 = ((v_163 <= min_164) ? min_164 : ((v_163 >= ((int)1)) ? ((int)1) : v_163));
			t_sample out1 = ((clamp_47859 + mul_47893) + mix_47828);
			t_sample out2 = ((clamp_47859 + mul_47893) + mix_47828);
			t_sample history_47891_next_47982 = fixdenorm(mix_47892);
			t_sample history_47853_next_47983 = fixdenorm(mix_47854);
			t_sample history_47874_next_47984 = fixdenorm(mix_47875);
			t_sample history_47715_next_47985 = fixdenorm(wrap_47718);
			t_sample history_47744_next_47986 = fixdenorm(switch_47743);
			t_sample history_47827_next_47987 = fixdenorm(mix_47828);
			m_history_23 = history_47726_next_47729;
			m_history_6 = history_47891_next_47982;
			m_history_5 = history_47853_next_47983;
			m_history_4 = history_47874_next_47984;
			m_history_3 = history_47715_next_47985;
			m_history_2 = history_47744_next_47986;
			m_history_1 = history_47827_next_47987;
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
			(*(__out35++)) = out35;
			(*(__out36++)) = out36;
			(*(__out37++)) = out37;
			
		};
		return __exception;
		
	};
	inline void set_sw6(t_param _value) {
		m_sw_24 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw8(t_param _value) {
		m_sw_25 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw5(t_param _value) {
		m_sw_26 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_cv2(t_param _value) {
		m_cv_27 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_kick_array(void * _value) {
		m_kick_array_28.setbuffer(_value);
	};
	inline void set_sw3(t_param _value) {
		m_sw_37 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_snare_array(void * _value) {
		m_snare_array_38.setbuffer(_value);
	};
	inline void set_sw4(t_param _value) {
		m_sw_39 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_density_snare(t_param _value) {
		m_density_snare_40 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_41 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_mix(t_param _value) {
		m_mix_42 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_snare_patterns(void * _value) {
		m_snare_patterns_43.setbuffer(_value);
	};
	inline void set_hihat_patterns(void * _value) {
		m_hihat_patterns_44.setbuffer(_value);
	};
	inline void set_gatein1(t_param _value) {
		m_gatein_45 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_density_hihat(t_param _value) {
		m_density_hihat_46 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_hihat_hit_values(void * _value) {
		m_hihat_hit_values_47.setbuffer(_value);
	};
	inline void set_hihat_array(void * _value) {
		m_hihat_array_48.setbuffer(_value);
	};
	inline void set_sw7(t_param _value) {
		m_sw_49 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_swing(t_param _value) {
		m_swing_50 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_X(t_param _value) {
		m_X_51 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw2(t_param _value) {
		m_sw_52 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_snare_hit_values(void * _value) {
		m_snare_hit_values_53.setbuffer(_value);
	};
	inline void set_Y(t_param _value) {
		m_Y_54 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_bpm(t_param _value) {
		m_bpm_55 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_grid_matrix_noise(void * _value) {
		m_grid_matrix_noise_56.setbuffer(_value);
	};
	inline void set_noise_array(void * _value) {
		m_noise_array_57.setbuffer(_value);
	};
	
} State;


///
///	Configuration for the genlib API
///

/// Number of signal inputs and outputs

int gen_kernel_numins = 2;
int gen_kernel_numouts = 37;

int num_inputs() { return gen_kernel_numins; }
int num_outputs() { return gen_kernel_numouts; }
int num_params() { return 26; }

/// Assistive lables for the signal inputs and outputs

const char *gen_kernel_innames[] = { "in1", "in2" };
const char *gen_kernel_outnames[] = { "sound_l", "sound_r", "led1", "led2", "led3", "led4", "led5", "led6", "led7", "led8", "sn1", "sn2", "sn3", "sn4", "sn5", "sn6", "sn7", "sn8", "hi1", "hi2", "hi3", "hi4", "hi5", "hi6", "hi7", "hi8", "trigger_b", "step_value", "x_pos", "y_pos", "out31", "out32", "out33", "out34", "out35", "out36", "out37" };

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
		case 0: self->set_X(value); break;
		case 1: self->set_Y(value); break;
		case 2: self->set_bpm(value); break;
		case 3: self->set_cv2(value); break;
		case 4: self->set_density_hihat(value); break;
		case 5: self->set_density_snare(value); break;
		case 6: self->set_gatein1(value); break;
		case 7: self->set_grid_matrix_noise(ref); break;
		case 8: self->set_hihat_array(ref); break;
		case 9: self->set_hihat_hit_values(ref); break;
		case 10: self->set_hihat_patterns(ref); break;
		case 11: self->set_kick_array(ref); break;
		case 12: self->set_mix(value); break;
		case 13: self->set_noise_array(ref); break;
		case 14: self->set_snare_array(ref); break;
		case 15: self->set_snare_hit_values(ref); break;
		case 16: self->set_snare_patterns(ref); break;
		case 17: self->set_sw1(value); break;
		case 18: self->set_sw2(value); break;
		case 19: self->set_sw3(value); break;
		case 20: self->set_sw4(value); break;
		case 21: self->set_sw5(value); break;
		case 22: self->set_sw6(value); break;
		case 23: self->set_sw7(value); break;
		case 24: self->set_sw8(value); break;
		case 25: self->set_swing(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_X_51; break;
		case 1: *value = self->m_Y_54; break;
		case 2: *value = self->m_bpm_55; break;
		case 3: *value = self->m_cv_27; break;
		case 4: *value = self->m_density_hihat_46; break;
		case 5: *value = self->m_density_snare_40; break;
		case 6: *value = self->m_gatein_45; break;
		
		
		
		
		
		case 12: *value = self->m_mix_42; break;
		
		
		
		
		case 17: *value = self->m_sw_41; break;
		case 18: *value = self->m_sw_52; break;
		case 19: *value = self->m_sw_37; break;
		case 20: *value = self->m_sw_39; break;
		case 21: *value = self->m_sw_26; break;
		case 22: *value = self->m_sw_24; break;
		case 23: *value = self->m_sw_49; break;
		case 24: *value = self->m_sw_25; break;
		case 25: *value = self->m_swing_50; break;
		
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
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(26 * sizeof(ParamInfo));
	self->__commonstate.numparams = 26;
	// initialize parameter 0 ("m_X_51")
	pi = self->__commonstate.params + 0;
	pi->name = "X";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_X_51;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_Y_54")
	pi = self->__commonstate.params + 1;
	pi->name = "Y";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_Y_54;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_bpm_55")
	pi = self->__commonstate.params + 2;
	pi->name = "bpm";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_bpm_55;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_cv_27")
	pi = self->__commonstate.params + 3;
	pi->name = "cv2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_cv_27;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_density_hihat_46")
	pi = self->__commonstate.params + 4;
	pi->name = "density_hihat";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_density_hihat_46;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_density_snare_40")
	pi = self->__commonstate.params + 5;
	pi->name = "density_snare";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_density_snare_40;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_gatein_45")
	pi = self->__commonstate.params + 6;
	pi->name = "gatein1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_gatein_45;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 7 ("m_grid_matrix_noise_56")
	pi = self->__commonstate.params + 7;
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
	// initialize parameter 8 ("m_hihat_array_48")
	pi = self->__commonstate.params + 8;
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
	// initialize parameter 9 ("m_hihat_hit_values_47")
	pi = self->__commonstate.params + 9;
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
	// initialize parameter 10 ("m_hihat_patterns_44")
	pi = self->__commonstate.params + 10;
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
	// initialize parameter 11 ("m_kick_array_28")
	pi = self->__commonstate.params + 11;
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
	// initialize parameter 12 ("m_mix_42")
	pi = self->__commonstate.params + 12;
	pi->name = "mix";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_mix_42;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 13 ("m_noise_array_57")
	pi = self->__commonstate.params + 13;
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
	// initialize parameter 14 ("m_snare_array_38")
	pi = self->__commonstate.params + 14;
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
	// initialize parameter 15 ("m_snare_hit_values_53")
	pi = self->__commonstate.params + 15;
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
	// initialize parameter 16 ("m_snare_patterns_43")
	pi = self->__commonstate.params + 16;
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
	// initialize parameter 17 ("m_sw_41")
	pi = self->__commonstate.params + 17;
	pi->name = "sw1";
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
	// initialize parameter 18 ("m_sw_52")
	pi = self->__commonstate.params + 18;
	pi->name = "sw2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_52;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 19 ("m_sw_37")
	pi = self->__commonstate.params + 19;
	pi->name = "sw3";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_37;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 20 ("m_sw_39")
	pi = self->__commonstate.params + 20;
	pi->name = "sw4";
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
	// initialize parameter 21 ("m_sw_26")
	pi = self->__commonstate.params + 21;
	pi->name = "sw5";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_26;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 22 ("m_sw_24")
	pi = self->__commonstate.params + 22;
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
	// initialize parameter 23 ("m_sw_49")
	pi = self->__commonstate.params + 23;
	pi->name = "sw7";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_49;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 24 ("m_sw_25")
	pi = self->__commonstate.params + 24;
	pi->name = "sw8";
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
	// initialize parameter 25 ("m_swing_50")
	pi = self->__commonstate.params + 25;
	pi->name = "swing";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_swing_50;
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
