
#include "RogueStatistics.h"

RogueStatistics::RogueStatistics(SimSettings *settings, QObject *parent) :
    ClassStatistics(settings, parent)
{

}

int RogueStatistics::getNumStatisticsRows() const {
    int data = spell_statistics.empty() ? 0 : 1;
    data += buff_statistics.empty() ? 0 : 1;
    data += resource_statistics.empty() ? 0 : 1;
    data += proc_statistics.empty() ? 0 : 1;
    return data;
}

QVariantList RogueStatistics::getTableInfo(const int index) const {
    QVariantList table_info;

    switch (index) {
    case 0:
        table_info.append(get_damage_breakdown_table());
        break;
    case 1:
        table_info.append(get_buff_uptime_table());
        break;
    case 2:
        table_info.append(get_resource_gain_table());
        break;
    case 3:
        table_info.append(get_proc_table());
        break;
    }

    return table_info;
}

QVariantList RogueStatistics::getChartInfo(const int index) const {
    QVariantList chart_info;


    switch (index) {
    case 0:
        chart_info.append(get_damage_breakdown_chart());
        break;
    }

    return chart_info;
}

QString RogueStatistics::getEntryIcon(const int) const {
    return "";
}