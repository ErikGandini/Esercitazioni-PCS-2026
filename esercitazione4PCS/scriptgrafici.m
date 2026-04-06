%dimensione del vettore
% Dati estratti dalla tua tabella
N = [4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192];

% Tempi in secondi
bubble = [1e-6, 1e-6, 3e-6, 11e-6, 42e-6, 154e-6, 732e-6, 0.002335, 0.008512, 0.021597, 0.056843, 0.217786];
selection = [1e-6, 1e-6, 3e-6, 8e-6, 27e-6, 117e-6, 356e-6, 0.001083, 0.003184, 0.007520, 0.020474, 0.080950];
insertion = [0, 1e-6, 1e-6, 4e-6, 12e-6, 46e-6, 167e-6, 0.000622, 0.001767, 0.003803, 0.011539, 0.045814];
std_sort = [2e-6, 1e-6, 2e-6, 6e-6, 14e-6, 30e-6, 86e-6, 0.000143, 0.000227, 0.000314, 0.000502, 0.001064];

figure(1);
plot(N, bubble, '-o', 'LineWidth', 2); hold on;
plot(N, selection, '-s', 'LineWidth', 2);
plot(N, insertion, '-d', 'LineWidth', 2);
plot(N, std_sort, '-x', 'LineWidth', 2);
grid on;
xlabel('Dimensione Vettore (N)');
ylabel('Tempo (secondi)');
title('Confronto Algoritmi di Ordinamento (Scala Lineare)');
legend('Bubble Sort', 'Selection Sort', 'Insertion Sort', 'std::sort', 'Location', 'northwest');

