#include "zmoddac1411.h"
#include "zmodadc1410.h"
#include <pybind11/pybind11.h>

namespace py = pybind11;

PYBIND11_MODULE(pyzmodlib, p)
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
    py::class_<ZMODADC1410>(p, "ZMODADC1410")
        .def(py::init<unsigned int, unsigned int, unsigned int, unsigned int, int, int>())
        //.def_property(variable, setter, getter)
        .def("alloc_channels_buffer", &ZMODADC1410::allocChannelsBuffer)
        .def("free_channels_buffer", &ZMODADC1410::freeChannelsBuffer)
        .def("channel_data", &ZMODADC1410::channelData)
        .def("signed_channel_data", &ZMODADC1410::signedChannelData)
        .def("set_transfer_length", &ZMODADC1410::setTransferLength)
        .def("set_trigger", &ZMODADC1410::setTrigger)
        .def("enable_buffer_full_interrupt", &ZMODADC1410::enableBufferFullInterrupt)
        .def("is_buffer_full", &ZMODADC1410::isBufferFull)
        .def("wait_for_buffer_full_polling", &ZMODADC1410::waitForBufferFullPolling)
        .def("start", &ZMODADC1410::start)
        .def("stop", &ZMODADC1410::stop)
        .def("acquire_triggered_polling", &ZMODADC1410::acquireTriggeredPolling)
        .def("acquire_immediate_polling", &ZMODADC1410::acquireImmediatePolling)
	.def("auto_test_ramp", &ZMODADC1410::autoTestRamp)
	.def("process_interrupt", &ZMODADC1410::processInterrupt)
	.def("set_gain", &ZMODADC1410::setGain)
	.def("set_coupling", &ZMODADC1410::setCoupling)
	.def("compute_coef_mult", &ZMODADC1410::computeCoefMult)
	.def("compute_coef_add", &ZMODADC1410::computeCoefAdd)
	.def("read_user_calib", &ZMODADC1410::readUserCalib)
	.def("set_calib_values", &ZMODADC1410::setCalibValues)
	.def("get_volt_from_signed_raw", &ZMODADC1410::getVoltFromSignedRaw)
	.def("get_data", &ZMODADC1410::getData)
        .def("__repr__", [](const ZMODADC1410 &p) {
                             return "ZMODADC1410('" + std::to_string(0.1) + ")";
                         });
}
