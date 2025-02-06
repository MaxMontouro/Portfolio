{/* Importer les composants nécessaires */}
import React, { useState } from 'react';
import { Shield, Terminal, Cpu, Network, Lock, Code, Mail, Github, Linkedin, ChevronDown, ExternalLink, AlertTriangle, Bug, Shield as ShieldIcon, Target, User, Briefcase, GraduationCap, Award } from 'lucide-react';

// ... (reste du code inchangé jusqu'à la section contact)

{/* Section Contact */}
function App() {
  // ... (code précédent inchangé)

  // État du formulaire
  const [formData, setFormData] = useState({
    name: '',
    email: '',
    message: ''
  });
  const [errors, setErrors] = useState({
    name: '',
    email: '',
    message: ''
  });
  const [isSubmitting, setIsSubmitting] = useState(false);
  const [submitStatus, setSubmitStatus] = useState<'idle' | 'success' | 'error'>('idle');

  // Validation des champs
  const validateField = (name: string, value: string) => {
    switch (name) {
      case 'name':
        if (value.length < 2) return 'Le nom doit contenir au moins 2 caractères';
        if (value.length > 50) return 'Le nom ne doit pas dépasser 50 caractères';
        if (!/^[a-zA-ZÀ-ÿ\s-]+$/.test(value)) return 'Le nom contient des caractères non autorisés';
        return '';
      case 'email':
        if (!value) return 'L\'email est requis';
        if (!/^[^\s@]+@[^\s@]+\.[^\s@]+$/.test(value)) return 'Format d\'email invalide';
        return '';
      case 'message':
        if (value.length < 10) return 'Le message doit contenir au moins 10 caractères';
        if (value.length > 1000) return 'Le message ne doit pas dépasser 1000 caractères';
        return '';
      default:
        return '';
    }
  };

  // Gestion des changements dans les champs
  const handleChange = (e: React.ChangeEvent<HTMLInputElement | HTMLTextAreaElement>) => {
    const { name, value } = e.target;
    
    // Prévention XSS basique
    const sanitizedValue = value.replace(/[<>]/g, '');
    
    setFormData(prev => ({
      ...prev,
      [name]: sanitizedValue
    }));
    
    setErrors(prev => ({
      ...prev,
      [name]: validateField(name, sanitizedValue)
    }));
  };

  // Soumission du formulaire
  const handleSubmit = async (e: React.FormEvent) => {
    e.preventDefault();
    setIsSubmitting(true);
    setSubmitStatus('idle');

    // Validation de tous les champs
    const newErrors = {
      name: validateField('name', formData.name),
      email: validateField('email', formData.email),
      message: validateField('message', formData.message)
    };

    setErrors(newErrors);

    // Vérification des erreurs
    if (Object.values(newErrors).some(error => error !== '')) {
      setIsSubmitting(false);
      return;
    }

    try {
      // Simulation d'envoi sécurisé (à remplacer par votre logique d'envoi réelle)
      await new Promise(resolve => setTimeout(resolve, 1000));
      
      setSubmitStatus('success');
      setFormData({ name: '', email: '', message: '' });
    } catch (error) {
      setSubmitStatus('error');
    } finally {
      setIsSubmitting(false);
    }
  };

  // ... (reste du code inchangé jusqu'à la section contact)

  return (
    <div className="min-h-screen bg-gray-900 text-gray-100">
      {/* ... (sections précédentes inchangées) */}

      {/* Section Contact */}
      <section id="contact" className="py-20 bg-gray-900">
        <div className="container mx-auto px-4">
          <h2 className="text-3xl font-bold mb-12 text-center flex items-center justify-center gap-2">
            <Terminal className="w-8 h-8 text-green-500" />
            Initier un Contact Sécurisé
          </h2>
          <div className="max-w-xl mx-auto">
            <form onSubmit={handleSubmit} className="space-y-6">
              <div className="bg-gray-800 p-6 rounded-lg border border-green-500/20">
                <label htmlFor="name" className="block text-sm font-medium text-gray-300 mb-1">
                  Nom_Complet *
                </label>
                <input
                  type="text"
                  id="name"
                  name="name"
                  value={formData.name}
                  onChange={handleChange}
                  maxLength={50}
                  required
                  className={`w-full px-4 py-2 bg-gray-900 border ${errors.name ? 'border-red-500' : 'border-green-500/20'} rounded-lg focus:ring-2 focus:ring-green-500 focus:border-transparent text-gray-100`}
                />
                {errors.name && (
                  <p className="mt-1 text-sm text-red-500">{errors.name}</p>
                )}
              </div>

              <div className="bg-gray-800 p-6 rounded-lg border border-green-500/20">
                <label htmlFor="email" className="block text-sm font-medium text-gray-300 mb-1">
                  Email_Sécurisé *
                </label>
                <input
                  type="email"
                  id="email"
                  name="email"
                  value={formData.email}
                  onChange={handleChange}
                  required
                  className={`w-full px-4 py-2 bg-gray-900 border ${errors.email ? 'border-red-500' : 'border-green-500/20'} rounded-lg focus:ring-2 focus:ring-green-500 focus:border-transparent text-gray-100`}
                />
                {errors.email && (
                  <p className="mt-1 text-sm text-red-500">{errors.email}</p>
                )}
              </div>

              <div className="bg-gray-800 p-6 rounded-lg border border-green-500/20">
                <label htmlFor="message" className="block text-sm font-medium text-gray-300 mb-1">
                  Message_Chiffré *
                </label>
                <textarea
                  id="message"
                  name="message"
                  value={formData.message}
                  onChange={handleChange}
                  rows={4}
                  maxLength={1000}
                  required
                  className={`w-full px-4 py-2 bg-gray-900 border ${errors.message ? 'border-red-500' : 'border-green-500/20'} rounded-lg focus:ring-2 focus:ring-green-500 focus:border-transparent text-gray-100`}
                ></textarea>
                {errors.message && (
                  <p className="mt-1 text-sm text-red-500">{errors.message}</p>
                )}
                <p className="mt-1 text-sm text-gray-400">
                  {formData.message.length}/1000 caractères
                </p>
              </div>

              <button
                type="submit"
                disabled={isSubmitting || Object.values(errors).some(error => error !== '')}
                className={`w-full ${isSubmitting ? 'bg-gray-600' : 'bg-green-600 hover:bg-green-700'} text-white px-6 py-3 rounded-lg transition flex items-center justify-center gap-2 disabled:cursor-not-allowed`}
              >
                <Lock className="w-5 h-5" />
                {isSubmitting ? 'Envoi en cours...' : 'Envoyer Message Sécurisé'}
              </button>

              {submitStatus === 'success' && (
                <div className="p-4 bg-green-500/20 border border-green-500 rounded-lg text-green-400">
                  Message envoyé avec succès !
                </div>
              )}

              {submitStatus === 'error' && (
                <div className="p-4 bg-red-500/20 border border-red-500 rounded-lg text-red-400">
                  Une erreur est survenue. Veuillez réessayer.
                </div>
              )}
            </form>
          </div>
        </div>
      </section>

      {/* ... (reste du code inchangé) */}
    </div>
  );
}

export default App;