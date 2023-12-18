The MultiSNICS is an ion source for a particle accelerator. It has several very high voltage
power supplies, a high vacuum chamber, several types of pumps, and is designed to work with
tritium embedded cathodes. Tritium is a radioactive isotope of hydrogen that poses a significant
health risk if ingested, inhaled, or absorbed into the body. To operate the Multi-SNICS safely,
a comprehensive safety plan is required. Part of the plan is an Interlock System that acts as
a fail-safe mechanism, actively monitoring key parameters such as closure of the cage doors
surrounding the source, leaking tritium detection, vacuum pressure, building power, coolant
flow, and smoke detection. In the event of deviations from safe operating conditions, the
Interlock System initiates automatic shutdown procedures, preventing potential harm to personnel,
the environment, and the equipment itself.

The Interlock System is based on a P1AM ProductivityOpen PLC controller. It has industrial grade
ratings to endure harsh environments. There are a lot of options for modules that snap together
and communicate on a Modbus. The expandability of this platform makes it a good choice for
this application because it can evolve to meet new needs in the future.

interlock Folder:
  This folder contains the c++ code with file extension ".ino" for use with the Arduino IDE for
  uploading to the P1AM-100 controller.

Resources Folder:
  This folder conatins a photo of the front panel of the interlock assembly, the user manual, and
  a template webpage which was used eventually used in the interlock code to display system status
  to a web interface.
