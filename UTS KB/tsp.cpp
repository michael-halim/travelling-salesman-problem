#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
using namespace std;

class Kota {
private:
	string nama_;
	int x_, y_;
public:
	Kota() {
		x_ = 0; y_ = 0;
	}
	void setNama(string nama) {
		nama_ = nama;
	}
	void setX(int x) {
		x_ = x;
	}
	void setY(int y) {
		y_ = y;
	}
	string getNama() {
		return nama_;
	}
	int getX() {
		return x_;
	}
	int getY() {
		return y_;
	}
};

int main() {
	srand(time(NULL));
	// input
	ifstream inputkota;
	inputkota.open("kota.txt");

	//Mendata kota
	int max_kota;
	inputkota >> max_kota;
	int jumlah_semut;
	inputkota >> jumlah_semut;
	int batas_loop;
	inputkota >> batas_loop;
	float pangkat_alpha;
	inputkota >> pangkat_alpha;
	float pangkat_beta;
	inputkota >> pangkat_beta;
	float evaporate_rate;
	inputkota >> evaporate_rate;
	Kota* titik_kota = new Kota[max_kota]; // jumlah array = [maxkota]

	string nama; int x, y;
	getline(inputkota, nama);
	getline(inputkota, nama);
	for (int i = 0; i < max_kota; i++) {
		getline(inputkota, nama);
		titik_kota[i].setNama(nama);
		inputkota >> x;
		titik_kota[i].setX(x);
		inputkota >> y;
		titik_kota[i].setY(y);
		getline(inputkota, nama);
		getline(inputkota, nama);
	}
	inputkota.close();

	// EDIT CONFIG
	int menu;
	do {
		cout << "Menu = " << endl;
		cout << "1. Input kota" << endl;
		cout << "2. Edit kota" << endl;
		cout << "3. Delete kota" << endl;
		cout << "4. Edit jumlah semut" << endl;
		cout << "5. Edit batas loop" << endl;
		cout << "6. Edit pangkat alpha" << endl;
		cout << "7. Edit pangkat beta" << endl;
		cout << "8. Edit evaporate rate" << endl;
		cout << "9. Display kota" << endl;
		cout << "10. Display Detail" << endl;
		cout << "0. RUNNNNN!!!" << endl;
		cout << "Choice = ";
		cin >> menu;
		system("cls");
		if (menu == 1) {
			string nama_kotabaru;
			int x_kotabaru, y_kotabaru;
			cin.ignore();
			cout << "Nama Kota Baru = "; getline(cin, nama_kotabaru);
			cout << "X Kota Baru = "; cin >> x_kotabaru;
			cout << "Y Kota Baru = "; cin >> y_kotabaru;

			Kota* temp = new Kota[max_kota];
			for (int i = 0; i < max_kota; i++) {
				temp[i] = titik_kota[i];
			}
			delete[] titik_kota;
			titik_kota = new Kota[max_kota + 1];
			for (int i = 0; i < max_kota; i++) {
				titik_kota[i] = temp[i];
			}

			titik_kota[max_kota].setNama(nama_kotabaru);
			titik_kota[max_kota].setX(x_kotabaru);
			titik_kota[max_kota].setY(y_kotabaru);
			max_kota++;
		}
		else if (menu == 2) {
			// display kota
			for (int i = 0; i < max_kota; i++) {
				cout << titik_kota[i].getNama() << endl;
				cout << titik_kota[i].getX() << " " << titik_kota[i].getY() << endl << endl;
			}
			cout << endl;

			string nama_kotaedit;
			int x_kotaedit, y_kotaedit;
			cin.ignore();
			cout << "Nama Kota yang ingin di edit = "; getline(cin, nama_kotaedit);

			bool ketemu = false;
			for (int i = 0; i < max_kota; i++) {
				if (titik_kota[i].getNama() == nama_kotaedit) {
					ketemu = true;
					do {
						char gantinama;
						cout << "Ingin mengganti nama kota? (y/n) = "; cin >> gantinama;
						if (gantinama == 'y' || gantinama == 'n') {
							if (gantinama == 'y') {
								cin.ignore();
								cout << "Edit Nama Kota = "; getline(cin, nama_kotaedit);
								titik_kota[i].setNama(nama_kotaedit);
							}
							cout << "Edit X Kota = "; cin >> x_kotaedit;
							cout << "Edit Y Kota = "; cin >> y_kotaedit;
							titik_kota[i].setX(x_kotaedit);
							titik_kota[i].setY(y_kotaedit);
							break;
						}
						else {
							cout << "Salah input perintah!" << endl << endl;
						}
					} while (true);
				}
			}
			if (!ketemu) {
				cout << "Nama kota salah karena tidak ditemukan" << endl;
			}
			system("cls");
		}
		else if (menu == 3) {
			// display kota
			for (int i = 0; i < max_kota; i++) {
				cout << titik_kota[i].getNama() << endl;
				cout << titik_kota[i].getX() << " " << titik_kota[i].getY() << endl << endl;
			}
			cout << endl;

			string nama_kotadelete;
			int x_kotadelete, y_kotadelete;
			cin.ignore();
			cout << "Nama Kota yang ingin di Delete = "; getline(cin, nama_kotadelete);

			bool ketemu = false;
			for (int i = 0; i < max_kota; i++) {
				if (titik_kota[i].getNama() == nama_kotadelete) {
					ketemu = true;
					Kota* temp = new Kota[max_kota];
					for (int i = 0; i < max_kota; i++) {
						temp[i] = titik_kota[i];
					}
					delete[] titik_kota;
					titik_kota = new Kota[max_kota - 1];
					for (int i = 0, j = 0; i < max_kota; i++) {
						if (temp[i].getNama() != nama_kotadelete) {
							titik_kota[j] = temp[i];
							j++;
						}
					}

					max_kota -= 1;
				}
			}
			if (!ketemu) {
				cout << "Nama kota salah karena tidak ditemukan" << endl;
			}
			system("cls");
		}
		else if (menu == 4) {
			cout << "Jumlah semut baru = "; cin >> jumlah_semut;
		}
		else if (menu == 5) {
			cout << "Batas loop baru = "; cin >> batas_loop;
		}
		else if (menu == 6) {
			cout << "Pangkat alpha baru = "; cin >> pangkat_alpha;
		}
		else if (menu == 7) {
			cout << "Pangkat beta baru = "; cin >> pangkat_beta;
		}
		else if (menu == 8) {
			cout << "Evaporate rate baru = "; cin >> evaporate_rate;
		}
		else if (menu == 9) {
			for (int i = 0; i < max_kota; i++) {
				cout << titik_kota[i].getNama() << endl;
				cout << titik_kota[i].getX() << " " << titik_kota[i].getY() << endl << endl;
			}
		}
		else if (menu == 10) {
			cout << "Jumlah semut = " << jumlah_semut << endl;
			cout << "Batas loop = " << batas_loop << endl;
			cout << "Pangkat alpha = " << pangkat_alpha << endl;
			cout << "Pangkat beta = " << pangkat_beta << endl;
			cout << "Evaporate rate = " << evaporate_rate << endl;
			cout << endl;
		}

		if (menu >= 1 && menu <= 8) {
			// SAVE CONFIG
			ofstream save("kota.txt");
			// save max_kota
			save << max_kota << endl;
			// save jumlah_semut
			save << jumlah_semut << endl;
			// save batas_loop
			save << batas_loop << endl;
			// save pangkat_alpha
			save << pangkat_alpha << endl;
			// save pangkat_beta
			save << pangkat_beta << endl;
			// save evaporate_rate
			save << evaporate_rate << endl;
			save << endl;
			// save kota
			for (int i = 0; i < max_kota; i++) {
				save << titik_kota[i].getNama() << endl;
				save << titik_kota[i].getX() << " " << titik_kota[i].getY() << endl;
				save << endl;
			}
			save.close();
		}
	} while (menu);

	// RUN PROGRAM
	int* besttour = new int[max_kota];	// jumlah array = [maxkota]
	float length_besttour = 0;
	float** pheromone = new float* [max_kota];	// jumlah array = [maxkota][maxkota]
	for (int i = 0; i < max_kota; i++) {
		pheromone[i] = new float[max_kota];
		for (int j = 0; j < max_kota; j++) {
			pheromone[i][j] = 0;
		}
	}

	// LOOP SAMPAI 500 KALI
	for (int maxloop = 0; maxloop < batas_loop; maxloop++) {
		// menempatkan n semut di titik tertentu
		// initialize 5 semut
		int** semut = new int* [jumlah_semut];	// jumlah array = [jumlah_semut][maxkota]
		for (int i = 0; i < jumlah_semut; i++) {
			semut[i] = new int[max_kota];
			for (int j = 0; j < max_kota; j++) {
				semut[i][j] = 0;
			}
		}
		float* length_semut = new float[jumlah_semut];	// jumlah array = [jumlah_semut]

		for (int i = 0; i < jumlah_semut; i++) {
			length_semut[i] = 0;
			int current = rand() % max_kota;
			int titik_awal_semut = current;

			// terus menjelajah kota sampai semua kota sudah di lewati
			int jelajah_kota = 1;
			semut[i][current] = jelajah_kota;
			while (jelajah_kota < max_kota) {
				// hitung total pheromone + distance setiap neighbour untuk memilih probabilitas
				float total_pheromonedistance_current_to_j = 0;
				for (int j = 0; j < max_kota; j++) {
					// selama bukan dirinya sendiri & belum pernah di lewati, maka
					if (j != current && semut[i][j] == 0) {
						// menentukan prioritas pheromone atau jarak
							// dapatkan pheromone
						float pheromone_current_to_j = pheromone[current][j];

						// hitung eucledian distance
						float eucledian_distance = 1 / (sqrt(pow((titik_kota[j].getX() - titik_kota[current].getX()), 2) + pow((titik_kota[j].getY() - titik_kota[current].getY()), 2)));

						// total dulu pembagi
						float pembagi = pow(pheromone_current_to_j, pangkat_alpha) * pow(eucledian_distance, pangkat_beta);
						total_pheromonedistance_current_to_j += pembagi;
					}
				}
				// random dengan probabilitas (metode roullete wheel)
				float roullete = (rand() % 100) * (rand() % 100);
				roullete /= 10000;
				float increment_pick_roullete = 0;
				int index_to_j = 0;
				for (int j = 0; j < max_kota; j++) {
					// selama bukan dirinya sendiri, maka
					if (j != current && semut[i][j] == 0) {
						// setidaknya harus ada 1 yang dipilih
						index_to_j = j;

						// menentukan prioritas pheromone atau jarak
							// dapatkan pheromone
						float pheromone_current_to_j = pheromone[current][j];

						// hitung eucledian distance
						float eucledian_distance = 1 / (sqrt(pow((titik_kota[j].getX() - titik_kota[current].getX()), 2) + pow((titik_kota[j].getY() - titik_kota[current].getY()), 2)));

						float p = (pow(pheromone_current_to_j, pangkat_alpha) * pow(eucledian_distance, pangkat_beta)) / total_pheromonedistance_current_to_j;

						if (increment_pick_roullete + p <= roullete) {
							increment_pick_roullete += p;
							index_to_j = j;
						}
						else {
							break;
						}
					}
				}

				// simpan jalur semut
				float eucledian_distance = sqrt(pow((titik_kota[index_to_j].getX() - titik_kota[current].getX()), 2) + pow((titik_kota[index_to_j].getY() - titik_kota[current].getY()), 2));
				semut[i][index_to_j] = jelajah_kota;

				// jumlah jalur semut
				length_semut[i] += eucledian_distance;

				// next ke kota berikutnya
				current = index_to_j;
				jelajah_kota++;
			}

			// semut kembali ke titik awal
				// tambah jalur semut
			float eucledian_distance = sqrt(pow((titik_kota[titik_awal_semut].getX() - titik_kota[current].getX()), 2) + pow((titik_kota[titik_awal_semut].getY() - titik_kota[current].getY()), 2));
			// jumlah jalur semut
			length_semut[i] += eucledian_distance;

			// jika sudah selesai dijelajahi semua
				// bandingkan dengan best tour
			if (length_besttour == 0 || length_besttour > length_semut[i]) {
				for (int j = 0; j < max_kota; j++) {
					besttour[j] = semut[i][j];
					length_besttour = length_semut[i];
				}
			}
		}

		// update pheromone
		for (int i = 0; i < max_kota; i++) {
			for (int j = 0; j < max_kota; j++) {
				if (i != j) {
					float pheromone_value = pheromone[i][j];
					float delta_pheromone_value = 0;
					for (int k = 0; k < jumlah_semut; k++) {
						if (abs(semut[k][i] - semut[k][j]) == 1) {
							delta_pheromone_value += 1 / (length_semut[k]);
						}
					}
					float new_pheromone = (evaporate_rate * pheromone_value) + (delta_pheromone_value);
					pheromone[i][j] = new_pheromone;
				}
			}
		}

		// Tampilkan best tour selama looping
		if (maxloop % 250 == 0) {
			cout << "Length Terbaik dari Loop ke-" << maxloop + 1 << " = " << length_besttour << endl;
		}
	}

	cout << endl << endl;
	// display hasil
	cout << "Length terbaik dari Loop ke-" << batas_loop << " = " << length_besttour << endl;
	int indexawal_besttour = 0;
	for (int i = 1; i <= max_kota; i++) {
		for (int j = 0; j < max_kota; j++) {
			if (besttour[j] == i) {
				if (i == 1) {
					indexawal_besttour = j;
				}
				cout << titik_kota[j].getNama() << " -> ";
				break;
			}
		}
	}
	cout << titik_kota[indexawal_besttour].getNama() << endl;
}