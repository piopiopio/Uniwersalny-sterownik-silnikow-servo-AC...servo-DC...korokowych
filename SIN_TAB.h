#ifndef __SIN_TAB_H
#define __SIN_TAB_H
#endif

#define SIN_TAB_quantity 6000
#define SIN_TAB_RESOLUTION 5000
//#define SIN_TAB_RESOLUTION 1022

const int SIN_TAB[SIN_TAB_quantity] =
{ 511, 512, 512, 513, 513, 514, 514, 515, 515, 516, 516, 517, 517, 518, 518,
		519, 520, 520, 521, 521, 522, 522, 523, 523, 524, 524, 525, 525, 526,
		527, 527, 528, 528, 529, 529, 530, 530, 531, 531, 532, 532, 533, 533,
		534, 535, 535, 536, 536, 537, 537, 538, 538, 539, 539, 540, 540, 541,
		541, 542, 543, 543, 544, 544, 545, 545, 546, 546, 547, 547, 548, 548,
		549, 549, 550, 551, 551, 552, 552, 553, 553, 554, 554, 555, 555, 556,
		556, 557, 557, 558, 559, 559, 560, 560, 561, 561, 562, 562, 563, 563,
		564, 564, 565, 565, 566, 567, 567, 568, 568, 569, 569, 570, 570, 571,
		571, 572, 572, 573, 573, 574, 575, 575, 576, 576, 577, 577, 578, 578,
		579, 579, 580, 580, 581, 581, 582, 582, 583, 584, 584, 585, 585, 586,
		586, 587, 587, 588, 588, 589, 589, 590, 590, 591, 591, 592, 593, 593,
		594, 594, 595, 595, 596, 596, 597, 597, 598, 598, 599, 599, 600, 600,
		601, 601, 602, 603, 603, 604, 604, 605, 605, 606, 606, 607, 607, 608,
		608, 609, 609, 610, 610, 611, 611, 612, 613, 613, 614, 614, 615, 615,
		616, 616, 617, 617, 618, 618, 619, 619, 620, 620, 621, 621, 622, 622,
		623, 624, 624, 625, 625, 626, 626, 627, 627, 628, 628, 629, 629, 630,
		630, 631, 631, 632, 632, 633, 633, 634, 634, 635, 635, 636, 637, 637,
		638, 638, 639, 639, 640, 640, 641, 641, 642, 642, 643, 643, 644, 644,
		645, 645, 646, 646, 647, 647, 648, 648, 649, 649, 650, 650, 651, 652,
		652, 653, 653, 654, 654, 655, 655, 656, 656, 657, 657, 658, 658, 659,
		659, 660, 660, 661, 661, 662, 662, 663, 663, 664, 664, 665, 665, 666,
		666, 667, 667, 668, 668, 669, 669, 670, 670, 671, 671, 672, 672, 673,
		673, 674, 674, 675, 676, 676, 677, 677, 678, 678, 679, 679, 680, 680,
		681, 681, 682, 682, 683, 683, 684, 684, 685, 685, 686, 686, 687, 687,
		688, 688, 689, 689, 690, 690, 691, 691, 692, 692, 693, 693, 694, 694,
		695, 695, 696, 696, 697, 697, 698, 698, 699, 699, 700, 700, 701, 701,
		702, 702, 703, 703, 704, 704, 705, 705, 706, 706, 707, 707, 708, 708,
		709, 709, 710, 710, 710, 711, 711, 712, 712, 713, 713, 714, 714, 715,
		715, 716, 716, 717, 717, 718, 718, 719, 719, 720, 720, 721, 721, 722,
		722, 723, 723, 724, 724, 725, 725, 726, 726, 727, 727, 728, 728, 729,
		729, 730, 730, 731, 731, 731, 732, 732, 733, 733, 734, 734, 735, 735,
		736, 736, 737, 737, 738, 738, 739, 739, 740, 740, 741, 741, 742, 742,
		743, 743, 743, 744, 744, 745, 745, 746, 746, 747, 747, 748, 748, 749,
		749, 750, 750, 751, 751, 752, 752, 752, 753, 753, 754, 754, 755, 755,
		756, 756, 757, 757, 758, 758, 759, 759, 760, 760, 760, 761, 761, 762,
		762, 763, 763, 764, 764, 765, 765, 766, 766, 767, 767, 767, 768, 768,
		769, 769, 770, 770, 771, 771, 772, 772, 773, 773, 773, 774, 774, 775,
		775, 776, 776, 777, 777, 778, 778, 778, 779, 779, 780, 780, 781, 781,
		782, 782, 783, 783, 783, 784, 784, 785, 785, 786, 786, 787, 787, 788,
		788, 788, 789, 789, 790, 790, 791, 791, 792, 792, 792, 793, 793, 794,
		794, 795, 795, 796, 796, 796, 797, 797, 798, 798, 799, 799, 800, 800,
		800, 801, 801, 802, 802, 803, 803, 804, 804, 804, 805, 805, 806, 806,
		807, 807, 807, 808, 808, 809, 809, 810, 810, 810, 811, 811, 812, 812,
		813, 813, 814, 814, 814, 815, 815, 816, 816, 817, 817, 817, 818, 818,
		819, 819, 820, 820, 820, 821, 821, 822, 822, 823, 823, 823, 824, 824,
		825, 825, 825, 826, 826, 827, 827, 828, 828, 828, 829, 829, 830, 830,
		830, 831, 831, 832, 832, 833, 833, 833, 834, 834, 835, 835, 835, 836,
		836, 837, 837, 838, 838, 838, 839, 839, 840, 840, 840, 841, 841, 842,
		842, 842, 843, 843, 844, 844, 844, 845, 845, 846, 846, 847, 847, 847,
		848, 848, 849, 849, 849, 850, 850, 851, 851, 851, 852, 852, 853, 853,
		853, 854, 854, 855, 855, 855, 856, 856, 856, 857, 857, 858, 858, 858,
		859, 859, 860, 860, 860, 861, 861, 862, 862, 862, 863, 863, 864, 864,
		864, 865, 865, 865, 866, 866, 867, 867, 867, 868, 868, 869, 869, 869,
		870, 870, 870, 871, 871, 872, 872, 872, 873, 873, 873, 874, 874, 875,
		875, 875, 876, 876, 876, 877, 877, 878, 878, 878, 879, 879, 879, 880,
		880, 881, 881, 881, 882, 882, 882, 883, 883, 884, 884, 884, 885, 885,
		885, 886, 886, 886, 887, 887, 888, 888, 888, 889, 889, 889, 890, 890,
		890, 891, 891, 891, 892, 892, 893, 893, 893, 894, 894, 894, 895, 895,
		895, 896, 896, 896, 897, 897, 897, 898, 898, 899, 899, 899, 900, 900,
		900, 901, 901, 901, 902, 902, 902, 903, 903, 903, 904, 904, 904, 905,
		905, 905, 906, 906, 906, 907, 907, 907, 908, 908, 908, 909, 909, 909,
		910, 910, 910, 911, 911, 911, 912, 912, 912, 913, 913, 913, 914, 914,
		914, 915, 915, 915, 916, 916, 916, 917, 917, 917, 918, 918, 918, 919,
		919, 919, 920, 920, 920, 921, 921, 921, 922, 922, 922, 923, 923, 923,
		923, 924, 924, 924, 925, 925, 925, 926, 926, 926, 927, 927, 927, 928,
		928, 928, 928, 929, 929, 929, 930, 930, 930, 931, 931, 931, 932, 932,
		932, 932, 933, 933, 933, 934, 934, 934, 935, 935, 935, 935, 936, 936,
		936, 937, 937, 937, 938, 938, 938, 938, 939, 939, 939, 940, 940, 940,
		940, 941, 941, 941, 942, 942, 942, 942, 943, 943, 943, 944, 944, 944,
		944, 945, 945, 945, 946, 946, 946, 946, 947, 947, 947, 948, 948, 948,
		948, 949, 949, 949, 949, 950, 950, 950, 951, 951, 951, 951, 952, 952,
		952, 952, 953, 953, 953, 954, 954, 954, 954, 955, 955, 955, 955, 956,
		956, 956, 956, 957, 957, 957, 957, 958, 958, 958, 959, 959, 959, 959,
		960, 960, 960, 960, 961, 961, 961, 961, 962, 962, 962, 962, 963, 963,
		963, 963, 964, 964, 964, 964, 965, 965, 965, 965, 966, 966, 966, 966,
		967, 967, 967, 967, 968, 968, 968, 968, 968, 969, 969, 969, 969, 970,
		970, 970, 970, 971, 971, 971, 971, 972, 972, 972, 972, 972, 973, 973,
		973, 973, 974, 974, 974, 974, 974, 975, 975, 975, 975, 976, 976, 976,
		976, 977, 977, 977, 977, 977, 978, 978, 978, 978, 978, 979, 979, 979,
		979, 980, 980, 980, 980, 980, 981, 981, 981, 981, 981, 982, 982, 982,
		982, 982, 983, 983, 983, 983, 984, 984, 984, 984, 984, 985, 985, 985,
		985, 985, 986, 986, 986, 986, 986, 987, 987, 987, 987, 987, 987, 988,
		988, 988, 988, 988, 989, 989, 989, 989, 989, 990, 990, 990, 990, 990,
		991, 991, 991, 991, 991, 991, 992, 992, 992, 992, 992, 993, 993, 993,
		993, 993, 993, 994, 994, 994, 994, 994, 994, 995, 995, 995, 995, 995,
		995, 996, 996, 996, 996, 996, 996, 997, 997, 997, 997, 997, 997, 998,
		998, 998, 998, 998, 998, 999, 999, 999, 999, 999, 999, 1000, 1000, 1000,
		1000, 1000, 1000, 1000, 1001, 1001, 1001, 1001, 1001, 1001, 1002, 1002,
		1002, 1002, 1002, 1002, 1002, 1003, 1003, 1003, 1003, 1003, 1003, 1003,
		1004, 1004, 1004, 1004, 1004, 1004, 1004, 1005, 1005, 1005, 1005, 1005,
		1005, 1005, 1006, 1006, 1006, 1006, 1006, 1006, 1006, 1006, 1007, 1007,
		1007, 1007, 1007, 1007, 1007, 1008, 1008, 1008, 1008, 1008, 1008, 1008,
		1008, 1008, 1009, 1009, 1009, 1009, 1009, 1009, 1009, 1009, 1010, 1010,
		1010, 1010, 1010, 1010, 1010, 1010, 1010, 1011, 1011, 1011, 1011, 1011,
		1011, 1011, 1011, 1011, 1012, 1012, 1012, 1012, 1012, 1012, 1012, 1012,
		1012, 1013, 1013, 1013, 1013, 1013, 1013, 1013, 1013, 1013, 1013, 1014,
		1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014, 1015, 1015,
		1015, 1015, 1015, 1015, 1015, 1015, 1015, 1015, 1015, 1016, 1016, 1016,
		1016, 1016, 1016, 1016, 1016, 1016, 1016, 1016, 1016, 1017, 1017, 1017,
		1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1018,
		1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018,
		1018, 1018, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019,
		1019, 1019, 1019, 1019, 1019, 1019, 1019, 1020, 1020, 1020, 1020, 1020,
		1020, 1020, 1020, 1020, 1020, 1020, 1020, 1020, 1020, 1020, 1020, 1020,
		1020, 1020, 1020, 1020, 1021, 1021, 1021, 1021, 1021, 1021, 1021, 1021,
		1021, 1021, 1021, 1021, 1021, 1021, 1021, 1021, 1021, 1021, 1021, 1021,
		1021, 1021, 1021, 1021, 1021, 1021, 1021, 1021, 1021, 1021, 1021, 1022,
		1022, 1022, 1022, 1022, 1022, 1022, 1022, 1022, 1022, 1022, 1022, 1022,
		1022, 1022, 1022, 1022, 1022, 1022, 1022, 1022, 1022, 1022, 1022, 1022,
		1022, 1022, 1022, 1022, 1022, 1022, 1022, 1022, 1022, 1022, 1022, 1022,
		1022, 1022, 1022, 1022, 1022, 1022, 1022, 1022, 1022, 1022, 1022, 1022,
		1022, 1022, 1022, 1022, 1022, 1022, 1022, 1022, 1022, 1022, 1022, 1022,
		1022, 1022, 1022, 1022, 1022, 1022, 1022, 1022, 1022, 1022, 1022, 1022,
		1022, 1022, 1022, 1022, 1022, 1022, 1022, 1022, 1022, 1022, 1022, 1022,
		1021, 1021, 1021, 1021, 1021, 1021, 1021, 1021, 1021, 1021, 1021, 1021,
		1021, 1021, 1021, 1021, 1021, 1021, 1021, 1021, 1021, 1021, 1021, 1021,
		1021, 1021, 1021, 1021, 1021, 1021, 1021, 1020, 1020, 1020, 1020, 1020,
		1020, 1020, 1020, 1020, 1020, 1020, 1020, 1020, 1020, 1020, 1020, 1020,
		1020, 1020, 1020, 1020, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019,
		1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1019, 1018, 1018, 1018,
		1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018, 1018,
		1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017, 1017,
		1017, 1017, 1016, 1016, 1016, 1016, 1016, 1016, 1016, 1016, 1016, 1016,
		1016, 1016, 1015, 1015, 1015, 1015, 1015, 1015, 1015, 1015, 1015, 1015,
		1015, 1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014, 1014,
		1013, 1013, 1013, 1013, 1013, 1013, 1013, 1013, 1013, 1013, 1012, 1012,
		1012, 1012, 1012, 1012, 1012, 1012, 1012, 1011, 1011, 1011, 1011, 1011,
		1011, 1011, 1011, 1011, 1010, 1010, 1010, 1010, 1010, 1010, 1010, 1010,
		1010, 1009, 1009, 1009, 1009, 1009, 1009, 1009, 1009, 1008, 1008, 1008,
		1008, 1008, 1008, 1008, 1008, 1008, 1007, 1007, 1007, 1007, 1007, 1007,
		1007, 1006, 1006, 1006, 1006, 1006, 1006, 1006, 1006, 1005, 1005, 1005,
		1005, 1005, 1005, 1005, 1004, 1004, 1004, 1004, 1004, 1004, 1004, 1003,
		1003, 1003, 1003, 1003, 1003, 1003, 1002, 1002, 1002, 1002, 1002, 1002,
		1002, 1001, 1001, 1001, 1001, 1001, 1001, 1000, 1000, 1000, 1000, 1000,
		1000, 1000, 999, 999, 999, 999, 999, 999, 998, 998, 998, 998, 998, 998,
		997, 997, 997, 997, 997, 997, 996, 996, 996, 996, 996, 996, 995, 995,
		995, 995, 995, 995, 994, 994, 994, 994, 994, 994, 993, 993, 993, 993,
		993, 993, 992, 992, 992, 992, 992, 991, 991, 991, 991, 991, 991, 990,
		990, 990, 990, 990, 989, 989, 989, 989, 989, 988, 988, 988, 988, 988,
		987, 987, 987, 987, 987, 987, 986, 986, 986, 986, 986, 985, 985, 985,
		985, 985, 984, 984, 984, 984, 984, 983, 983, 983, 983, 982, 982, 982,
		982, 982, 981, 981, 981, 981, 981, 980, 980, 980, 980, 980, 979, 979,
		979, 979, 978, 978, 978, 978, 978, 977, 977, 977, 977, 977, 976, 976,
		976, 976, 975, 975, 975, 975, 974, 974, 974, 974, 974, 973, 973, 973,
		973, 972, 972, 972, 972, 972, 971, 971, 971, 971, 970, 970, 970, 970,
		969, 969, 969, 969, 968, 968, 968, 968, 968, 967, 967, 967, 967, 966,
		966, 966, 966, 965, 965, 965, 965, 964, 964, 964, 964, 963, 963, 963,
		963, 962, 962, 962, 962, 961, 961, 961, 961, 960, 960, 960, 960, 959,
		959, 959, 959, 958, 958, 958, 957, 957, 957, 957, 956, 956, 956, 956,
		955, 955, 955, 955, 954, 954, 954, 954, 953, 953, 953, 952, 952, 952,
		952, 951, 951, 951, 951, 950, 950, 950, 949, 949, 949, 949, 948, 948,
		948, 948, 947, 947, 947, 946, 946, 946, 946, 945, 945, 945, 944, 944,
		944, 944, 943, 943, 943, 942, 942, 942, 942, 941, 941, 941, 940, 940,
		940, 940, 939, 939, 939, 938, 938, 938, 938, 937, 937, 937, 936, 936,
		936, 935, 935, 935, 935, 934, 934, 934, 933, 933, 933, 932, 932, 932,
		932, 931, 931, 931, 930, 930, 930, 929, 929, 929, 928, 928, 928, 928,
		927, 927, 927, 926, 926, 926, 925, 925, 925, 924, 924, 924, 923, 923,
		923, 923, 922, 922, 922, 921, 921, 921, 920, 920, 920, 919, 919, 919,
		918, 918, 918, 917, 917, 917, 916, 916, 916, 915, 915, 915, 914, 914,
		914, 913, 913, 913, 912, 912, 912, 911, 911, 911, 910, 910, 910, 909,
		909, 909, 908, 908, 908, 907, 907, 907, 906, 906, 906, 905, 905, 905,
		904, 904, 904, 903, 903, 903, 902, 902, 902, 901, 901, 901, 900, 900,
		900, 899, 899, 899, 898, 898, 897, 897, 897, 896, 896, 896, 895, 895,
		895, 894, 894, 894, 893, 893, 893, 892, 892, 891, 891, 891, 890, 890,
		890, 889, 889, 889, 888, 888, 888, 887, 887, 886, 886, 886, 885, 885,
		885, 884, 884, 884, 883, 883, 882, 882, 882, 881, 881, 881, 880, 880,
		879, 879, 879, 878, 878, 878, 877, 877, 876, 876, 876, 875, 875, 875,
		874, 874, 873, 873, 873, 872, 872, 872, 871, 871, 870, 870, 870, 869,
		869, 869, 868, 868, 867, 867, 867, 866, 866, 865, 865, 865, 864, 864,
		864, 863, 863, 862, 862, 862, 861, 861, 860, 860, 860, 859, 859, 858,
		858, 858, 857, 857, 856, 856, 856, 855, 855, 855, 854, 854, 853, 853,
		853, 852, 852, 851, 851, 851, 850, 850, 849, 849, 849, 848, 848, 847,
		847, 847, 846, 846, 845, 845, 844, 844, 844, 843, 843, 842, 842, 842,
		841, 841, 840, 840, 840, 839, 839, 838, 838, 838, 837, 837, 836, 836,
		835, 835, 835, 834, 834, 833, 833, 833, 832, 832, 831, 831, 830, 830,
		830, 829, 829, 828, 828, 828, 827, 827, 826, 826, 825, 825, 825, 824,
		824, 823, 823, 823, 822, 822, 821, 821, 820, 820, 820, 819, 819, 818,
		818, 817, 817, 817, 816, 816, 815, 815, 814, 814, 814, 813, 813, 812,
		812, 811, 811, 810, 810, 810, 809, 809, 808, 808, 807, 807, 807, 806,
		806, 805, 805, 804, 804, 804, 803, 803, 802, 802, 801, 801, 800, 800,
		800, 799, 799, 798, 798, 797, 797, 796, 796, 796, 795, 795, 794, 794,
		793, 793, 792, 792, 792, 791, 791, 790, 790, 789, 789, 788, 788, 788,
		787, 787, 786, 786, 785, 785, 784, 784, 783, 783, 783, 782, 782, 781,
		781, 780, 780, 779, 779, 778, 778, 778, 777, 777, 776, 776, 775, 775,
		774, 774, 773, 773, 773, 772, 772, 771, 771, 770, 770, 769, 769, 768,
		768, 767, 767, 767, 766, 766, 765, 765, 764, 764, 763, 763, 762, 762,
		761, 761, 760, 760, 760, 759, 759, 758, 758, 757, 757, 756, 756, 755,
		755, 754, 754, 753, 753, 752, 752, 752, 751, 751, 750, 750, 749, 749,
		748, 748, 747, 747, 746, 746, 745, 745, 744, 744, 743, 743, 743, 742,
		742, 741, 741, 740, 740, 739, 739, 738, 738, 737, 737, 736, 736, 735,
		735, 734, 734, 733, 733, 732, 732, 731, 731, 731, 730, 730, 729, 729,
		728, 728, 727, 727, 726, 726, 725, 725, 724, 724, 723, 723, 722, 722,
		721, 721, 720, 720, 719, 719, 718, 718, 717, 717, 716, 716, 715, 715,
		714, 714, 713, 713, 712, 712, 711, 711, 710, 710, 710, 709, 709, 708,
		708, 707, 707, 706, 706, 705, 705, 704, 704, 703, 703, 702, 702, 701,
		701, 700, 700, 699, 699, 698, 698, 697, 697, 696, 696, 695, 695, 694,
		694, 693, 693, 692, 692, 691, 691, 690, 690, 689, 689, 688, 688, 687,
		687, 686, 686, 685, 685, 684, 684, 683, 683, 682, 682, 681, 681, 680,
		680, 679, 679, 678, 678, 677, 677, 676, 676, 675, 674, 674, 673, 673,
		672, 672, 671, 671, 670, 670, 669, 669, 668, 668, 667, 667, 666, 666,
		665, 665, 664, 664, 663, 663, 662, 662, 661, 661, 660, 660, 659, 659,
		658, 658, 657, 657, 656, 656, 655, 655, 654, 654, 653, 653, 652, 652,
		651, 650, 650, 649, 649, 648, 648, 647, 647, 646, 646, 645, 645, 644,
		644, 643, 643, 642, 642, 641, 641, 640, 640, 639, 639, 638, 638, 637,
		637, 636, 635, 635, 634, 634, 633, 633, 632, 632, 631, 631, 630, 630,
		629, 629, 628, 628, 627, 627, 626, 626, 625, 625, 624, 624, 623, 622,
		622, 621, 621, 620, 620, 619, 619, 618, 618, 617, 617, 616, 616, 615,
		615, 614, 614, 613, 613, 612, 611, 611, 610, 610, 609, 609, 608, 608,
		607, 607, 606, 606, 605, 605, 604, 604, 603, 603, 602, 601, 601, 600,
		600, 599, 599, 598, 598, 597, 597, 596, 596, 595, 595, 594, 594, 593,
		593, 592, 591, 591, 590, 590, 589, 589, 588, 588, 587, 587, 586, 586,
		585, 585, 584, 584, 583, 582, 582, 581, 581, 580, 580, 579, 579, 578,
		578, 577, 577, 576, 576, 575, 575, 574, 573, 573, 572, 572, 571, 571,
		570, 570, 569, 569, 568, 568, 567, 567, 566, 565, 565, 564, 564, 563,
		563, 562, 562, 561, 561, 560, 560, 559, 559, 558, 557, 557, 556, 556,
		555, 555, 554, 554, 553, 553, 552, 552, 551, 551, 550, 549, 549, 548,
		548, 547, 547, 546, 546, 545, 545, 544, 544, 543, 543, 542, 541, 541,
		540, 540, 539, 539, 538, 538, 537, 537, 536, 536, 535, 535, 534, 533,
		533, 532, 532, 531, 531, 530, 530, 529, 529, 528, 528, 527, 527, 526,
		525, 525, 524, 524, 523, 523, 522, 522, 521, 521, 520, 520, 519, 518,
		518, 517, 517, 516, 516, 515, 515, 514, 514, 513, 513, 512, 512, 511,
		510, 510, 509, 509, 508, 508, 507, 507, 506, 506, 505, 505, 504, 504,
		503, 502, 502, 501, 501, 500, 500, 499, 499, 498, 498, 497, 497, 496,
		495, 495, 494, 494, 493, 493, 492, 492, 491, 491, 490, 490, 489, 489,
		488, 487, 487, 486, 486, 485, 485, 484, 484, 483, 483, 482, 482, 481,
		481, 480, 479, 479, 478, 478, 477, 477, 476, 476, 475, 475, 474, 474,
		473, 473, 472, 471, 471, 470, 470, 469, 469, 468, 468, 467, 467, 466,
		466, 465, 465, 464, 463, 463, 462, 462, 461, 461, 460, 460, 459, 459,
		458, 458, 457, 457, 456, 455, 455, 454, 454, 453, 453, 452, 452, 451,
		451, 450, 450, 449, 449, 448, 447, 447, 446, 446, 445, 445, 444, 444,
		443, 443, 442, 442, 441, 441, 440, 440, 439, 438, 438, 437, 437, 436,
		436, 435, 435, 434, 434, 433, 433, 432, 432, 431, 431, 430, 429, 429,
		428, 428, 427, 427, 426, 426, 425, 425, 424, 424, 423, 423, 422, 422,
		421, 421, 420, 419, 419, 418, 418, 417, 417, 416, 416, 415, 415, 414,
		414, 413, 413, 412, 412, 411, 411, 410, 409, 409, 408, 408, 407, 407,
		406, 406, 405, 405, 404, 404, 403, 403, 402, 402, 401, 401, 400, 400,
		399, 398, 398, 397, 397, 396, 396, 395, 395, 394, 394, 393, 393, 392,
		392, 391, 391, 390, 390, 389, 389, 388, 388, 387, 387, 386, 385, 385,
		384, 384, 383, 383, 382, 382, 381, 381, 380, 380, 379, 379, 378, 378,
		377, 377, 376, 376, 375, 375, 374, 374, 373, 373, 372, 372, 371, 370,
		370, 369, 369, 368, 368, 367, 367, 366, 366, 365, 365, 364, 364, 363,
		363, 362, 362, 361, 361, 360, 360, 359, 359, 358, 358, 357, 357, 356,
		356, 355, 355, 354, 354, 353, 353, 352, 352, 351, 351, 350, 350, 349,
		349, 348, 348, 347, 346, 346, 345, 345, 344, 344, 343, 343, 342, 342,
		341, 341, 340, 340, 339, 339, 338, 338, 337, 337, 336, 336, 335, 335,
		334, 334, 333, 333, 332, 332, 331, 331, 330, 330, 329, 329, 328, 328,
		327, 327, 326, 326, 325, 325, 324, 324, 323, 323, 322, 322, 321, 321,
		320, 320, 319, 319, 318, 318, 317, 317, 316, 316, 315, 315, 314, 314,
		313, 313, 312, 312, 312, 311, 311, 310, 310, 309, 309, 308, 308, 307,
		307, 306, 306, 305, 305, 304, 304, 303, 303, 302, 302, 301, 301, 300,
		300, 299, 299, 298, 298, 297, 297, 296, 296, 295, 295, 294, 294, 293,
		293, 292, 292, 291, 291, 291, 290, 290, 289, 289, 288, 288, 287, 287,
		286, 286, 285, 285, 284, 284, 283, 283, 282, 282, 281, 281, 280, 280,
		279, 279, 279, 278, 278, 277, 277, 276, 276, 275, 275, 274, 274, 273,
		273, 272, 272, 271, 271, 270, 270, 270, 269, 269, 268, 268, 267, 267,
		266, 266, 265, 265, 264, 264, 263, 263, 262, 262, 262, 261, 261, 260,
		260, 259, 259, 258, 258, 257, 257, 256, 256, 256, 255, 255, 254, 254,
		253, 253, 252, 252, 251, 251, 250, 250, 249, 249, 249, 248, 248, 247,
		247, 246, 246, 245, 245, 244, 244, 244, 243, 243, 242, 242, 241, 241,
		240, 240, 239, 239, 239, 238, 238, 237, 237, 236, 236, 235, 235, 234,
		234, 234, 233, 233, 232, 232, 231, 231, 230, 230, 230, 229, 229, 228,
		228, 227, 227, 226, 226, 226, 225, 225, 224, 224, 223, 223, 222, 222,
		222, 221, 221, 220, 220, 219, 219, 218, 218, 218, 217, 217, 216, 216,
		215, 215, 215, 214, 214, 213, 213, 212, 212, 212, 211, 211, 210, 210,
		209, 209, 208, 208, 208, 207, 207, 206, 206, 205, 205, 205, 204, 204,
		203, 203, 202, 202, 202, 201, 201, 200, 200, 199, 199, 199, 198, 198,
		197, 197, 197, 196, 196, 195, 195, 194, 194, 194, 193, 193, 192, 192,
		192, 191, 191, 190, 190, 189, 189, 189, 188, 188, 187, 187, 187, 186,
		186, 185, 185, 184, 184, 184, 183, 183, 182, 182, 182, 181, 181, 180,
		180, 180, 179, 179, 178, 178, 178, 177, 177, 176, 176, 175, 175, 175,
		174, 174, 173, 173, 173, 172, 172, 171, 171, 171, 170, 170, 169, 169,
		169, 168, 168, 167, 167, 167, 166, 166, 166, 165, 165, 164, 164, 164,
		163, 163, 162, 162, 162, 161, 161, 160, 160, 160, 159, 159, 158, 158,
		158, 157, 157, 157, 156, 156, 155, 155, 155, 154, 154, 153, 153, 153,
		152, 152, 152, 151, 151, 150, 150, 150, 149, 149, 149, 148, 148, 147,
		147, 147, 146, 146, 146, 145, 145, 144, 144, 144, 143, 143, 143, 142,
		142, 141, 141, 141, 140, 140, 140, 139, 139, 138, 138, 138, 137, 137,
		137, 136, 136, 136, 135, 135, 134, 134, 134, 133, 133, 133, 132, 132,
		132, 131, 131, 131, 130, 130, 129, 129, 129, 128, 128, 128, 127, 127,
		127, 126, 126, 126, 125, 125, 125, 124, 124, 123, 123, 123, 122, 122,
		122, 121, 121, 121, 120, 120, 120, 119, 119, 119, 118, 118, 118, 117,
		117, 117, 116, 116, 116, 115, 115, 115, 114, 114, 114, 113, 113, 113,
		112, 112, 112, 111, 111, 111, 110, 110, 110, 109, 109, 109, 108, 108,
		108, 107, 107, 107, 106, 106, 106, 105, 105, 105, 104, 104, 104, 103,
		103, 103, 102, 102, 102, 101, 101, 101, 100, 100, 100, 99, 99, 99, 99,
		98, 98, 98, 97, 97, 97, 96, 96, 96, 95, 95, 95, 94, 94, 94, 94, 93, 93,
		93, 92, 92, 92, 91, 91, 91, 90, 90, 90, 90, 89, 89, 89, 88, 88, 88, 87,
		87, 87, 87, 86, 86, 86, 85, 85, 85, 84, 84, 84, 84, 83, 83, 83, 82, 82,
		82, 82, 81, 81, 81, 80, 80, 80, 80, 79, 79, 79, 78, 78, 78, 78, 77, 77,
		77, 76, 76, 76, 76, 75, 75, 75, 74, 74, 74, 74, 73, 73, 73, 73, 72, 72,
		72, 71, 71, 71, 71, 70, 70, 70, 70, 69, 69, 69, 68, 68, 68, 68, 67, 67,
		67, 67, 66, 66, 66, 66, 65, 65, 65, 65, 64, 64, 64, 63, 63, 63, 63, 62,
		62, 62, 62, 61, 61, 61, 61, 60, 60, 60, 60, 59, 59, 59, 59, 58, 58, 58,
		58, 57, 57, 57, 57, 56, 56, 56, 56, 55, 55, 55, 55, 54, 54, 54, 54, 54,
		53, 53, 53, 53, 52, 52, 52, 52, 51, 51, 51, 51, 50, 50, 50, 50, 50, 49,
		49, 49, 49, 48, 48, 48, 48, 48, 47, 47, 47, 47, 46, 46, 46, 46, 45, 45,
		45, 45, 45, 44, 44, 44, 44, 44, 43, 43, 43, 43, 42, 42, 42, 42, 42, 41,
		41, 41, 41, 41, 40, 40, 40, 40, 40, 39, 39, 39, 39, 38, 38, 38, 38, 38,
		37, 37, 37, 37, 37, 36, 36, 36, 36, 36, 35, 35, 35, 35, 35, 35, 34, 34,
		34, 34, 34, 33, 33, 33, 33, 33, 32, 32, 32, 32, 32, 31, 31, 31, 31, 31,
		31, 30, 30, 30, 30, 30, 29, 29, 29, 29, 29, 29, 28, 28, 28, 28, 28, 28,
		27, 27, 27, 27, 27, 27, 26, 26, 26, 26, 26, 26, 25, 25, 25, 25, 25, 25,
		24, 24, 24, 24, 24, 24, 23, 23, 23, 23, 23, 23, 22, 22, 22, 22, 22, 22,
		22, 21, 21, 21, 21, 21, 21, 20, 20, 20, 20, 20, 20, 20, 19, 19, 19, 19,
		19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 17, 17, 17, 17, 17, 17, 17, 16,
		16, 16, 16, 16, 16, 16, 16, 15, 15, 15, 15, 15, 15, 15, 14, 14, 14, 14,
		14, 14, 14, 14, 14, 13, 13, 13, 13, 13, 13, 13, 13, 12, 12, 12, 12, 12,
		12, 12, 12, 12, 11, 11, 11, 11, 11, 11, 11, 11, 11, 10, 10, 10, 10, 10,
		10, 10, 10, 10, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 8, 8, 8, 8, 8, 8, 8, 8, 8,
		8, 8, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
		6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4, 4, 4, 4, 4, 4, 4, 4, 4,
		4, 4, 4, 4, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2,
		2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2,
		2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3,
		3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
		4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6,
		6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8,
		8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10,
		10, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 12, 12, 12, 12, 12, 12, 12,
		12, 12, 13, 13, 13, 13, 13, 13, 13, 13, 14, 14, 14, 14, 14, 14, 14, 14,
		14, 15, 15, 15, 15, 15, 15, 15, 16, 16, 16, 16, 16, 16, 16, 16, 17, 17,
		17, 17, 17, 17, 17, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19,
		19, 20, 20, 20, 20, 20, 20, 20, 21, 21, 21, 21, 21, 21, 22, 22, 22, 22,
		22, 22, 22, 23, 23, 23, 23, 23, 23, 24, 24, 24, 24, 24, 24, 25, 25, 25,
		25, 25, 25, 26, 26, 26, 26, 26, 26, 27, 27, 27, 27, 27, 27, 28, 28, 28,
		28, 28, 28, 29, 29, 29, 29, 29, 29, 30, 30, 30, 30, 30, 31, 31, 31, 31,
		31, 31, 32, 32, 32, 32, 32, 33, 33, 33, 33, 33, 34, 34, 34, 34, 34, 35,
		35, 35, 35, 35, 35, 36, 36, 36, 36, 36, 37, 37, 37, 37, 37, 38, 38, 38,
		38, 38, 39, 39, 39, 39, 40, 40, 40, 40, 40, 41, 41, 41, 41, 41, 42, 42,
		42, 42, 42, 43, 43, 43, 43, 44, 44, 44, 44, 44, 45, 45, 45, 45, 45, 46,
		46, 46, 46, 47, 47, 47, 47, 48, 48, 48, 48, 48, 49, 49, 49, 49, 50, 50,
		50, 50, 50, 51, 51, 51, 51, 52, 52, 52, 52, 53, 53, 53, 53, 54, 54, 54,
		54, 54, 55, 55, 55, 55, 56, 56, 56, 56, 57, 57, 57, 57, 58, 58, 58, 58,
		59, 59, 59, 59, 60, 60, 60, 60, 61, 61, 61, 61, 62, 62, 62, 62, 63, 63,
		63, 63, 64, 64, 64, 65, 65, 65, 65, 66, 66, 66, 66, 67, 67, 67, 67, 68,
		68, 68, 68, 69, 69, 69, 70, 70, 70, 70, 71, 71, 71, 71, 72, 72, 72, 73,
		73, 73, 73, 74, 74, 74, 74, 75, 75, 75, 76, 76, 76, 76, 77, 77, 77, 78,
		78, 78, 78, 79, 79, 79, 80, 80, 80, 80, 81, 81, 81, 82, 82, 82, 82, 83,
		83, 83, 84, 84, 84, 84, 85, 85, 85, 86, 86, 86, 87, 87, 87, 87, 88, 88,
		88, 89, 89, 89, 90, 90, 90, 90, 91, 91, 91, 92, 92, 92, 93, 93, 93, 94,
		94, 94, 94, 95, 95, 95, 96, 96, 96, 97, 97, 97, 98, 98, 98, 99, 99, 99,
		99, 100, 100, 100, 101, 101, 101, 102, 102, 102, 103, 103, 103, 104,
		104, 104, 105, 105, 105, 106, 106, 106, 107, 107, 107, 108, 108, 108,
		109, 109, 109, 110, 110, 110, 111, 111, 111, 112, 112, 112, 113, 113,
		113, 114, 114, 114, 115, 115, 115, 116, 116, 116, 117, 117, 117, 118,
		118, 118, 119, 119, 119, 120, 120, 120, 121, 121, 121, 122, 122, 122,
		123, 123, 123, 124, 124, 125, 125, 125, 126, 126, 126, 127, 127, 127,
		128, 128, 128, 129, 129, 129, 130, 130, 131, 131, 131, 132, 132, 132,
		133, 133, 133, 134, 134, 134, 135, 135, 136, 136, 136, 137, 137, 137,
		138, 138, 138, 139, 139, 140, 140, 140, 141, 141, 141, 142, 142, 143,
		143, 143, 144, 144, 144, 145, 145, 146, 146, 146, 147, 147, 147, 148,
		148, 149, 149, 149, 150, 150, 150, 151, 151, 152, 152, 152, 153, 153,
		153, 154, 154, 155, 155, 155, 156, 156, 157, 157, 157, 158, 158, 158,
		159, 159, 160, 160, 160, 161, 161, 162, 162, 162, 163, 163, 164, 164,
		164, 165, 165, 166, 166, 166, 167, 167, 167, 168, 168, 169, 169, 169,
		170, 170, 171, 171, 171, 172, 172, 173, 173, 173, 174, 174, 175, 175,
		175, 176, 176, 177, 177, 178, 178, 178, 179, 179, 180, 180, 180, 181,
		181, 182, 182, 182, 183, 183, 184, 184, 184, 185, 185, 186, 186, 187,
		187, 187, 188, 188, 189, 189, 189, 190, 190, 191, 191, 192, 192, 192,
		193, 193, 194, 194, 194, 195, 195, 196, 196, 197, 197, 197, 198, 198,
		199, 199, 199, 200, 200, 201, 201, 202, 202, 202, 203, 203, 204, 204,
		205, 205, 205, 206, 206, 207, 207, 208, 208, 208, 209, 209, 210, 210,
		211, 211, 212, 212, 212, 213, 213, 214, 214, 215, 215, 215, 216, 216,
		217, 217, 218, 218, 218, 219, 219, 220, 220, 221, 221, 222, 222, 222,
		223, 223, 224, 224, 225, 225, 226, 226, 226, 227, 227, 228, 228, 229,
		229, 230, 230, 230, 231, 231, 232, 232, 233, 233, 234, 234, 234, 235,
		235, 236, 236, 237, 237, 238, 238, 239, 239, 239, 240, 240, 241, 241,
		242, 242, 243, 243, 244, 244, 244, 245, 245, 246, 246, 247, 247, 248,
		248, 249, 249, 249, 250, 250, 251, 251, 252, 252, 253, 253, 254, 254,
		255, 255, 255, 256, 256, 257, 257, 258, 258, 259, 259, 260, 260, 261,
		261, 262, 262, 262, 263, 263, 264, 264, 265, 265, 266, 266, 267, 267,
		268, 268, 269, 269, 270, 270, 270, 271, 271, 272, 272, 273, 273, 274,
		274, 275, 275, 276, 276, 277, 277, 278, 278, 279, 279, 279, 280, 280,
		281, 281, 282, 282, 283, 283, 284, 284, 285, 285, 286, 286, 287, 287,
		288, 288, 289, 289, 290, 290, 291, 291, 291, 292, 292, 293, 293, 294,
		294, 295, 295, 296, 296, 297, 297, 298, 298, 299, 299, 300, 300, 301,
		301, 302, 302, 303, 303, 304, 304, 305, 305, 306, 306, 307, 307, 308,
		308, 309, 309, 310, 310, 311, 311, 312, 312, 312, 313, 313, 314, 314,
		315, 315, 316, 316, 317, 317, 318, 318, 319, 319, 320, 320, 321, 321,
		322, 322, 323, 323, 324, 324, 325, 325, 326, 326, 327, 327, 328, 328,
		329, 329, 330, 330, 331, 331, 332, 332, 333, 333, 334, 334, 335, 335,
		336, 336, 337, 337, 338, 338, 339, 339, 340, 340, 341, 341, 342, 342,
		343, 343, 344, 344, 345, 345, 346, 346, 347, 348, 348, 349, 349, 350,
		350, 351, 351, 352, 352, 353, 353, 354, 354, 355, 355, 356, 356, 357,
		357, 358, 358, 359, 359, 360, 360, 361, 361, 362, 362, 363, 363, 364,
		364, 365, 365, 366, 366, 367, 367, 368, 368, 369, 369, 370, 370, 371,
		372, 372, 373, 373, 374, 374, 375, 375, 376, 376, 377, 377, 378, 378,
		379, 379, 380, 380, 381, 381, 382, 382, 383, 383, 384, 384, 385, 385,
		386, 387, 387, 388, 388, 389, 389, 390, 390, 391, 391, 392, 392, 393,
		393, 394, 394, 395, 395, 396, 396, 397, 397, 398, 398, 399, 400, 400,
		401, 401, 402, 402, 403, 403, 404, 404, 405, 405, 406, 406, 407, 407,
		408, 408, 409, 409, 410, 411, 411, 412, 412, 413, 413, 414, 414, 415,
		415, 416, 416, 417, 417, 418, 418, 419, 419, 420, 421, 421, 422, 422,
		423, 423, 424, 424, 425, 425, 426, 426, 427, 427, 428, 428, 429, 429,
		430, 431, 431, 432, 432, 433, 433, 434, 434, 435, 435, 436, 436, 437,
		437, 438, 438, 439, 440, 440, 441, 441, 442, 442, 443, 443, 444, 444,
		445, 445, 446, 446, 447, 447, 448, 449, 449, 450, 450, 451, 451, 452,
		452, 453, 453, 454, 454, 455, 455, 456, 457, 457, 458, 458, 459, 459,
		460, 460, 461, 461, 462, 462, 463, 463, 464, 465, 465, 466, 466, 467,
		467, 468, 468, 469, 469, 470, 470, 471, 471, 472, 473, 473, 474, 474,
		475, 475, 476, 476, 477, 477, 478, 478, 479, 479, 480, 481, 481, 482,
		482, 483, 483, 484, 484, 485, 485, 486, 486, 487, 487, 488, 489, 489,
		490, 490, 491, 491, 492, 492, 493, 493, 494, 494, 495, 495, 496, 497,
		497, 498, 498, 499, 499, 500, 500, 501, 501, 502, 502, 503, 504, 504,
		505, 505, 506, 506, 507, 507, 508, 508, 509, 509, 510, 510 };

