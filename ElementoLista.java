package listaInvertida;

public class ElementoLista implements Comparable<ElementoLista> {

    private int id;
    private float frequencia;

    public ElementoLista(int id, float frequencia) {
        this.id = id;
        this.frequencia = frequencia;
    }

    public int getId() {
        return id;
    }

    public float getFrequencia() {
        return frequencia;
    }

    public ElementoLista clone() {
        return new ElementoLista(id, frequencia);
    }

    @Override
    public String toString() {
        return "ID: " + id + ", Freq: " + frequencia;
    }

    @Override
    public int compareTo(ElementoLista o) {
        return Float.compare(o.frequencia, this.frequencia); // Descending order
    }
}