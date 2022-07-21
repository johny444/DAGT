import { NgModule } from '@angular/core';
import { RouterModule, Routes } from '@angular/router';
import { ViewComponent } from './component/category/view/view.component';
import { LoginComponent } from './component/login/login.component';
import { RegisterComponent } from './component/register/register.component';
import { ResetpasswordComponent } from './component/resetpassword/resetpassword.component';
import { WelcomeComponent } from './component/welcome/welcome.component';

const routes: Routes = [
  {path:'', redirectTo:'welcome', pathMatch:'full'},
  {path:'category', component: ViewComponent},
  {path:'article', component: ViewComponent},
  {
    path:"welcome",component:WelcomeComponent
  },
  {
    path:'register',component:RegisterComponent
  },
  {
    path:'login',component:LoginComponent
  },
  {
    path:'reset',component:ResetpasswordComponent
  }
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
