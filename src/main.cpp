#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <polylla.hpp>
#include <triangulation.hpp>

namespace py = pybind11;

PYBIND11_MODULE(Polylla, m) {
    m.doc() = "Polylla: Polygonal meshing algorithm based on terminal-edge "
            "regions"; // optional module docstring

    py::class_<Vertex>(m, "Vertex")
    .def(py::init<>())
    .def_readwrite("x", &Vertex::x)
    .def_readwrite("y", &Vertex::y)
    .def_readwrite("is_border", &Vertex::is_border)
    .def_readwrite("incident_halfedge", &Vertex::incident_halfedge);

    py::class_<Polygon>(m, "Polygon")
    .def(py::init<>())
    .def_readwrite("vertices", &Polygon::vertices)
    .def("__str__", [](const Polygon &p) {
        std::stringstream ss;
        std::string sep = "";
        ss << "Polygon: [";
        for(auto v : p.vertices) {
            ss << sep << v;
            sep = ", ";
        }
        ss << "]";
        return ss.str();
    });

    py::class_<Triangulation>(m, "Triangulation").def(py::init<std::vector<Vertex> &, std::vector<int>>());


    py::class_<Polylla>(m, "Polylla")
    .def(py::init<const Triangulation &>())
    .def("construct_polylla", &Polylla::construct_polylla)
    .def("get_polygonal_mesh", &Polylla::get_polygonal_mesh);
}
