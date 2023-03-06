# HTAB

## Getting Started

htab here and pair are basic struct constructors

You have usually one htab and several pairs
Why? Because in the htab you have a list of pointer
Each pointer points to a struct pair
That is a sentinel
The sentinel points to the next element and the next element points to the next element
We have this schema :

```
htab->data :    - *sentinel1   ->    el1   ->   el2   ->   NULL
                - *sentinel2   ->    el1'  ->   NULL
                - *sentinel3   ->    NULL
                - *sentinel4   ->    el1'' ->   el2'' ->   el3'' ->   NULL
```