<?php
// Fungsi untuk menghitung jumlah parsial dari array
function partialSum($array) {
    $sum = 0;
    foreach ($array as $value) {
        $sum += $value;
    }
    return $sum;
}

// Fungsi untuk menjalankan PSPEC menggunakan pendekatan DPPL
function pspec_dppl($array, $num_threads) {
    $length = count($array);
    $chunk_size = ceil($length / $num_threads);
    $partial_sums = [];

    // Bagikan pekerjaan ke beberapa sub-array
    for ($i = 0; $i < $num_threads; $i++) {
        $start = $i * $chunk_size;
        $end = min($start + $chunk_size, $length);
        $sub_array = array_slice($array, $start, $end - $start);

        // Simpan hasil parsial
        $partial_sums[] = partialSum($sub_array);
    }

    // Gabungkan hasil parsial
    $total_sum = partialSum($partial_sums);

    return $total_sum;
}

// Contoh array
$array = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];

// Tentukan jumlah threads (atau proses paralel)
$num_threads = 4;  // Misalnya kita bagi ke 4 proses

// Jalankan algoritma PSPEC menggunakan DPPL
$result = pspec_dppl($array, $num_threads);

// Cetak hasil
echo "Total Sum: " . $result.PHP_EOL;
?>