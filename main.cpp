#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <memory>

using namespace std;

// ==================== الأنظمة المتاحة ====================
enum class SystemType {
    EDUCATION,      // نظام التعليم
    FINANCE,        // النظام المالي  
    HEALTHCARE,     // النظام الصحي
    INVENTORY       // نظام المخزون
};

// ==================== العقل الاصطناعي المركزي ====================
class AICore {
private:
    SystemType current_system;
    
public:
    AICore(SystemType initial_system = SystemType::EDUCATION) {
        switch_system(initial_system);
    }

    void switch_system(SystemType new_system) {
        current_system = new_system;
        cout << "🔄 تم تبديل النظام إلى: " << get_system_name() << endl;
    }

    vector<double> analyze_data(const vector<double>& input_data) {
        vector<double> results;
        
        switch(current_system) {
            case SystemType::EDUCATION:
                results = analyze_education(input_data);
                break;
            case SystemType::FINANCE:
                results = analyze_finance(input_data);
                break;
            case SystemType::HEALTHCARE:
                results = analyze_healthcare(input_data);
                break;
            case SystemType::INVENTORY:
                results = analyze_inventory(input_data);
                break;
        }
        
        return results;
    }

    string get_system_name() const {
        switch(current_system) {
            case SystemType::EDUCATION: return "نظام التعليم";
            case SystemType::FINANCE: return "النظام المالي";
            case SystemType::HEALTHCARE: return "النظام الصحي";
            case SystemType::INVENTORY: return "نظام المخزون";
            default: return "غير محدد";
        }
    }

private:
    vector<double> analyze_education(const vector<double>& grades) {
        // تحليل البيانات التعليمية
        vector<double> predictions;
        if(!grades.empty()) {
            double avg = 0;
            for(double g : grades) avg += g;
            avg /= grades.size();
            
            predictions.push_back(avg);                    // المتوسط
            predictions.push_back(avg + 2.5);             // تحسن متوقع
            predictions.push_back(grades.back() + 1.8);   // تنبؤ بأداء المستقبل
        }
        return predictions;
    }

    vector<double> analyze_finance(const vector<double>& financial_data) {
        // تحليل البيانات المالية
        vector<double> analysis;
        if(!financial_data.empty()) {
            double total = 0;
            for(double d : financial_data) total += d;
            
            analysis.push_back(total);                    // الإجمالي
            analysis.push_back(total * 0.1);             // ضريبة 10%
            analysis.push_back(total * 1.15);            // نمو متوقع 15%
        }
        return analysis;
    }

    vector<double> analyze_healthcare(const vector<double>& health_metrics) {
        // تحليل البيانات الصحية
        vector<double> health_analysis;
        if(!health_metrics.empty()) {
            double sum = 0;
            for(double m : health_metrics) sum += m;
            
            health_analysis.push_back(sum / health_metrics.size());  // المتوسط
            health_analysis.push_back(health_metrics.back());        // آخر قياس
            health_analysis.push_back(health_metrics.back() * 0.95); // تحسن متوقع
        }
        return health_analysis;
    }

    vector<double> analyze_inventory(const vector<double>& stock_data) {
        // تحليل بيانات المخزون
        vector<double> inventory_analysis;
        if(!stock_data.empty()) {
            double min_val = stock_data[0], max_val = stock_data[0];
            for(double s : stock_data) {
                if(s < min_val) min_val = s;
                if(s > max_val) max_val = s;
            }
            
            inventory_analysis.push_back(min_val);    // الحد الأدنى
            inventory_analysis.push_back(max_val);    // الحد الأقصى
            inventory_analysis.push_back((min_val + max_val) / 2); // المتوسط
        }
        return inventory_analysis;
    }
};

// ==================== مدير النظام الرئيسي ====================
class SystemManager {
private:
    unique_ptr<AICore> ai_core;
    map<string, vector<double>> data_store;

public:
    SystemManager() {
        ai_core = make_unique<AICore>();
        cout << "🧠 النظام الذكي المتعدد المجالات جاهز" << endl;
    }

    void switch_system(SystemType new_system) {
        ai_core->switch_system(new_system);
    }

    void add_data(const string& key, const vector<double>& data) {
        data_store[key] = data;
        cout << "✅ تمت إضافة بيانات: " << key << endl;
    }

    void analyze_with_ai(const string& data_key) {
        if(data_store.find(data_key) == data_store.end()) {
            cout << "❌ البيانات غير موجودة: " << data_key << endl;
            return;
        }

        cout << "\n🔍 التحليل في " << ai_core->get_system_name() << ":" << endl;
        cout << "   البيانات: " << data_key << " -> ";
        
        auto data = data_store[data_key];
        for(double d : data) cout << d << " ";
        cout << endl;

        auto results = ai_core->analyze_data(data);
        
        cout << "   النتائج: ";
        for(double r : results) cout << r << " ";
        cout << endl;
    }

    void show_system_status() {
        cout << "\n📊 حالة النظام:" << endl;
        cout << "   • النظام النشط: " << ai_core->get_system_name() << endl;
        cout << "   • عدد مجموعات البيانات: " << data_store.size() << endl;
    }
};

// ==================== الدالة الرئيسية ====================
int main() {
    SystemManager manager;

    // إضافة بيانات مختلفة
    manager.add_data("طالب_أحمد", {85, 88, 90, 92});
    manager.add_data("ميزانية_شركة", {50000, 55000, 60000, 65000});
    manager.add_data("مريض_سعيد", {120, 118, 116, 115});
    manager.add_data("مخزون_منتج", {100, 85, 120, 95});

    // اختبار النظام التعليمي
    manager.switch_system(SystemType::EDUCATION);
    manager.analyze_with_ai("طالب_أحمد");

    // اختبار النظام المالي
    manager.switch_system(SystemType::FINANCE);
    manager.analyze_with_ai("ميزانية_شركة");

    // اختبار النظام الصحي
    manager.switch_system(SystemType::HEALTHCARE);
    manager.analyze_with_ai("مريض_سعيد");

    // اختبار نظام المخزون
    manager.switch_system(SystemType::INVENTORY);
    manager.analyze_with_ai("مخزون_منتج");

    manager.show_system_status();

    return 0;
}
