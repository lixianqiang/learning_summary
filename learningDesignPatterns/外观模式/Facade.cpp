#include <string>
#include <map>
using std::string;
/***************************************************************************************************
 * 外观(Facade)模式:又叫作门面模式,属于对象结构型模式,该模式也是迪米特法则又一重要体现
 * 
 * 关于模式的直观体现:
 *      以前到政府机关进行业务办理的时候,比如饭店的经营申请.申请人(客户端)往往需要走访多个部门:
 *              办理营业执照(工商),卫生许可证(防疫),税务登记证(地税),对从业人员还要有健康证(防疫)等等
 *              由各部门领导审批签字合格方能成功办理,审批流程繁琐,审核需时.
 *      缺点:过程中申请人需要与各部门直接接触.(客户端与众多对象之间产生了依赖关系)
 * 
 *      现在政府提供了便民服务,申请人(客户端)只需要准备好所需要的材料,文件,复印件,到办事大厅提交申请即可,
 *              业务审批过程由相关政府人员负责走访协调,办理成功后再通知申请人前往指定地点领取营业执照.
 *      优点:整个过程中,申请人没有与任何部门打交道.仅与柜台人员接触(客户端的依赖对象减少到只有一个)
 * 
 * 在软件复用上:外观模式的实际作用跟适配器模式有点类似.都是为了给用户(客户端)
 *                              提供一类简化的接口(适配器则是提供用户指定的接口)去访问实际的接口.
 *                              使得用户不需要关心这些实际接口之间究竟是如何调用的.也不需要关心
 *                              这些实际接口它的具体函数实现以及彼此之间的依赖关系
 * 
 * 核心思想:
 *      对于复杂系统来说,一个功能的实现,需要系统的各个模块协同工作((子系统之间相互调用)
 *      而通过外观类对象将这些调用行为封装成一些列函数接口,来解耦用户(客户端)与各子系统的依赖关系
 * 
 *设计目的:
 *      通过外观类来提供一系列接口,为用户(客户端)解决各个子系统之间(多个对象之间)的调用以及依赖关系,
 *      因此,对于子系统(对象)的功能扩展.不应该通过外观类来实现,而是应该交还给子系统(功能扩展应该在对象内部自身进行)
 *      即:子系统(对象)的功能增加应该通过修改原有子系统类(对象类)或增加新的子系统类(新的对象类)来实现
 * 
 * 模式扩展:可以为外观类引入一个抽象外观类,这样就能避免外观类的修改直接影响到客户端
 *                   
 * 参考资料:https://design-patterns.readthedocs.io/zh_CN/latest/structural_patterns/facade.html
 *                    https://www.runoob.com/design-pattern/facade-pattern.html
 ***************************************************************************************************/
class IGovernment
{
        protected:
                std::multimap<string, std::map<string, bool>> applicants_;
        public:
                virtual bool registration(string name, string business, string doc) = 0;
                virtual string GetLicense(string name) = 0;
};

class BusinessSector: public IGovernment
{
        public:
                virtual bool registration(string name, string business, string doc){
                        bool result = false;
                        if(business=="工商营业执照" && doc=="身份证"){
                                result = true;
                        }
                        if(business=="业务代码BS02" && doc=="......"){
                            //.............略
                        }
                        std::map<string, bool> BsNum;
                        BsNum.insert({business, result});
                        applicants_.insert({name, BsNum});
                        return result;
                }
                virtual string GetLicense(string name){
                        std::map<string, bool> BsNum = applicants_.find(name)->second;
                        auto Bs01 = BsNum.find("工商营业执照");
                        if(Bs01 != BsNum.end()){
                                bool result = Bs01->second;
                                if(result == true){
                                        return "营业执照许可证";
                                }
                        }
                        auto Bs02 = BsNum.find("业务代码BS02");
                        if(Bs02 != BsNum.end()){
                                bool result = Bs02->second;
                                if(result == true){
                                        return "xxxxx许可证";
                                }                           
                        }
                        return "";
                }
};

class FireDepartment: public IGovernment
{
        public:
                virtual bool registration(string name, string business, string doc){
                        bool result = false;
                        if(business=="消防安全检查" && doc==""){
                                result = true;
                        }
                        if(business=="业务代码FD02" && doc=="......"){
                            //.............略
                        }
                        std::map<string, bool> FdNum;
                        FdNum.insert({business, result});
                        applicants_.insert({name, FdNum});
                        return result;
                }
                virtual string GetLicense(string name){
                        std::map<string, bool> FdNum = applicants_.find(name)->second;
                        auto Fd01 = FdNum.find("消防安全检查");
                        if(Fd01 != FdNum.end()){
                                bool result = Fd01->second;
                                if(result == true){
                                        return "消防安全合格证";
                                }
                        }
                        auto Fd02 = FdNum.find("业务代码FD02");
                        if(Fd02 != FdNum.end()){
                                bool result = Fd02->second;
                                if(result == true){
                                        return "xxxxx许可证";
                                }                           
                        }
                        return "";
                }
};

class HealthAuthority: public IGovernment
{
        public:
                virtual bool registration(string name, string business, string doc){
                        bool result = false;
                        if(business=="卫生许可" && doc=="健康证"){
                                result = true;
                        }
                        if(business=="业务代码HA02" && doc=="......"){
                            //.............略
                        }
                        std::map<string, bool> HaNum;
                        HaNum.insert({business, result});
                        applicants_.insert({name, HaNum});
                        return result;
                }
                virtual string GetLicense(string name){
                        std::map<string, bool> HaNum = applicants_.find(name)->second;
                        auto Ha01 = HaNum.find("消防安全检查");
                        if(Ha01 != HaNum.end()){
                                bool result = Ha01->second;
                                if(result == true){
                                        return "消防安全合格证";
                                }
                        }
                        auto Ha02 = HaNum.find("业务代码HA02");
                        if(Ha02 != HaNum.end()){
                                bool result = Ha02->second;
                                if(result == true){
                                        return "xxxxx许可证";
                                }                           
                        }
                        return "";
                }
};

class SanitationDepartment: public IGovernment
{
        public:
                virtual bool registration(string name, string business, string doc){
                        bool result = false;
                        if(business=="排污许可" && doc==""){
                                result = true;
                        }
                        if(business=="业务代码SD02" && doc=="......"){
                            //.............略
                        }
                        std::map<string, bool> SdNum;
                        SdNum.insert({business, result});
                        applicants_.insert({name, SdNum});
                        return result;
                }
                virtual string GetLicense(string name){
                        std::map<string, bool> SdNum = applicants_.find(name)->second;
                        auto Sd01 = SdNum.find("排污许可");
                        if(Sd01 != SdNum.end()){
                                bool result = Sd01->second;
                                if(result == true){
                                        return "排污许可证";
                                }
                        }
                        auto Sd02 = SdNum.find("业务代码SD02");
                        if(Sd02 != SdNum.end()){
                                bool result = Sd02->second;
                                if(result == true){
                                        return "xxxxx许可证";
                                }                           
                        }
                        return "";
                }
};

class TaxBureau: public IGovernment
{
        public:
                virtual bool registration(string name, string business, string doc){
                        bool result = false;
                        if(business=="税务登记" && doc=="营业执照许可证"){
                                result = true;
                        }
                        if(business=="业务代码TB02" && doc=="......"){
                            //.............略
                        }
                        std::map<string, bool> TbNum;
                        TbNum.insert({business, result});
                        applicants_.insert({name, TbNum});
                        return result;
                }
                virtual string GetLicense(string name){
                        std::map<string, bool> TbNum = applicants_.find(name)->second;
                        auto Tb01 = TbNum.find("税务登记");
                        if(Tb01 != TbNum.end()){
                                bool result = Tb01->second;
                                if(result == true){
                                        return "税务登记证";
                                }
                        }
                        auto Tb02 = TbNum.find("业务代码TD02");
                        if(Tb02 != TbNum.end()){
                                bool result = Tb02->second;
                                if(result == true){
                                        return "xxxxx许可证";
                                }                           
                        }
                        return "";
                }
};

class BusinessLobby
{
        private:
                IGovernment* businessSector;
                IGovernment* sanitationDepartment;
                IGovernment* fireDepartment;
                IGovernment* healthAuthority;
                IGovernment* taxBureau;
        public:
                BusinessLobby(){
                        businessSector = new BusinessSector();
                        sanitationDepartment = new SanitationDepartment();
                        fireDepartment = new FireDepartment();
                        healthAuthority = new HealthAuthority();
                        taxBureau = new TaxBureau();
                }

                bool Apply4BusinessLicense(string name, string idCard, string healthCertificate){
                        if(idCard=="" || healthCertificate==""){
                                printf("对不起, 您的材料不足,不满足申请要求\n");
                                return false;
                        }
                        else{
                                printf("你的材料初步审批通过,部门审批结果将于七个工作日,以短信形式通知您\n");
                                if(!sanitationDepartment->registration(name, "排污许可", "")){
                                        printf("短信消息:不好意思%s,您的排污许可证未能申请通过\n", name.c_str());
                                        return false;
                                }
                                if(!healthAuthority->registration(name, "卫生许可", healthCertificate)){
                                        printf("短信消息:不好意思%s,您的卫生许可证未能申请通过\n", name.c_str());
                                        return false;
                                }
                                if(!fireDepartment->registration(name, "消防安全检查", "")){
                                        printf("短信消息:不好意思%s,您的消防安全合格证未能申请通过\n", name.c_str());
                                        return false;
                                }
                                if(!businessSector->registration(name, "工商营业执照", idCard)){
                                        printf("短信消息:不好意思%s,您的营业执照许可证未能申请通过\n", name.c_str());
                                        return false;
                                }
                                string license = businessSector->GetLicense(name);
                                if(!taxBureau->registration(name, "税务登记", license)){
                                        printf("短信消息:不好意思%s,您的地税税务登记号未能申请通过\n", name.c_str());
                                        return false;
                                }                  
                                printf("恭喜%s, 您的xx饭店的经营牌照审批已经通过,请于15个工作日内到服务大厅领取相关证件\n", name.c_str());
                                return true;
                        }
                }
                bool Apply4PublicHouse(string name, string idCard){
                    //.....................略
                }
                bool Apply4Passport(string name, string idCard, int photo){
                    //..................略
                }
};

int main(){
        BusinessLobby* bl = new BusinessLobby();
        bl->Apply4BusinessLicense("lxq", "身份证", "健康证");
        return 0;
}