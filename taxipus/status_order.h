#ifndef STATUS_ORDER_H
#define STATUS_ORDER_H

enum status_order
{
    New,
    Assigned,
    Accepted, //пассажира забрали
    Completed, //поездка завершена
    Canceled, //поездка отменена
    Failed //клиент пропал
};

#endif // STATUS_ORDER_H
