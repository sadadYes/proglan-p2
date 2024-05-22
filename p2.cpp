#include <iostream>

class car{
    public:
    int kecepatan = 10;
    int bensin = 100;
    int bensin_max = 100;
    int penumpang = 4;
    
    virtual void jalan()
    {
        bensin -= kecepatan;
        std::cout << "Mobil ini berjalan sejauh " << kecepatan << "km/jam" << std::endl;
    };
};

class superCar : public car{
    public:
    
    superCar(){
        kecepatan = 100;
        bensin = 1000;
        bensin_max = 1000;
    }
    
};

class pickup : public car{
    public:
    int kapasitas = 1;
    int berat_barang{};
    int kapasitas_max = 100;
    
    pickup()
    {
        kecepatan = 20;
        bensin = 200;
    }
    
    void angkut(int berat_barang)
    {
        if(berat_barang <= kapasitas_max)
        {
            kapasitas += berat_barang;
            std::cout << "kapasitas barang = " << kapasitas << std::endl;
        }
        
    };
    
    void jalan() override{
        kecepatan = kecepatan / kapasitas;
        bensin = bensin - (berat_barang + kecepatan); 
        
        std::cout << "mobil ini berjalan sejauh " << kecepatan << "km/jam dengan kapasitas terpakai " << kapasitas << "kg" << std::endl;
    };
};

int main()
{
    car mobil;
    mobil.jalan();
    
    superCar mobil3;
    mobil3.jalan();
    
    pickup mobil2;
    mobil2.angkut(2);
    mobil2.jalan();
    
    return 0;
}

