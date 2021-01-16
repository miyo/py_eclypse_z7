#include "zmoddac1411.h"
#include <pybind11/pybind11.h>

namespace py = pybind11;

PYBIND11_MODULE(zmoddac1411, p)
{
    py::class_<ZMODDAC1411>(p, "ZMODDAC1411")
        .def(py::init<unsigned int, unsigned int, unsigned int, unsigned int, int>())
        //.def_property(variable, setter, getter)
        .def("alloc_channels_buffer", &ZMODDAC1411::allocChannelsBuffer)
        .def("free_channels_buffer", &ZMODDAC1411::freeChannelsBuffer)
        .def("arrange_channel_data", &ZMODDAC1411::arrangeChannelData)
        .def("arrange_signed_channel_data", &ZMODDAC1411::arrangeSignedChannelData)
        .def("reset_output_counter", &ZMODDAC1411::resetOutputCounter)
        .def("set_data", &ZMODDAC1411::setData)
        .def("start", &ZMODDAC1411::start)
        .def("stop", &ZMODDAC1411::stop)
        .def("set_output_sample_frequency_divider", &ZMODDAC1411::setOutputSampleFrequencyDivider)
        .def("process_interrupt", &ZMODDAC1411::processInterrupt)
        .def("read_user_calib", &ZMODDAC1411::readUserCalib)
        .def("set_gain", &ZMODDAC1411::setGain)
        .def("compute_coef_mult", &ZMODDAC1411::computeCoefMult)
        .def("compute_coef_add", &ZMODDAC1411::computeCoefAdd)
        .def("get_signed_raw_from_volt", &ZMODDAC1411::getSignedRawFromVolt)
        .def("put_data", &ZMODDAC1411::putData)
        .def("__repr__", [](const ZMODDAC1411 &p) {
                             return "ZMODDAC1411('" + std::to_string(0.1) + ")";
                         });
}
