const { performance } = require('perf_hooks');


const insertionsort = (data) => {
    console.log("Insertion Sort")
    let array = data
    let i, j, aux, n = array.length;
    for (i = 1; i < n; i++) {
        j = i;
        while ((j != 0) && (array[j].cpf < array[j - 1].cpf)) {
            aux = array[j];
            array[j] = array[j - 1];
            array[j - 1] = aux;
            j--;
        }

    }
    return array;
}

const selectionsort = (data) => {
    console.log("Selection Sort")
    let array = data
    let i, min, aux;
    for (i = 0; i < array.length - 1; i++) {
        min = i;
        for (let j = i + 1; j < array.length; j++) {
            if (array[j].cpf < array[min].cpf)
                min = j
        }
        if (array[i].cpf != array[min].cpf) {
            aux = array[i];
            array[i] = array[min];
            array[min] = aux;
        }
    }
    return array;
}

const bubblesort = (data) => {
    console.log("Bubble Sort")
    let array = data
    let n = array.length;
    let swap = false
    do {
        swap = false
        for (let i = 0; i < n - 2; i++) {
            if (array[i].cpf > array[i + 1].cpf) {
                swap = true
                let aux = array[i]
                array[i] = array[i + 1]
                array[i + 1] = aux
            }
        }

    } while (swap === true);

    return array;
}

const timeoffunction = (fun, data, name) => {
    let vet
    let t0 = performance.now();
    vet = fun(data)
    let t1 = performance.now();
    console.log(`Time used by ${name} = ${t1 - t0} milliseconds`);
    return vet
}
module.exports = {
    insertionsort,
    selectionsort,
    bubblesort,
    timeoffunction
}