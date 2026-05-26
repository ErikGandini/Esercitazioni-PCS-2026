#include <iostream>
#include <iomanip> // Aggiunto per avere funzionamento delle opzioni di precisione di std::cout
#include <Eigen/Eigen>
#include "GC.h"


int main(int argc, char **argv)
{
    const double tol = 1.0e-15;
    unsigned int n = 3;
    Eigen::MatrixXd B = Eigen::MatrixXd::Random(n, n);

    if (std::abs(B.determinant()) < tol) // Usato std::abs per i numeri in virgola mobile (double)
        return -1;
    
    Eigen::MatrixXd A = B.transpose() * B;
    Eigen::VectorXd x_es = Eigen::VectorXd::Ones(n);
    Eigen::VectorXd b = A * x_es;
    
    const unsigned int k_max = 100; //numero di iterazione max
    unsigned int k = 0;             // Verrà aggiornato dalla funzione
    const double res_tol = 1.0e-12; //tolleranza sulla soluzione 
    double res_norm_0 = b.norm();   // Poiché x_0 = 0, il res_norm_0 iniziale è pari a b.norm()

    // Chiamata alla funzione del Gradiente Coniugato
    Eigen::VectorXd x = coniugato_gradiente(A, b, res_tol, k_max, k);
    
    // Calcolo del residuo finale e dell'errore relativo per la stampa
    Eigen::VectorXd res = b - A * x;
    const auto err_rel = (x_es.norm() == 0.0) ? (x - x_es).norm() : (x - x_es).norm() / x_es.norm();
    
    // Stampe finali
    std::cout.precision(4);
    std::cout << std::scientific << "iter:" << "/" << "k_max" << std::endl;
    std::cout << std::scientific << k << "/" << k_max << std::endl;
    std::cout << std::scientific << "res: " << "/" << "res_tol" << std::endl;
    std::cout << std::scientific << res.norm() / res_norm_0 << " / " << res_tol << std::endl;
    std::cout << std::scientific << "err_rel" << std::endl;
    std::cout << std::scientific << err_rel << std::endl;
    
    return 0;
}