function linearSearch(arr, x) {
    for (let i = 0; i < arr.length; i++) {
        if (arr[i] === x) return i;
    }
    return -1;
}

function binarySearch(arr, x) {
    let l = 0, r = arr.length - 1;
    while (l <= r) {
        let m = l + Math.floor((r - l) / 2);
        if (arr[m] === x) return m;
        if (arr[m] < x) l = m + 1;
        else r = m - 1;
    }
    return -1;
}

module.exports = { linearSearch, binarySearch };
