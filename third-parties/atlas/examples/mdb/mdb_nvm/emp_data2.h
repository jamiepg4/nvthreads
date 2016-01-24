

typedef struct data {
	int id;
	char name[STR_MAX_LEN];
	char geo[STR_MAX_LEN];
} Data;

Data data0[100] = {
	{ 0,  "Glenna Petty",  "31.33239, -39.762"},
	{ 1,  "Ocean Figueroa",  "-54.00744, -155.18411"},
	{ 2,  "Melodie Patterson",  "36.50293, 90.99187"},
	{ 3,  "Sonia Grimes",  "79.07931, -46.35866"},
	{ 4,  "Noelle Cameron",  "38.16252, -174.79389"},
	{ 5,  "Jessamine Head",  "-23.763, -159.9067"},
	{ 6,  "Fatima Hull",  "39.00127, -51.75461"},
	{ 7,  "Joy Morin",  "-78.11505, -99.55869"},
	{ 8,  "Breanna Oneill",  "-41.05773, -107.84312"},
	{ 9,  "Sheila Welch",  "47.57943, 121.03991"},
	{ 10,  "Lee Hahn",  "11.74229, -145.17223"},
	{ 11,  "Alfreda Galloway",  "89.67874, -151.77318"},
	{ 12,  "Beatrice Mullen",  "14.59246, 71.62332"},
	{ 13,  "Germane Parker",  "-49.58013, 139.00896"},
	{ 14,  "Whilemina Stephens",  "-77.53019, -49.59412"},
	{ 15,  "Deanna Boyd",  "-70.90852, 157.04405"},
	{ 16,  "Brynn Camacho",  "-24.93687, -101.74087"},
	{ 17,  "Quynn Ray",  "15.55404, -166.60141"},
	{ 18,  "Uma Bradford",  "51.2985, 152.17766"},
	{ 19,  "Destiny Ellis",  "-0.35916, 57.42235"},
	{ 20,  "Erin Padilla",  "-73.39004, 44.50107"},
	{ 21,  "Stephanie Smith",  "63.93991, -27.60938"},
	{ 22,  "Adrienne Chaney",  "78.28629, -165.85265"},
	{ 23,  "Yolanda Rowe",  "-1.89208, 100.57337"},
	{ 24,  "Roanna Mccray",  "-62.35924, 124.5787"},
	{ 25,  "Judith Rodriquez",  "-67.14942, 27.71895"},
	{ 26,  "Nomlanga Hoover",  "79.00914, 70.17749"},
	{ 27,  "Melinda Greer",  "-6.05419, -38.54383"},
	{ 28,  "Quemby Frye",  "6.63732, 95.92181"},
	{ 29,  "Keelie Rowe",  "0.06766, -80.54485"},
	{ 30,  "Maile Watson",  "31.37567, 69.42634"},
	{ 31,  "Lacota Daniel",  "-65.64591, 93.90037"},
	{ 32,  "Beverly Gay",  "-7.74633, 162.29831"},
	{ 33,  "Jeanette Marks",  "76.94133, 97.60673"},
	{ 34,  "Camilla Ayala",  "-79.53933, 88.79033"},
	{ 35,  "Cathleen Kelly",  "-9.78805, 60.05649"},
	{ 36,  "Naomi Lawrence",  "-58.31701, -137.50967"},
	{ 37,  "Karleigh Noble",  "25.03974, 151.90862"},
	{ 38,  "Flavia Bennett",  "54.56338, -137.18576"},
	{ 39,  "Heather Warren",  "48.66622, 56.37078"},
	{ 40,  "Willow Smith",  "28.63127, -175.18865"},
	{ 41,  "Judith Lopez",  "0.30308, -119.1183"},
	{ 42,  "Shana Meadows",  "-31.0138, 45.44438"},
	{ 43,  "Melodie Whitaker",  "11.65479, -81.4132"},
	{ 44,  "Heidi Hinton",  "47.03966, 3.03202"},
	{ 45,  "Lara Holmes",  "85.09282, -143.97064"},
	{ 46,  "Emi Fleming",  "49.8749, 14.75224"},
	{ 47,  "Mary Cantu",  "-36.66698, 19.69133"},
	{ 48,  "Kalia Beck",  "33.40227, 178.41585"},
	{ 49,  "Iona Barrera",  "-53.68309, -134.01737"},
	{ 50,  "Mariam Cortez",  "15.15909, 179.00293"},
	{ 51,  "Charde Gibbs",  "-35.5926, -60.45018"},
	{ 52,  "Karyn Hamilton",  "-19.23763, 68.54378"},
	{ 53,  "Linda Nielsen",  "-39.89117, -29.59132"},
	{ 54,  "Maggie Christensen",  "53.22089, 163.83084"},
	{ 55,  "Shellie Moses",  "-3.16146, 52.51361"},
	{ 56,  "Morgan Donaldson",  "42.22906, -57.17896"},
	{ 57,  "Hannah Townsend",  "11.3665, 34.12635"},
	{ 58,  "Kitra Ward",  "-77.10376, -52.69687"},
	{ 59,  "Giselle Byers",  "-32.25971, 9.77058"},
	{ 60,  "Naomi Atkinson",  "-30.24487, -114.30195"},
	{ 61,  "Maite Norton",  "6.3421, -170.56565"},
	{ 62,  "Cameran Morse",  "-37.44338, -52.15824"},
	{ 63,  "Jenna Mckee",  "-11.95456, 162.92487"},
	{ 64,  "Mona Everett",  "46.57263, -91.62054"},
	{ 65,  "Mari Kane",  "-71.96624, -8.07684"},
	{ 66,  "Lynn James",  "-84.05556, 173.16505"},
	{ 67,  "Teegan Buchanan",  "-74.4845, 46.58298"},
	{ 68,  "Reagan Vance",  "78.67355, 49.66509"},
	{ 69,  "Lesley Ford",  "-13.14098, -56.19398"},
	{ 70,  "Tasha Kline",  "60.17301, -40.10656"},
	{ 71,  "Morgan Underwood",  "10.07917, 2.49402"},
	{ 72,  "Whoopi Mosley",  "-64.43601, 99.0756"},
	{ 73,  "Avye Potter",  "-21.62813, 162.94604"},
	{ 74,  "Martina Lindsay",  "-52.185, -83.82661"},
	{ 75,  "Sharon Holland",  "4.43247, -106.61948"},
	{ 76,  "Nicole Sexton",  "-42.89126, -139.61042"},
	{ 77,  "Diana Adams",  "-65.19774, 39.62764"},
	{ 78,  "Maya Knowles",  "-60.90841, -87.83126"},
	{ 79,  "Harriet Lindsey",  "27.00374, 119.14635"},
	{ 80,  "Melyssa Clark",  "-46.02485, 77.46919"},
	{ 81,  "Candace Velazquez",  "-18.90198, 61.17607"},
	{ 82,  "Kevyn Finch",  "-36.60242, 100.05702"},
	{ 83,  "Tana Schmidt",  "-67.84285, -121.34034"},
	{ 84,  "Bo Holman",  "17.20515, -109.87143"},
	{ 85,  "Quincy Mills",  "-27.90103, 14.43297"},
	{ 86,  "Ciara Kelley",  "8.47292, 55.61365"},
	{ 87,  "Brynne Vaughn",  "49.77884, 176.87114"},
	{ 88,  "Hedwig Lyons",  "-86.16911, -144.39201"},
	{ 89,  "Phoebe Sosa",  "-16.01083, 38.23703"},
	{ 90,  "Martina Hudson",  "-17.0434, 64.7468"},
	{ 91,  "Fatima Sears",  "-18.05699, 21.85042"},
	{ 92,  "Tanya Meadows",  "-69.82319, 178.77948"},
	{ 93,  "Briar Scott",  "28.35018, -56.51847"},
	{ 94,  "Giselle Solis",  "34.97834, -145.42106"},
	{ 95,  "Ocean Underwood",  "18.57749, 147.40661"},
	{ 96,  "Cameran Cummings",  "4.07598, 85.34583"},
	{ 97,  "Lee Reid",  "62.43505, -151.47973"},
	{ 98,  "Minerva Fox",  "85.89626, 75.09899"},
	{ 99,  "Leslie Warren",  "50.58985, -105.31756"}
};

Data data1[100] = {
	{ 0,  "Florence Hess",  "6.68824, 147.44607"},
	{ 1,  "Cherokee Reyes",  "63.85568, -109.01263"},
	{ 2,  "Felicia Calderon",  "-52.696, -133.47325"},
	{ 3,  "Oprah Wong",  "-24.49788, -59.99538"},
	{ 4,  "Celeste Lloyd",  "38.4553, 93.60862"},
	{ 5,  "Winifred Burgess",  "-56.00995, 171.19224"},
	{ 6,  "Quinn Patton",  "13.6218, 43.51446"},
	{ 7,  "Karen Mills",  "-35.5145, -30.91055"},
	{ 8,  "Yeo Peterson",  "21.89731, -119.93986"},
	{ 9,  "Celeste Ross",  "66.97577, 30.58316"},
	{ 10,  "Cynthia Butler",  "-21.1743, -68.35355"},
	{ 11,  "Whoopi Vasquez",  "-36.79103, 106.2526"},
	{ 12,  "Dacey Huff",  "-20.51723, -152.03126"},
	{ 13,  "Alika Barnett",  "-47.48678, -105.50872"},
	{ 14,  "Leila Ochoa",  "-67.96398, 155.2638"},
	{ 15,  "Kylan Park",  "48.55804, 3.89521"},
	{ 16,  "Justine Salinas",  "-3.82351, -31.93828"},
	{ 17,  "Kelsie French",  "53.88923, -21.82174"},
	{ 18,  "Quemby Hodge",  "12.83179, -147.3398"},
	{ 19,  "Galena Bird",  "51.08077, -107.38801"},
	{ 20,  "Hadassah Tran",  "13.71869, 60.22179"},
	{ 21,  "Hayfa Howe",  "45.60591, -42.81215"},
	{ 22,  "Alana Horton",  "65.94061, 128.38373"},
	{ 23,  "Dana Dennis",  "28.67288, -99.77098"},
	{ 24,  "Kai Walters",  "-71.09702, 173.0029"},
	{ 25,  "Tanya Molina",  "-89.59446, 101.12815"},
	{ 26,  "Echo Obrien",  "5.94169, 43.97054"},
	{ 27,  "Jacqueline Bird",  "64.65718, 84.10224"},
	{ 28,  "Ginger Moss",  "86.51252, -169.10758"},
	{ 29,  "Hayfa Yates",  "8.40545, 152.45842"},
	{ 30,  "Carolyn Mcconnell",  "-70.91161, 126.03045"},
	{ 31,  "Morgan Chapman",  "55.0011, 91.9597"},
	{ 32,  "Doris Goodman",  "66.87878, 103.84359"},
	{ 33,  "Ginger Perkins",  "-74.23044, -112.10938"},
	{ 34,  "Sopoline Johns",  "-85.37969, -154.17319"},
	{ 35,  "Ria Finley",  "-42.12142, 31.46672"},
	{ 36,  "Hilary Jarvis",  "-22.5788, -79.14046"},
	{ 37,  "Rylee Freeman",  "-27.10231, 43.88287"},
	{ 38,  "Briar Mccray",  "3.22906, -132.71615"},
	{ 39,  "Erin Frost",  "29.45609, 153.50664"},
	{ 40,  "Hannah Shaw",  "82.29608, -114.63655"},
	{ 41,  "Jane Jones",  "-82.23895, 72.80054"},
	{ 42,  "Carissa Jacobs",  "27.41007, -159.04466"},
	{ 43,  "Kalia Cotton",  "-65.73572, -33.58014"},
	{ 44,  "Dominique Vazquez",  "62.73014, -67.88902"},
	{ 45,  "Carol Sosa",  "10.00333, 128.82432"},
	{ 46,  "Ruby Mcleod",  "-47.32955, -90.19953"},
	{ 47,  "Xandra Baxter",  "77.22137, -29.81496"},
	{ 48,  "Isabelle Kent",  "75.7866, -114.32717"},
	{ 49,  "Whitney Justice",  "-76.97817, 146.57972"},
	{ 50,  "Noelani Molina",  "-22.88389, -70.93155"},
	{ 51,  "Callie Spence",  "-84.12151, -54.2343"},
	{ 52,  "Karleigh Franco",  "-45.68323, -55.88037"},
	{ 53,  "Florence Rutledge",  "-62.89522, -54.2233"},
	{ 54,  "Tana Carney",  "25.93199, -151.01409"},
	{ 55,  "Shelley Barton",  "-80.99367, -21.95451"},
	{ 56,  "Alika May",  "-54.16509, 120.07646"},
	{ 57,  "Hyacinth Mays",  "-9.78372, 169.4265"},
	{ 58,  "Hayfa Knapp",  "57.81244, -9.10749"},
	{ 59,  "Whilemina Powell",  "69.81618, -10.83655"},
	{ 60,  "Britanney Herrera",  "8.08974, -112.87008"},
	{ 61,  "Mollie Dudley",  "-28.94583, 117.2146"},
	{ 62,  "Cynthia Lowe",  "-39.2158, 61.73686"},
	{ 63,  "Marah Shepard",  "-63.00197, 28.83565"},
	{ 64,  "Nadine Barton",  "-16.05191, 164.72244"},
	{ 65,  "Hayfa Beck",  "-52.94138, 148.32605"},
	{ 66,  "Iona Barlow",  "26.45119, 53.75667"},
	{ 67,  "Natalie Lindsay",  "9.7127, 56.02567"},
	{ 68,  "Serina Duffy",  "-89.13744, 44.85256"},
	{ 69,  "Madeson Goff",  "33.2867, -153.24295"},
	{ 70,  "April Ferrell",  "17.64014, -55.10499"},
	{ 71,  "Gwendolyn Aguirre",  "21.93269, -6.16827"},
	{ 72,  "Catherine Bishop",  "-14.17017, 120.05325"},
	{ 73,  "April Weber",  "-19.69893, 99.19175"},
	{ 74,  "Jamalia Blackwell",  "38.75979, 8.51953"},
	{ 75,  "Savannah Ware",  "-68.69172, -35.87534"},
	{ 76,  "Illana Powell",  "-87.08946, -83.90569"},
	{ 77,  "Tamara Ellis",  "-43.18374, -79.91253"},
	{ 78,  "Aurora Trevino",  "60.9772, 116.80238"},
	{ 79,  "Sandra Little",  "-16.51584, -159.02527"},
	{ 80,  "Keiko Nixon",  "-57.51177, -100.19166"},
	{ 81,  "Lillith Watts",  "55.14356, 65.87283"},
	{ 82,  "Shelly Collins",  "-33.00332, 18.71427"},
	{ 83,  "Amity Riddle",  "42.07744, 35.91706"},
	{ 84,  "Rebekah Orr",  "58.85595, -142.60345"},
	{ 85,  "Chastity Mcconnell",  "34.98379, -67.31934"},
	{ 86,  "Frances Rice",  "-62.32814, -167.35336"},
	{ 87,  "Shana Velez",  "77.84541, -116.954"},
	{ 88,  "Cheyenne Holloway",  "66.70173, -121.67824"},
	{ 89,  "Nola Mason",  "3.94117, -47.88015"},
	{ 90,  "Regan Gallagher",  "-75.20901, -64.98538"},
	{ 91,  "Indigo Horton",  "-25.66751, 137.51229"},
	{ 92,  "Orla Scott",  "55.27559, -19.61301"},
	{ 93,  "Stephanie Mills",  "45.0477, -26.90544"},
	{ 94,  "Melodie Burke",  "8.8217, -61.02206"},
	{ 95,  "Athena Berger",  "-82.11028, -68.46375"},
	{ 96,  "Alika Norris",  "-9.98801, 145.4663"},
	{ 97,  "Sonia Chapman",  "-10.79239, -91.93899"},
	{ 98,  "Halla Baker",  "84.63455, 168.50964"},
	{ 99,  "Kristen Boyer",  "7.54849, 154.87839"}
};

Data data2[100] = {
	{ 0,  "Alma Hooper",  "24.42863, -85.16362"},
	{ 1,  "Shelley White",  "-60.51545, -107.58"},
	{ 2,  "Shay Dorsey",  "27.01255, -40.64997"},
	{ 3,  "Yeo Todd",  "-16.55222, -74.95069"},
	{ 4,  "Olivia Valenzuela",  "37.66273, 5.27436"},
	{ 5,  "Hollee Rogers",  "-17.45297, -53.46689"},
	{ 6,  "Petra Gutierrez",  "-2.11811, -151.99368"},
	{ 7,  "Belle Wyatt",  "28.09194, 167.82871"},
	{ 8,  "Quincy Matthews",  "83.45791, -25.15951"},
	{ 9,  "Guinevere Blackwell",  "-61.85033, -114.89204"},
	{ 10,  "Callie Huff",  "-3.26209, 72.14144"},
	{ 11,  "Uma Chambers",  "62.09338, -157.97942"},
	{ 12,  "Athena Wolf",  "72.91449, -20.90687"},
	{ 13,  "Barbara Holt",  "52.46244, 42.48419"},
	{ 14,  "Carissa Camacho",  "-49.73613, 7.60115"},
	{ 15,  "Regina Lyons",  "-43.40128, -152.96835"},
	{ 16,  "Angelica Fowler",  "8.41618, 167.50458"},
	{ 17,  "Jessamine Nielsen",  "5.16936, 52.30574"},
	{ 18,  "Minerva Levine",  "84.46783, -27.2309"},
	{ 19,  "Kevyn Butler",  "-44.14952, -126.24217"},
	{ 20,  "Josephine Montgomery",  "80.90143, -151.84146"},
	{ 21,  "Jaquelyn Riddle",  "55.29424, 160.47122"},
	{ 22,  "Guinevere Pacheco",  "22.18446, 70.95975"},
	{ 23,  "Elizabeth Mcguire",  "78.29543, 2.30007"},
	{ 24,  "Delilah Herman",  "45.95268, -174.10805"},
	{ 25,  "Jessica Garrison",  "-9.38523, -55.04782"},
	{ 26,  "Chantale Solomon",  "-67.99144, -44.50973"},
	{ 27,  "Felicia Duncan",  "-69.67849, -6.05903"},
	{ 28,  "Rinah Nielsen",  "26.15707, -176.57282"},
	{ 29,  "Selma Brock",  "-7.83975, 120.65671"},
	{ 30,  "Fatima Larsen",  "12.16099, -53.13378"},
	{ 31,  "Kelsey Morse",  "-51.49019, 13.25405"},
	{ 32,  "Jeanette Mays",  "-72.32945, -89.80153"},
	{ 33,  "Isabella Perry",  "57.23569, 71.33933"},
	{ 34,  "Olympia Roman",  "81.57877, 81.32188"},
	{ 35,  "Latifah Woodard",  "-42.62472, 80.56366"},
	{ 36,  "Willow Maldonado",  "69.7767, 167.83245"},
	{ 37,  "Alexa Horne",  "-87.18489, -22.9849"},
	{ 38,  "Dakota Holcomb",  "-56.49522, -66.71642"},
	{ 39,  "Sharon Fowler",  "84.43514, 100.19838"},
	{ 40,  "Iona Shepherd",  "-83.18143, 118.88373"},
	{ 41,  "Ora Santos",  "88.34595, 92.89623"},
	{ 42,  "Vanna Boyle",  "82.5344, 101.74291"},
	{ 43,  "Amaya Mathews",  "63.08067, 77.11837"},
	{ 44,  "Jacqueline Bolton",  "-78.11758, -159.11131"},
	{ 45,  "Mariko Livingston",  "65.44527, -161.23362"},
	{ 46,  "Kellie Williamson",  "40.31036, 148.13872"},
	{ 47,  "Bethany Lee",  "-10.91641, -88.35344"},
	{ 48,  "Irene Herrera",  "-44.46365, -94.81938"},
	{ 49,  "Rhea Frost",  "76.30026, 102.48822"},
	{ 50,  "Kalia Freeman",  "-43.6212, 36.25685"},
	{ 51,  "Meghan Mueller",  "-75.54384, -71.20842"},
	{ 52,  "Sharon Brown",  "1.547, 65.80208"},
	{ 53,  "Marcia Nielsen",  "-79.61287, -79.93884"},
	{ 54,  "Lois Jackson",  "23.72308, 32.07537"},
	{ 55,  "Winter Ware",  "-84.7596, 155.88692"},
	{ 56,  "Hadley Hodge",  "-80.60142, -74.63065"},
	{ 57,  "Shafira Duffy",  "14.96952, -81.13883"},
	{ 58,  "McKenzie Cooper",  "51.24059, 178.32225"},
	{ 59,  "Alika Kirby",  "-63.41551, -80.26279"},
	{ 60,  "Elaine Ortega",  "-28.04612, -36.70896"},
	{ 61,  "Gwendolyn Watkins",  "-10.24166, -52.57518"},
	{ 62,  "Tatiana Whitaker",  "85.15082, 165.16684"},
	{ 63,  "Amethyst Glass",  "15.18151, -124.30888"},
	{ 64,  "Gwendolyn Burks",  "-45.23291, -107.97367"},
	{ 65,  "September Gibbs",  "-66.85107, 19.71149"},
	{ 66,  "Cameran Murray",  "18.07511, -115.6099"},
	{ 67,  "Maia Morin",  "44.83842, 10.8285"},
	{ 68,  "Sarah Rutledge",  "-39.93981, 3.40218"},
	{ 69,  "Bethany England",  "-89.57428, 130.38782"},
	{ 70,  "Gay Lowery",  "-45.70848, -65.36953"},
	{ 71,  "Leila Pollard",  "3.5838, -37.31843"},
	{ 72,  "Lydia Velazquez",  "-30.94026, 131.51424"},
	{ 73,  "Clare Blankenship",  "-19.04404, -20.15776"},
	{ 74,  "Kathleen Holden",  "-81.10347, -172.37041"},
	{ 75,  "Abra Gardner",  "-28.075, -112.16359"},
	{ 76,  "Hiroko Carlson",  "-82.6569, 154.54851"},
	{ 77,  "Sloane Wilkinson",  "86.48065, 84.6781"},
	{ 78,  "Karina Hodge",  "-5.95631, 173.67654"},
	{ 79,  "Lunea Dale",  "58.66229, -167.45249"},
	{ 80,  "Lydia Morgan",  "16.28153, 149.13716"},
	{ 81,  "Basia Fulton",  "-23.94568, -98.81814"},
	{ 82,  "Scarlet Nguyen",  "-79.06861, -125.94148"},
	{ 83,  "Nora Roman",  "7.03255, 7.4047"},
	{ 84,  "Maya Mcbride",  "6.21714, -92.80687"},
	{ 85,  "Hayfa Gibson",  "45.50638, 143.41297"},
	{ 86,  "Dawn Salazar",  "8.48384, 21.19856"},
	{ 87,  "Maya Nolan",  "17.83402, -57.89372"},
	{ 88,  "Meghan Richardson",  "22.41177, 170.53814"},
	{ 89,  "TaShya Eaton",  "79.54529, 170.2806"},
	{ 90,  "Paula Best",  "23.14086, 72.81321"},
	{ 91,  "Kylee Guzman",  "-40.59626, 3.26711"},
	{ 92,  "Jade Wilkerson",  "26.13172, 10.33116"},
	{ 93,  "Kerry Moss",  "71.08708, 172.43289"},
	{ 94,  "Hadassah Riley",  "-73.89459, -89.86911"},
	{ 95,  "Kerry Lancaster",  "62.95246, -30.76996"},
	{ 96,  "Dorothy Sexton",  "-67.62627, -69.51987"},
	{ 97,  "Odessa Mcdonald",  "-6.69604, 106.05812"},
	{ 98,  "Florence Wolfe",  "-4.83962, 90.43241"},
	{ 99,  "Leilani Diaz",  "-15.626, -151.96052"}
};
