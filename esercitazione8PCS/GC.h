#ifndef GC_H
#define GC_H

#include <iostream>
#include <Eigen/Eigen>

// Funzione Gradiente Coniugato
inline Eigen::VectorXd coniugato_gradiente(const Eigen::MatrixXd& A, const Eigen::VectorXd& b, double res_tol, unsigned int k_max, unsigned int& k) {
    unsigned int n = A.rows();
    Eigen::VectorXd x = Eigen::VectorXd::Zero(n);
    Eigen::VectorXd res = b - A * x; 
    Eigen::VectorXd p = res; // Inizializzazione direzione p_0 = r_0
    
    k = 0; //contaore iter
    double res_norm_0 = res.norm();
    std::cout.precision(2);

    while (k < k_max && res.norm() > res_tol * res_norm_0) {
        // Calcolo separato dei .value() per evitare l'errore di compilazione di Eigen
        double num_alpha = (p.transpose() * res).value();
        double den_alpha = (p.transpose() * A * p).value();
        const double alpha_k = num_alpha / den_alpha; 

        std::cout.precision(2); 
        std::cout << std::scientific << "iter: " << k << " ,alpha: " << alpha_k << std::endl; //std::scientific uso per visualizzare con la notazione scientific
        x = x + alpha_k * p;
        
        Eigen::VectorXd res_next = b - A * x;
        
        double num_beta = (p.transpose() * (A * res_next)).value();
        const double beta_k = num_beta / den_alpha;
        
        p = res_next - beta_k * p;
        res = res_next;
        
        k++;
    } //uso sempre precision per quante cifre voglio

    return x;
}

#endif // GC_H